import mouse
import keyboard
import sys


def keyboardRelease(e: tuple) -> None:
    print("keyRelease:", e.name)
    sys.stdout.flush()


def mousePress(button: int) -> None:
    finalTuple = mouse.get_position() + (button,)
    print("mouseClick:", list(finalTuple))
    sys.stdout.flush()


keyboard.on_release(keyboardRelease)

mouse.on_click(lambda: mousePress(1))
mouse.on_right_click(lambda: mousePress(2))
mouse.on_middle_click(lambda: mousePress(3))


input()
