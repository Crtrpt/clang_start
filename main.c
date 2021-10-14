#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#pragma comment(lib, "user32.lib")

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {

    MSG  msg;
    HWND hwnd;
    WNDCLASSW wc;

    wchar_t computerName[16]=L"CloudExplorer";

    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.lpszClassName = computerName;
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszMenuName  = NULL;
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);

    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);

    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, computerName,
                         WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                         100, 100, x-200, y-200, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
         printf("%d",msg.message);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
                         WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}