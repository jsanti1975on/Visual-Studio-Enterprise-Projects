#include <windows.h>
#include <stdio.h>
#include <gdiplus.h> // For GDI+ Also not image did not load & have not tested other configs
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "gdiplus.lib") // Link GDI+ library

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void ShowCustomMessageBox(HWND hwnd, LPCSTR message, LPCSTR imagePath);

// Entry point
int main() {
    printf("Hello and Welcome to Mimi's Cyber-Range.\n");

    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char CLASS_NAME[] = "CyberRangeWindowClass";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Mimi's Orchid Shop - Sales Application",
                               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,
                               NULL, NULL, hInstance, NULL);

    if (!hwnd) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hButtonShowMessage;

    switch (uMsg) {
    case WM_CREATE:
        // Button to show the custom message box
        hButtonShowMessage = CreateWindow("BUTTON", "Show Message with Image",
                                          WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                          150, 100, 200, 30,
                                          hwnd, (HMENU)1,
                                          (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
                                          NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            ShowCustomMessageBox(hwnd, "Welcome to Mimi's Orchid Shop!\nEnjoy the beauty of orchids.", "orchid_image.png");
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}



void ShowCustomMessageBox(HWND hwnd, LPCSTR message, LPCSTR imagePath) {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;

    // Initialize GDI+
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // Create the dialog box window
    HWND hDlg = CreateWindowEx(0, "STATIC", "Custom Message Box",
                               WS_POPUP | WS_BORDER | WS_VISIBLE,
                               CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
                               hwnd, NULL, NULL, NULL);

    HDC hdc = GetDC(hDlg);

    // Load the image using GDI+ C API
    GpImage* image;
    GdipLoadImageFromFile(L"orchid_image.png", &image);

    // Create a graphics object
    GpGraphics* graphics;
    GdipCreateFromHDC(hdc, &graphics);

    // Draw the image on the right side
    GdipDrawImageRect(graphics, image, 250, 20, 100, 100);

    // Draw the text on the left side
    RECT textRect = {20, 20, 230, 150};
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(0, 0, 0));
    DrawText(hdc, message, -1, &textRect, DT_LEFT | DT_WORDBREAK);

    // Wait for user to close
    MessageBox(hDlg, "Click OK to close.", "Custom Message", MB_OK);

    // Clean up resources
    GdipDisposeImage(image);
    GdipDeleteGraphics(graphics);
    ReleaseDC(hDlg, hdc);
    DestroyWindow(hDlg);
    GdiplusShutdown(gdiplusToken);
}
