
#pragma once

typedef int ( CALLBACK * PFUNC ) ( PCHAR );

class CSySkin
{
public:
	CSySkin(void);
	~CSySkin(void);
private:
	PFUNC m_pFunc;
	HMODULE m_hModule;
	TCHAR m_szCurrPath[MAX_PATH];
	TCHAR m_szDLLPath[MAX_PATH];
	TCHAR m_szSkinPath[MAX_PATH];
private:
	BOOL GetModulePathName(LPTSTR lpszPath, UINT nLen);
	BOOL ReleaseRes(UINT nResID, LPCTSTR szResType, LPCTSTR szFilePath);
public:
	BOOL LoadDLLFromRes(UINT nResID, LPCTSTR szResType);
	BOOL LoadDLLFromPath(LPCTSTR szFilePath);
	BOOL LoadSkinFromRes(UINT nResID, LPCTSTR szResType);
	BOOL LoadSkinFromPath(LPCTSTR szFilePath);
	BOOL InstallSkin();
	BOOL UnInstallSkin(BOOL bDelete = FALSE);
};
