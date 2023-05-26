// DialogTestDlg.h : header file
//

#if !defined(AFX_DIALOGTESTDLG_H__6DE4CC95_0003_11D4_AD6B_0050046174B4__INCLUDED_)
#define AFX_DIALOGTESTDLG_H__6DE4CC95_0003_11D4_AD6B_0050046174B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

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
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTESTDLG_H__6DE4CC95_0003_11D4_AD6B_0050046174B4__INCLUDED_)
