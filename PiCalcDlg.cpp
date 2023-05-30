// PiCalcDlg.cpp : implementation file
//

#include "afxdialogex.h"
#include "PiCalcDlg.h"
#include "resource.h"
#include <thread>
#include <format>


// PiCalcDlg dialog

IMPLEMENT_DYNAMIC(PiCalcDlg, CDialogEx)

PiCalcDlg::PiCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PI_CALC, pParent)
{

}

PiCalcDlg::~PiCalcDlg()
{
}

void PiCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PI_OUTPUT, piOutCtrl);
	DDX_Control(pDX, IDC_THREAD_SLIDER, threadSliderCtrl);
	DDX_Control(pDX, IDC_THREAD_COUNT, threadCountCtrl);
	DDX_Control(pDX, IDC_PI_CALC_GO, piCalcBtnCtrl);
	DDX_Control(pDX, IDC_PI_NUM_DIGITS, piNumDigitsCtrl);
}


BEGIN_MESSAGE_MAP(PiCalcDlg, CDialogEx)

	ON_NOTIFY(NM_CUSTOMDRAW, IDC_THREAD_SLIDER, &PiCalcDlg::OnNMCustomdrawThreadSlider)
	ON_BN_CLICKED(IDC_PI_CALC_GO, &PiCalcDlg::OnBnClickedPiCalcGo)
END_MESSAGE_MAP()


// PiCalcDlg message handlers
BOOL PiCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	threadSliderCtrl.SetRange(1, std::thread::hardware_concurrency());

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void PiCalcDlg::OnNMCustomdrawThreadSlider(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	const std::wstring threadCount = std::format(L"{}", threadSliderCtrl.GetPos());
	threadCountCtrl.SetWindowTextW(threadCount.c_str());
	*pResult = 0;
}


void PiCalcDlg::OnBnClickedPiCalcGo()
{
	calculating = !calculating;
	calculating ? piCalcBtnCtrl.SetWindowTextW(L"Stop") : piCalcBtnCtrl.SetWindowTextW(L"Calculate");
	auto pi = CalcPi(2, 1);
	auto x = BBPAlgorithm(0);
	auto y = BBPAlgorithm(1);
	auto z = BBPAlgorithm(2);
	std::wstring frmt = std::format(L"{}", pi);
	piOutCtrl.SetWindowTextW(frmt.c_str());
}
