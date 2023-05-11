#include <iostream>
#include <windows.h>

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam);

int main() {
  HINSTANCE hInstance = GetModuleHandle(NULL);
  HHOOK keyboardHook =
      SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, hInstance, 0);
  HHOOK mouseHook =
      SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, hInstance, 0);

  MSG message;
  while (GetMessage(&message, NULL, 0, 0)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }

  UnhookWindowsHookEx(keyboardHook);
  UnhookWindowsHookEx(mouseHook);
  return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HC_ACTION) {
    KBDLLHOOKSTRUCT *keyboardHook = (KBDLLHOOKSTRUCT *)lParam;
    if (wParam == WM_KEYDOWN) {
      std::cout << "keyPress: " << keyboardHook->vkCode << std::endl;
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}

LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HC_ACTION) {
    MSLLHOOKSTRUCT *mouseHook = (MSLLHOOKSTRUCT *)lParam;
    switch (wParam) {
    case WM_MOUSEMOVE:
      std::cout << "mouseMove:[" << mouseHook->pt.x << ", " << mouseHook->pt.y
                << "]" << std::endl;
      break;
    case WM_LBUTTONDOWN:
      std::cout << "mouseDown:[" << mouseHook->pt.x << ", " << mouseHook->pt.y
                << "]" << std::endl;
      break;
    case WM_LBUTTONUP:
      std::cout << "mouseUp:[" << mouseHook->pt.x << ", " << mouseHook->pt.y
                << "]" << std::endl;
      break;
    case WM_RBUTTONDOWN:
      std::cout << "Right mouse button down" << std::endl;
      break;
    case WM_RBUTTONUP:
      std::cout << "Right mouse button up" << std::endl;
      break;
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}
