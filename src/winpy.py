import mouse
import keyboard
import sys


def handle_hook(e: tuple) -> None:
    if e.event_type == "down":
        print("keyPress:", e.name)
    else :
        print("keyRelease:", e.name)
    sys.stdout.flush()



keyboard.hook(handle_hook)


def mousePress(button: int) -> None:
    finalTuple = mouse.get_position() + (button,)
    print("mouseClick:", list(finalTuple))
    sys.stdout.flush()


mouse.on_click(lambda: mousePress(1))
mouse.on_right_click(lambda: mousePress(2))
mouse.on_middle_click(lambda: mousePress(3))


keyboard.wait()

