// DialogTestDlg.h : header file
//

#if !defined(AFX_DIALOGTESTDLG_H__6DE4CC95_0003_11D4_AD6B_0050046174B4__INCLUDED_)
#define AFX_DIALOGTESTDLG_H__6DE4CC95_0003_11D4_AD6B_0050046174B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <utility>
#include <string>
#include "lib/VariableHandler/VariableHandler.h"


/////////////////////////////////////////////////////////////////////////////
// CDialogTestDlg dialog

class CDialogTestDlg : public CDialog
{
// Construction
public:
	CDialogTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogTestDlg)
	enum { IDD = IDD_DIALOGTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedDivide();
private:
	CEdit val1Ctrl;
	CEdit val2Ctrl;
	CEdit resultCtrl;
	CEdit variableCtrl;
	CString varDef;

	int calcMode = 0;

	VariableHandler varHandler;

	std::wstring GetEditCtrlText(const CEdit& ctrl);

	std::pair<double, double> GetValsDec(const std::pair<std::wstring, std::wstring> vals);
	std::pair<long long, long long> GetValsInt(const std::pair<std::wstring, std::wstring> vals);

public:
	afx_msg void OnBnClickedModeInt();
	afx_msg void OnBnClickedModeDec();
	afx_msg void OnEnChangeValue1();
	afx_msg void OnEnChangeValue2();
	afx_msg void OnBnClickedCopyto1();
	afx_msg void OnBnClickedCopyto2();
	afx_msg void OnBnClickedVarAssign();
	afx_msg void OnEnChangeVarAssignEdit();
	afx_msg void OnBnClickedOpenVariablesDlg();
	afx_msg void OnBnClickedOpenPiCalc();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTESTDLG_H__6DE4CC95_0003_11D4_AD6B_0050046174B4__INCLUDED_)
