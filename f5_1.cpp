//#include <Windows.h>
//#include <stdlib.h>
//#include <math.h>
//
//int f5_1() {
//    HWND hWnd = GetConsoleWindow();
//    HDC hDC = GetDC(hWnd);
//    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
//    SelectObject(hDC, Pen);
//    MoveToEx(hDC, 0, 85, NULL);
//    LineTo(hDC, 200, 85);
//    MoveToEx(hDC, 100, 0, NULL);
//    LineTo(hDC, 100, 170);
//    for (float x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
//    {
//        MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL);//10 - scale
//        LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
//    }
//    system("pause");
//    ReleaseDC(hWnd, hDC);
//    return 0;
//}

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);



        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}