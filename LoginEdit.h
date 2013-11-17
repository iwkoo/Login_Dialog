#if !defined(AFX_LOGINEDIT_H__061372A3_B2B4_4887_8CE0_DC4C33688590__INCLUDED_)
#define AFX_LOGINEDIT_H__061372A3_B2B4_4887_8CE0_DC4C33688590__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginEdit window

class CLoginEdit : public CEdit
{
// Construction
public:
	CLoginEdit(const CString &str = "", bool bIsPassword = false);
	void Clear_All(void);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLoginEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLoginEdit)
	afx_msg void OnChange();
	afx_msg void OnKillfocus();
	afx_msg void OnSetfocus();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CString m_strDefault;
	bool m_bNULL;
	bool m_bIsPassword;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINEDIT_H__061372A3_B2B4_4887_8CE0_DC4C33688590__INCLUDED_)
