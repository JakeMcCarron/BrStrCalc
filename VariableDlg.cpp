// VariableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "VariableDlg.h"
#include "resource.h"
#include <format>



// VariableDlg dialog

IMPLEMENT_DYNAMIC(VariableDlg, CDialog)

VariableDlg::VariableDlg(VariableHandler& vars, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_VariableDlg, pParent)
{
	varHandler = vars;
}

VariableDlg::~VariableDlg()
{
}

void VariableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VARIABLE_LIST, varListCtrl);
}


BEGIN_MESSAGE_MAP(VariableDlg, CDialog)
END_MESSAGE_MAP()


// VariableDlg message handlers


BOOL VariableDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	varListCtrl.InsertColumn(0, L"Variable Name", LVCFMT_LEFT, 150);
	varListCtrl.InsertColumn(1, L"Value", LVCFMT_LEFT, 500);

	//Init var list
	int index = 0;
	for (auto& varVal : varHandler.GetFullMap())
	{
		LVITEM item;
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 0;
		item.pszText = (LPWSTR)varVal.first.c_str();
		varListCtrl.InsertItem(&item);

		item.iSubItem = 1;
		std::wstring frmt = std::format(L"{}", varVal.second);
		item.pszText = (LPWSTR)frmt.c_str();
		varListCtrl.SetItem(&item);

		index++;
	}

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
