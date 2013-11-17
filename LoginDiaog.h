// LoginDiaog.h : main header file for the LOGINDIAOG application
//

#if !defined(AFX_LOGINDIAOG_H__C7413A42_A28D_4793_A660_8F09AD225B7D__INCLUDED_)
#define AFX_LOGINDIAOG_H__C7413A42_A28D_4793_A660_8F09AD225B7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLoginDiaogApp:
// See LoginDiaog.cpp for the implementation of this class
//

class CLoginDiaogApp : public CWinApp
{
public:
	CLoginDiaogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDiaogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLoginDiaogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDIAOG_H__C7413A42_A28D_4793_A660_8F09AD225B7D__INCLUDED_)
