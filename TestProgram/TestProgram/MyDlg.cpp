// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestProgram.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include <uf_ui.h>

// CMyDlg �Ի���

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


// CMyDlg ��Ϣ�������

// ��ťʵ�ֹ��ܵľ��嶨��
void CMyDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	uc1601("�����������Ŀؼ������ж����Լ�Ҫʵ�ֵĹ��ܣ����������Լ�д",1);
	CDialog::OnOK();
}
