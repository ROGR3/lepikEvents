#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main() {
  Display *display = XOpenDisplay(nullptr);
  if (display == nullptr) {
    std::cerr << "Failed to open display" << std::endl;
    return 1;
  }

  XEvent event;
  Window root = XDefaultRootWindow(display);
  XGrabKeyboard(display, root, false, GrabModeAsync, GrabModeAsync,
                CurrentTime);
  XGrabPointer(display, root, false,
               PointerMotionMask | ButtonPressMask | ButtonReleaseMask,
               GrabModeAsync, GrabModeAsync, None, None, CurrentTime);

  while (true) {
    XNextEvent(display, &event);
    switch (event.type) {
    case KeyPress: {
      char buffer[32];
      KeySym keysym;
      XLookupString(&event.xkey, buffer, sizeof(buffer), &keysym, nullptr);
      std::cout << "keyPress: " << buffer << std::endl;
      std::cout << "keyDown: " << buffer << std::endl;
      break;
    }
    case KeyRelease: {
      char buffer[32];
      KeySym keysym;
      XLookupString(&event.xkey, buffer, sizeof(buffer), &keysym, nullptr);
      std::cout << "keyUp: " << buffer << std::endl;
      break;
    }
    case MotionNotify: {
      std::cout << "mouseMove:[" << event.xmotion.x << "," << event.xmotion.y
                << "," << event.xmotion.time << "]" << std::endl;
      break;
    }
    case ButtonPress: {
      std::cout << "mouseClick:[" << event.xbutton.x << "," << event.xbutton.y
                << "," << event.xbutton.button << "]" << std::endl;
      std::cout << "mouseDown:[" << event.xbutton.x << "," << event.xbutton.y
                << "," << event.xbutton.button << "]" << std::endl;
      break;
    }
    case ButtonRelease: {
      std::cout << "mouseUp:[" << event.xbutton.x << "," << event.xbutton.y
                << "," << event.xbutton.button << "]" << std::endl;
      break;
    }
    case ButtonDoubleClick: {
      std::cout << "mouseDoubleClick:[" << event.xbutton.x << ","
                << event.xbutton.y << "," << event.xbutton.button << "]"
                << std::endl;
      break;
    }
    default:
      break;
    }
  }

  XCloseDisplay(display);
  return 0;
}
