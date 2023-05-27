// DialogTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include <string>
#include <format>

import BasicMaths;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogTestDlg dialog

CDialogTestDlg::CDialogTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CDialogTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogTestDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_VALUE_1, val1Ctrl);
	DDX_Control(pDX, IDC_VALUE_2, val2Ctrl);
	DDX_Control(pDX, IDC_RESULT, resultCtrl);
	DDX_Control(pDX, IDC_VAR_ASSIGN_EDIT, variableCtrl);
	DDX_Text(pDX, IDC_VAR_DEF, varDef);
}

BEGIN_MESSAGE_MAP(CDialogTestDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PLUS, &CDialogTestDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CDialogTestDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULTIPLY, &CDialogTestDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_DIVIDE, &CDialogTestDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_MODE_INT, &CDialogTestDlg::OnBnClickedModeInt)
	ON_BN_CLICKED(IDC_MODE_DEC, &CDialogTestDlg::OnBnClickedModeDec)
	ON_EN_CHANGE(IDC_VALUE_1, &CDialogTestDlg::OnEnChangeValue1)
	ON_EN_CHANGE(IDC_VALUE_2, &CDialogTestDlg::OnEnChangeValue2)
	ON_BN_CLICKED(IDC_COPYTO_1, &CDialogTestDlg::OnBnClickedCopyto1)
	ON_BN_CLICKED(IDC_COPYTO_2, &CDialogTestDlg::OnBnClickedCopyto2)
	ON_BN_CLICKED(IDC_VAR_ASSIGN, &CDialogTestDlg::OnBnClickedVarAssign)
	ON_EN_CHANGE(IDC_VAR_ASSIGN_EDIT, &CDialogTestDlg::OnEnChangeVarAssignEdit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogTestDlg message handlers

BOOL CDialogTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CheckRadioButton(IDC_MODE_INT, IDC_MODE_DEC, IDC_MODE_INT);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialogTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CDialogTestDlg::OnBnClickedPlus()
{
	std::wstring result;
	if (calcMode == 0)
	{
		auto vals = GetValsInt(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Addition(vals.first, vals.second));
	}
	else if(calcMode == 1)
	{
		auto vals = GetValsDec(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Addition(vals.first, vals.second));
	}

	resultCtrl.SetWindowTextW(result.c_str());
}


void CDialogTestDlg::OnBnClickedMinus()
{
	std::wstring result;
	if (calcMode == 0)
	{
		auto vals = GetValsInt(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Subtraction(vals.first, vals.second));
	}
	else if (calcMode == 1)
	{
		auto vals = GetValsDec(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Subtraction(vals.first, vals.second));
	}

	resultCtrl.SetWindowTextW(result.c_str());
}


void CDialogTestDlg::OnBnClickedMultiply()
{
	std::wstring result;
	if (calcMode == 0)
	{
		auto vals = GetValsInt(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Multiplication(vals.first, vals.second));
	}
	else if (calcMode == 1)
	{
		auto vals = GetValsDec(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Multiplication(vals.first, vals.second));
	}

	resultCtrl.SetWindowTextW(result.c_str());
}


void CDialogTestDlg::OnBnClickedDivide()
{
	std::wstring result;
	if (calcMode == 0)
	{
		auto vals = GetValsInt(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Division(vals.first, vals.second));
	}
	else if (calcMode == 1)
	{
		auto vals = GetValsDec(std::make_pair(GetEditCtrlText(val1Ctrl), GetEditCtrlText(val2Ctrl)));
		result = std::format(L"{}", Division(vals.first, vals.second));
	}

	resultCtrl.SetWindowTextW(result.c_str());
}



std::wstring CDialogTestDlg::GetEditCtrlText(const CEdit& ctrl)
{
	CString buf;
	ctrl.GetWindowTextW(buf);
	return buf.GetString();
}


std::pair<double, double> CDialogTestDlg::GetValsDec(const std::pair<std::wstring, std::wstring> vals)
{
	double val1, val2;
	auto varRes1 = varHandler.RetrieveFromMap<double>(vals.first);
	if (varRes1.has_value())
	{
		val1 = varRes1.value();
	}
	else
	{
		val1 = _wtof(vals.first.c_str());
	}
	auto varRes2 = varHandler.RetrieveFromMap<double>(vals.second);
	if (varRes2.has_value())
	{
		val2 = varRes2.value();
	}
	else
	{
		val2 = _wtof(vals.second.c_str());
	}
	return std::make_pair(val1, val2);
}

std::pair<long long, long long> CDialogTestDlg::GetValsInt(const std::pair<std::wstring, std::wstring> vals)
{
	long long val1, val2;
	auto varRes1 = varHandler.RetrieveFromMap<long long>(vals.first);
	if (varRes1.has_value())
	{
		val1 = varRes1.value();
	}
	else
	{
		val1 = _wtof(vals.first.c_str());
	}
	auto varRes2 = varHandler.RetrieveFromMap<long long>(vals.second);
	if (varRes2.has_value())
	{
		val2 = varRes2.value();
	}
	else
	{
		val2 = _wtof(vals.second.c_str());
	}
	return std::make_pair(val1, val2);
}

void CDialogTestDlg::OnBnClickedModeInt()
{
	calcMode = 0;
}


void CDialogTestDlg::OnBnClickedModeDec()
{
	calcMode = 1;
}


void CDialogTestDlg::OnEnChangeValue1()
{

}


void CDialogTestDlg::OnEnChangeValue2()
{

}


void CDialogTestDlg::OnBnClickedCopyto1()
{
	val1Ctrl.SetWindowTextW(GetEditCtrlText(resultCtrl).c_str());
}


void CDialogTestDlg::OnBnClickedCopyto2()
{
	val2Ctrl.SetWindowTextW(GetEditCtrlText(resultCtrl).c_str());
}


void CDialogTestDlg::OnBnClickedVarAssign()
{
	if (GetEditCtrlText(variableCtrl) == L"")
	{
		AfxMessageBox(L"Variable name cannot be empty!");
		return;
	}

	if (calcMode == 0)
	{
		const long long val = _wtoll(GetEditCtrlText(resultCtrl).c_str());
		const bool success = varHandler.AddToMap<long long>(GetEditCtrlText(variableCtrl), val);
		if (!success)
		{
			if (AfxMessageBox(L"Variable already exists, override?", MB_YESNO) == IDYES)
			{
				varHandler.AddToMapOverride<long long>(GetEditCtrlText(variableCtrl), val);
			}
		}
	}
	else if (calcMode == 1)
	{
		const double val = _wtof(GetEditCtrlText(resultCtrl).c_str());
		const bool success = varHandler.AddToMap<double>(GetEditCtrlText(variableCtrl), val);
		if (!success)
		{
			if (AfxMessageBox(L"Variable already exists, override?", MB_YESNO) == IDYES)
			{
				varHandler.AddToMapOverride<double>(GetEditCtrlText(variableCtrl), val);
			}
		}
	}
	OnEnChangeVarAssignEdit();
}


void CDialogTestDlg::OnEnChangeVarAssignEdit()
{
	if (GetEditCtrlText(variableCtrl).find_first_of(L"0123456789.-") != std::string::npos)
	{
		AfxMessageBox(L"Variables cannot be numeric!");
		variableCtrl.SetWindowTextW(L"");
	}

	if (calcMode == 0)
	{
		auto varRes = varHandler.RetrieveFromMap<long long>(GetEditCtrlText(variableCtrl));
		if (varRes.has_value())
		{
			varDef.Format(L"%s = %d", GetEditCtrlText(variableCtrl).c_str(), varRes.value());
		}
		else
		{
			varDef.Format(L"%s undefined", GetEditCtrlText(variableCtrl).c_str());
		}
	}
	else if (calcMode == 1)
	{
		auto varRes = varHandler.RetrieveFromMap<double>(GetEditCtrlText(variableCtrl));
		if (varRes.has_value())
		{
			varDef.Format(L"%s = %d", GetEditCtrlText(variableCtrl).c_str(), varRes.value());
		}
		else
		{
			varDef.Format(L"%s undefined", GetEditCtrlText(variableCtrl).c_str());
		}
	}

	UpdateData(FALSE);
}
