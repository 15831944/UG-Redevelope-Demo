// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestProgram.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include <uf_ui.h>

// CMyDlg 对话框

IMPLEMENT_DYNAMIC(CMyDlg, CDialog)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{

}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CMyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDlg 消息处理程序

// 按钮实现功能的具体定义
void CMyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	uc1601("在类似这样的控件函数中定义自己要实现的功能，函数都是自己写",1);
	CDialog::OnOK();
}
