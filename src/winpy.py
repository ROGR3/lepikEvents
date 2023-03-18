import mouse
import keyboard
import sys
from threading import Lock, Thread

print_lock = Lock()

def safe_print(*a, **b):
    with print_lock:
        print(*a, **b)
        sys.stdout.flush()


def handle_key_hook(e: tuple) -> None:
    if e.event_type == "down":
        safe_print("keyPress:", e.name)
    else :
        safe_print("keyRelease:", e.name)

mousePosX = 0
mousePosY = 0
def handle_mouse_hook(e: tuple) -> None:
    global mousePosX
    global mousePosY
    if type(e) == mouse.MoveEvent:
        mousePosX = e.x
        mousePosY = e.y
        safe_print("mouseMove:[",e.x,",",e.y,",",e.time,"]")
    elif type(e) == mouse.ButtonEvent:
        if  e.event_type == "down":
            safe_print("mouseDown:[",mousePosX,",",mousePosY,"]")
        else:
            safe_print("mouseUp:[",mousePosX,",",mousePosY,"]")

keyboard.hook(handle_key_hook)
mouse.hook(handle_mouse_hook)

def mousePress(button: int) -> None:
    finalTuple = mouse.get_position() + (button,)
    safe_print("mouseClick:", list(finalTuple))

def mouseDoubleClick(button: int) -> None:
    finalTuple = mouse.get_position() + (button,)
    safe_print("mouseDoubleClick:", list(finalTuple))
    

mouse.on_click(lambda: mousePress(1))
mouse.on_right_click(lambda: mousePress(2))
mouse.on_middle_click(lambda: mousePress(3))
mouse.on_double_click(lambda: mouseDoubleClick(1))

def mouse_poll_loop():
    while True:
        mouse.wait()

mouse_thread = Thread(target=mouse_poll_loop, args=())
mouse_thread.start()
keyboard.wait()

