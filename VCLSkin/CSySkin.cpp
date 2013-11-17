
#include "StdAfx.h"
#include "CSySkin.h"

CSySkin::CSySkin(void)
{
	m_hModule = NULL;
	m_pFunc = NULL;
	ZeroMemory(m_szCurrPath, MAX_PATH);
	ZeroMemory(m_szDLLPath, MAX_PATH);
	ZeroMemory(m_szSkinPath, MAX_PATH);
	GetModulePathName(m_szCurrPath, MAX_PATH);
}

CSySkin::~CSySkin(void)
{
}

BOOL CSySkin::GetModulePathName(LPTSTR lpszPath, UINT nLen)
{
	TCHAR szPath[MAX_PATH] = {0};
	DWORD dwRet = GetModuleFileName(NULL, szPath, MAX_PATH);
	if ( dwRet > 0 ) {
		size_t tLen = _tcslen(szPath)-1, idx = 0;
		for ( idx = tLen; idx >= 0; idx-- ) {
			if ( szPath[idx] == '\\' ) {
				break;
			}
		}
		_tcsncpy_s(lpszPath, MAX_PATH, szPath, idx);
	}else{
		return FALSE;
	}
	return TRUE;
}

BOOL CSySkin::ReleaseRes(UINT nResID, LPCTSTR szResType, LPCTSTR szFilePath)
{
	if ( nResID <= 0 || !szResType ) {
		return FALSE;
	}
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(nResID), szResType);
	if ( !hRsrc ) {
		return FALSE;
	}
	DWORD dwSize = SizeofResource(NULL, hRsrc);
	if ( dwSize <= 0 ) {
		return FALSE;
	}
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc); 
	if ( !hGlobal ) {
		return FALSE;
	}
	LPVOID pBuffer = LockResource(hGlobal);
	if ( !pBuffer ) {
		return FALSE;
	}
	HANDLE hFile = CreateFile(szFilePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);	//将文件从资源中释放，并隐藏
	if ( hFile == INVALID_HANDLE_VALUE ) {
		return FALSE;
	}
	DWORD dwWrited = 0;
	WriteFile(hFile, pBuffer, dwSize, &dwWrited, NULL);
	CloseHandle(hFile);
	return TRUE;
}

BOOL CSySkin::LoadDLLFromRes(UINT nResID, LPCTSTR szResType)
{
	if ( nResID <= 0 || !szResType ) {
		return FALSE;
	}
	TCHAR szPath[MAX_PATH] = {0};
	_tcscat_s(szPath, MAX_PATH, m_szCurrPath);
	_tcscat_s(szPath, MAX_PATH, _T("\\Skin.dll"));
	if ( ReleaseRes(nResID, szResType, szPath) ) {
		return LoadDLLFromPath(szPath);
	}
	return TRUE;
}

BOOL CSySkin::LoadSkinFromRes(UINT nResID, LPCTSTR szResType)
{
	if ( nResID <= 0 || !szResType ) {
		return FALSE;
	}
	TCHAR szPath[MAX_PATH] = {0};
	_tcscat_s(szPath, MAX_PATH, m_szCurrPath);
	_tcscat_s(szPath, MAX_PATH, _T("\\Skin.skn"));
	if ( ReleaseRes(nResID, szResType, szPath) ) {
		return LoadSkinFromPath(szPath);
	}
	return TRUE;
}

BOOL CSySkin::LoadDLLFromPath(LPCTSTR szFilePath)
{
	if ( !szFilePath ) {
		return FALSE;
	}
	_tcscpy_s(m_szDLLPath, MAX_PATH, szFilePath);
	m_hModule  = LoadLibrary(szFilePath);
	if ( m_hModule ) {
		m_pFunc = (PFUNC)GetProcAddress(m_hModule, "LoadSkin");
		if ( m_pFunc ) {
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CSySkin::LoadSkinFromPath(LPCTSTR szFilePath)
{
	if ( !szFilePath ) {
		return FALSE;
	}
	_tcscpy_s(m_szSkinPath, MAX_PATH, szFilePath);
	return TRUE;
}

BOOL CSySkin::InstallSkin()
{
	if ( !m_pFunc || _tcslen(m_szSkinPath) <= 0 || !PathFileExists(m_szSkinPath) ) {
		return FALSE;
	}
	char szSkinPath[MAX_PATH] = {0};
#ifdef _UNICODE
	WideCharToMultiByte(CP_ACP, 0, m_szSkinPath, -1, szSkinPath, MAX_PATH, NULL, NULL);
#else
	_tcscpy_s(szSkinPath, MAX_PATH, m_szSkinPath);
#endif
	return m_pFunc(szSkinPath);
}

BOOL CSySkin::UnInstallSkin(BOOL bDelete)
{
	BOOL bRet = FreeLibrary(m_hModule);
	if ( bDelete == TRUE ) {
		DeleteFile(m_szDLLPath);
		DeleteFile(m_szSkinPath);
	}
	return bRet;
}