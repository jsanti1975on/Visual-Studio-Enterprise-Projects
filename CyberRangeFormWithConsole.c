#include <windows.h>
#include <stdio.h> // For printf

// Function declarations
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Entry point for the Windows program
int main() {
    // Show a message in the terminal
    printf("Hello, and Welcome to my Cyber Range.\n");

    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char CLASS_NAME[] = "CyberRangeWindowClass";

    // Register the window class
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Desktop Cyber-Range Application",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hwnd) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);

    // Run the message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Window procedure for handling messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hButtonClose, hButtonCommands;

    switch (uMsg) {
    case WM_CREATE:
        // Create the "Close Console" button
        hButtonClose = CreateWindow(
            "BUTTON", "Close Form",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 50, 120, 30,
            hwnd, (HMENU)1,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL
        );

        // Create the "Show Commands" button
        hButtonCommands = CreateWindow(
            "BUTTON", "Show Commands",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            200, 50, 120, 30,
            hwnd, (HMENU)2,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL
        );
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 1: // Close Form button
            PostQuitMessage(0);
            break;

        case 2: // Show Commands button
            printf("Future Commands:\n");
            printf("1. Run 'ipconfig'.\n");
            printf("2. Open ESXi.\n");
            printf("3. Access Windows Server DIR.\n");
            MessageBox(hwnd, 
                "Future functionality will allow you to:\n\n"
                "1. Run 'ipconfig'.\n"
                "2. Open ESXi.\n"
                "3. Access Windows Server DIR.",
                "Commands Coming Soon", 
                MB_OK | MB_ICONINFORMATION);
            break;
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
