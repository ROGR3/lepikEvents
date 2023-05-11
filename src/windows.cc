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
      char buffer[256];
      if (GetKeyNameTextA(keyboardHook->scanCode << 16, buffer,
                          sizeof(buffer))) {
        std::cout << "keyPress: " << buffer << std::endl;
        std::cout << "keyDown: " << buffer << std::endl;
      }
    } else if (wParam == WM_KEYUP) {
      char buffer[256];
      if (GetKeyNameTextA(keyboardHook->scanCode << 16, buffer,
                          sizeof(buffer))) {
        std::cout << "keyUp: " << buffer << std::endl;
      }
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}

LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HC_ACTION) {
    MSLLHOOKSTRUCT *mouseHook = (MSLLHOOKSTRUCT *)lParam;
    switch (wParam) {
    case WM_MOUSEMOVE:
      std::cout << "mouseMove:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << "," << mouseHook->time << "]" << std::endl;
      break;
    case WM_LBUTTONDOWN:
      std::cout << "mouseClick:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",1]" << std::endl;
      std::cout << "mouseDown:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",1]" << std::endl;
      break;
    case WM_LBUTTONUP:
      std::cout << "mouseUp:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",1]" << std::endl;
      break;
    case WM_RBUTTONDOWN:
      std::cout << "mouseClick:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",2]" << std::endl;
      std::cout << "mouseDown:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",2]" << std::endl;
      break;
    case WM_RBUTTONUP:
      std::cout << "mouseUp:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",2]" << std::endl;
      break;
    case WM_MBUTTONDOWN:
      std::cout << "mouseClick:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",3]" << std::endl;
      std::cout << "mouseDown:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",3]" << std::endl;
      break;
    case WM_MBUTTONUP:
      std::cout << "mouseUp:[" << mouseHook->pt.x << "," << mouseHook->pt.y
                << ",3]" << std::endl;
      break;
    case WM_LBUTTONDBLCLK:
      std::cout << "mouseDoubleClick:[" << mouseHook->pt.x << ","
                << mouseHook->pt.y << ",1]" << std::endl;
    case WM_RBUTTONDBLCLK:
      std::cout << "mouseDoubleClick:[" << mouseHook->pt.x << ","
                << mouseHook->pt.y << ",2]" << std::endl;
      break;
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}
