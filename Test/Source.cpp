#include <tchar.h>
#include <windows.h>
#include <WinCred.h>

#pragma comment(lib,"Credui.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL save = false;
	DWORD authPackage = 0;
	LPVOID authBuffer;
	ULONG authBufferSize = 0;
	CREDUI_INFO credUiInfo;

	credUiInfo.pszCaptionText = TEXT("My caption");
	credUiInfo.pszMessageText = TEXT("My message");
	credUiInfo.cbSize = sizeof(credUiInfo);
	credUiInfo.hbmBanner = NULL;
	credUiInfo.hwndParent = NULL;

	CredUIPromptForWindowsCredentials(&(credUiInfo), 0, &(authPackage),
		NULL, 0, &authBuffer, &authBufferSize, &(save), 0);
}
