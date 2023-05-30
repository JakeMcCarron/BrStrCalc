#pragma once
#include "afxdialogex.h"
#include "lib/VariableHandler/VariableHandler.h"


// VariableDlg dialog

class VariableDlg : public CDialog
{
	DECLARE_DYNAMIC(VariableDlg)

public:
	VariableDlg(VariableHandler& varHandler, CWnd* pParent = nullptr);   // standard constructor
	virtual ~VariableDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VariableDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl varListCtrl;
	VariableHandler varHandler;
	int calcMode;
public:
	virtual BOOL OnInitDialog();
};
