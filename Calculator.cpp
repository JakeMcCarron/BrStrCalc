// DialogTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogTestApp

BEGIN_MESSAGE_MAP(CDialogTestApp, CWinApp)
	//{{AFX_MSG_MAP(CDialogTestApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogTestApp construction

CDialogTestApp::CDialogTestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDialogTestApp object

CDialogTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDialogTestApp initialization

BOOL CDialogTestApp::InitInstance()
{
	AfxEnableControlContainer();

	CDialogTestDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
