// DialogTest.h : main header file for the DIALOGTEST application
//

#if !defined(AFX_DIALOGTEST_H__6DE4CC93_0003_11D4_AD6B_0050046174B4__INCLUDED_)
#define AFX_DIALOGTEST_H__6DE4CC93_0003_11D4_AD6B_0050046174B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogTestApp:
// See DialogTest.cpp for the implementation of this class
//

class CDialogTestApp : public CWinApp
{
public:
	CDialogTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTEST_H__6DE4CC93_0003_11D4_AD6B_0050046174B4__INCLUDED_)
