// WindowApp.cpp : Defines the entry point for the application.

#include <iostream>
#include <string>
#include <time.h>

#include "stdafx.h"
#include "ScoreKeeper.h"
using namespace std;


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];					// The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
string K = "Kajsa";
string J = "Johan";

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// Gui elements
HWND j_score_lbl, k_score_lbl;

// Model
Model gameModel;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.


    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWAPP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWAPP));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWAPP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWAPP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(
	   szWindowClass, // Window class
	   L"Test title", // Title of the window (L to convert to LPCWSTR)
	   WS_OVERLAPPEDWINDOW,	// Window style
	   0, 0, 800, 600, // Size and position (x, y, width, height)
	   nullptr, // Parent window
	   nullptr, // Menu
	   hInstance, // Instance handle
	   nullptr // Additinal application data
   );

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		int js, ks;
		js = gameModel.getScore(J);	// Hämta nuvarande poäng
		ks = gameModel.getScore(K);


		wchar_t j_score[256];					// Konvertera till LPCWSTR
		wsprintfW(j_score, L"%d", js);

		wchar_t k_score[256];
		wsprintfW(k_score, L"%d", ks);
		

		/* Johans score label */
		j_score_lbl = CreateWindow(
			L"static", // Window class (button)
			j_score, // Window text
			WS_VISIBLE | WS_CHILD, // Window style (WS)
			200, 10, 80, 25, // x, y, width, height
			hWnd,			// Parent window
			(HMENU)0,		// Menu ID
			NULL,
			NULL
		);

		/* Kajsas score label */
		k_score_lbl = CreateWindow(
			L"static", // Window class (button)
			k_score, // Window text
			WS_VISIBLE | WS_CHILD, // Window style (WS)
			200, 40, 80, 25, // x, y, width, height
			hWnd,			// Parent window
			(HMENU)0,		// Menu ID
			NULL,
			NULL
		);

		/* Johans score knapp */
		CreateWindow(
			L"button", // Window class (button)
			L"Johan", // Window text
			WS_VISIBLE | WS_CHILD, // Window style (WS)
			10, 10, 80, 25, // x, y, width, height
			hWnd,			// Parent window
			(HMENU) 1,		// Menu ID
			NULL,
			NULL
		);

		/* Kajsas score knapp */
		CreateWindow(
			L"button", // Window class (button)
			L"Kajsa", // Window text
			WS_VISIBLE | WS_CHILD, // Window style (WS)
			10, 40, 80, 25, // x, y, width, height
			hWnd,			// Parent window
			(HMENU) 2,		// Menu ID
			NULL,
			NULL
		);



		break;
    case WM_COMMAND:
        {
			//int score;

            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case 1:		// Johan-knappen har tryckts
				gameModel.AddScore(J); //String J = "Johan" deklarerad längst upp, mindre risk för felstavning mm
				//score = gameModel.m_Johan;
				wchar_t j_buffer[256];
				wsprintfW(j_buffer, L"%d", gameModel.getScore(J));
				SetWindowText(j_score_lbl, j_buffer);
				break;
			case 2:		// Kajsa-knappen har tryckts
				gameModel.AddScore(K); //String K = "Kajsa" deklarerad längst upp, mindre risk för felstavning mm
				wchar_t k_buffer[256];
				wsprintfW(k_buffer, L"%d", gameModel.getScore(K));
				SetWindowText(k_score_lbl, k_buffer);
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
