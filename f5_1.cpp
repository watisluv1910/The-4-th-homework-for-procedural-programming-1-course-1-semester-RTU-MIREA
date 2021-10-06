#include <Windows.h>
#include <stdlib.h>
#include <math.h>

int f5_1() {
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    SelectObject(hDC, Pen);
    MoveToEx(hDC, 0, 85, NULL);
    LineTo(hDC, 200, 85);
    MoveToEx(hDC, 100, 0, NULL);
    LineTo(hDC, 100, 170);
    for (float x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
    {
        MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL);//10 - scale
        LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
    }
    system("pause");
    ReleaseDC(hWnd, hDC);
    return 0;
}