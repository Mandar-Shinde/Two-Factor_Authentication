// CppWin32Dialog.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CppWin32Dialog.h"
#include <CommCtrl.h>
// For nice controls look 
#pragma comment(linker, \
  "\"/manifestdependency:type='Win32' "\
  "name='Microsoft.Windows.Common-Controls' "\
  "version='6.0.0.0' "\
  "processorArchitecture='*' "\
  "publicKeyToken='6595b64144ccf1df' "\
  "language='*'\"")

#pragma comment(lib, "ComCtl32.lib")

INT_PTR CALLBACK DialogProc(HWND ,UINT ,WPARAM ,LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine,  int nCmdShow)
{
	HWND hDlg;
	MSG msg;
	BOOL ret;
	InitCommonControls();

	//IDD_VALIDATOR

	hDlg = CreateDialogParam(hInstance, MAKEINTRESOURCE(IDD_VALIDATOR), 0, DialogProc, 0);

    //hDlg = CreateDialogParam(hInstance, MAKEINTRESOURCE(frmMain), 0, DialogProc, 0);

    ShowWindow(hDlg, nCmdShow);

	//Sleep(10000);
	// Main message loop:
	while((ret = GetMessage(&msg, 0, 0, 0)) != 0) 
	{
    if(ret == -1)
      return -1;

    if(!IsDialogMessage(hDlg, &msg)) 
	{
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

	return (int) msg.wParam;
}

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;


	HINSTANCE l_hInstance = (HINSTANCE)GetWindowLong(hDlg, IDBANNER);
	HBITMAP l_hBitmap = (HBITMAP)LoadImage(l_hInstance, MAKEINTRESOURCE(IDB_LOGO_IMAGE), IMAGE_BITMAP, 0, 0, NULL);

	HANDLE hbitmap;

	HWND button;

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		//SendMessage(MainLogo, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmap);
		//SendMessage(hDlg, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)(HANDLE)l_hBitmap);
		 hbitmap = LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_IMAGE), IMAGE_BITMAP,400,50, LR_DEFAULTCOLOR);
		
		 button = CreateWindow(L"BUTTON", L"Test button", BS_BITMAP | WS_VISIBLE | WS_CHILD, 0, 0, 400,50, hDlg, NULL, l_hInstance, NULL);
	
		SendMessage(button, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbitmap);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDBU_EXIT:
			PostQuitMessage(0);
			break;
		//case IDBU_CK:
		//	MessageBox(NULL,L"MSG Cancel,Retry,Continue",	L"Hello Message Box",	MB_ICONERROR | MB_ABORTRETRYIGNORE);
		//	break;
		}
		break;
			case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hDlg, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
	break;

	}
	return (INT_PTR)FALSE;
}
