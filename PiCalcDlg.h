#pragma once
#include "StdAfx.h"
#include "afxdialogex.h"

import PiFuncs;

// PiCalcDlg dialog

class PiCalcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PiCalcDlg)

public:
	PiCalcDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PiCalcDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PI_CALC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	
	virtual BOOL OnInitDialog();
	
	afx_msg void OnNMCustomdrawThreadSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedPiCalcGo();
	
	CEdit piOutCtrl;
	CStatic threadCountCtrl;
	CSliderCtrl threadSliderCtrl;
	CButton piCalcBtnCtrl;
	CEdit piNumDigitsCtrl;

	bool calculating = false;
};
