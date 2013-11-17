// LoginDiaogDlg.h : header file
//

#if !defined(AFX_LOGINDIAOGDLG_H__97F77189_267F_4B69_9ED6_B11A94F7E742__INCLUDED_)
#define AFX_LOGINDIAOGDLG_H__97F77189_267F_4B69_9ED6_B11A94F7E742__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLoginDiaogDlg dialog

#include "LoginEdit.h"

class CLoginDiaogDlg : public CDialog
{
// Construction
public:
	CLoginDiaogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDiaogDlg)
	enum { IDD = IDD_LOGINDIAOG_DIALOG };
	CLoginEdit	m_password;
	CLoginEdit	m_user;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDiaogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLoginDiaogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDIAOGDLG_H__97F77189_267F_4B69_9ED6_B11A94F7E742__INCLUDED_)
