// LoginEdit.cpp : implementation file
//

#include "stdafx.h"
#include "LoginDiaog.h"
#include "LoginEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginEdit

CLoginEdit::CLoginEdit(const CString &str, bool bIsPassword)
: m_strDefault(str), m_bIsPassword(bIsPassword)
, m_bNULL(false)
{

}

CLoginEdit::~CLoginEdit()
{
}


BEGIN_MESSAGE_MAP(CLoginEdit, CEdit)
	//{{AFX_MSG_MAP(CLoginEdit)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, OnSetfocus)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginEdit message handlers

void CLoginEdit::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	GetWindowText(str);
	if(str.GetLength() == 0 && !m_bNULL)
	{
		m_bNULL = true;
	}	
}

void CLoginEdit::OnKillfocus() 
{
	// TODO: Add your control notification handler code here
	if(m_bNULL)
	{
		if(m_bIsPassword)
		{
			SetPasswordChar(NULL);
			ModifyStyle(ES_PASSWORD, 0);
		}
		SetWindowText(m_strDefault);
	}
}

void CLoginEdit::OnSetfocus() 
{
	// TODO: Add your control notification handler code here
	if(m_bNULL)
	{
		SetWindowText("");
		Invalidate();
	}
}

HBRUSH CLoginEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	CBrush Bk_Brush;
	Bk_Brush.CreateSolidBrush(RGB(255, 255, 255));
	
	if(m_bNULL)
		pDC->SetTextColor(RGB(156, 156, 156));
	else
		pDC->SetTextColor(RGB(0, 0, 0));
	
	pDC->SetBkColor(RGB(255, 255, 255));
	return (HBRUSH)Bk_Brush.GetSafeHandle();
	
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}

void CLoginEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bNULL)
	{

		if(nChar == VK_LEFT || nChar == VK_RIGHT || nChar == VK_DOWN || nChar == VK_UP || nChar == VK_BACK || nChar == VK_DELETE || nChar == VK_HOME || nChar == VK_END)
		{
			return ;
		}
		else
		{
			if(m_bIsPassword)
			{
				SetPasswordChar('*');
				ModifyStyle(0, ES_PASSWORD);
			}
			
			
			/*CString str;
			str.Format("%d", nChar);
			MessageBox(str);*/

			// ÆÁ±Îshift, ctrl, win¼ü
			if(nChar == 16 || nChar == 17 || nChar == 91)
			{
				return ;
			}

			m_bNULL = false;
			SendMessage(WM_KEYDOWN, nChar, 0);
		}
	}
	
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLoginEdit::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bIsPassword)
	{
		SetFocus();
		SetWindowText(m_strDefault);
	}

	CEdit::PreSubclassWindow();
}

void CLoginEdit::Clear_All(void)
{
	m_bNULL = true;
	SetWindowText("");
}
