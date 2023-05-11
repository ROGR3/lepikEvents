#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main() {
  Display *display = XOpenDisplay(NULL);
  Window root = DefaultRootWindow(display);
  XEvent event;
  XGrabKeyboard(display, root, True, GrabModeAsync, GrabModeAsync, CurrentTime);
  XGrabPointer(display, root, True,
               PointerMotionMask | ButtonPressMask | ButtonReleaseMask,
               GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
  while (true) {
    XNextEvent(display, &event);
    switch (event.type) {
    case KeyPress:
      std::cout << "Key pressed: " << XLookupKeysym(&event.xkey, 0)
                << std::endl;
      break;
    case ButtonPress:
      switch (event.xbutton.button) {
      case Button1:
        std::cout << "Left mouse button down" << std::endl;
        break;
      case Button2:
        std::cout << "Middle mouse button down" << std::endl;
        break;
      case Button3:
        std::cout << "Right mouse button down" << std::endl;
        break;
      }
      break;
    case ButtonRelease:
      switch (event.xbutton.button) {
      case Button1:
        std::cout << "Left mouse button up" << std::endl;
        break;
      case Button2:
        std::cout << "Middle mouse button up" << std::endl;
        break;
      case Button3:
        std::cout << "Right mouse button up" << std::endl;
        break;
      }
      break;
    case MotionNotify:
      std::cout << "Mouse moved: " << event.xmotion.x << ", " << event.xmotion.y
                << std::endl;
      break;
    }
  }
  XCloseDisplay(display);
  return 0;
}
