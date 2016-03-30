// ���ͷ�ļ�
#include "stdafx.h"
#include "TestProgram.h"
#include "MyDlg.h"

#include <uf.h>
#include <uf_exit.h>
#include <uf_ui.h>
#include <uf_mb.h>

// һЩ�궨��
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ��������
void CreateFaceAttrFun();	// ���������Եĺ���

//////////////////////////////////////////////////////////////////////////���򴴽��ļ������ù�
BEGIN_MESSAGE_MAP(CTestProgramApp, CWinApp)
END_MESSAGE_MAP()

// CTestProgramApp ����

CTestProgramApp::CTestProgramApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CTestProgramApp ����
CTestProgramApp theApp;

// CTestProgramApp ��ʼ��
BOOL CTestProgramApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
//////////////////////////////////////////////////////////////////////////���򴴽��ļ������ù�

// �˵���Ϊ��������
UF_MB_cb_status_t CreateAttr(UF_MB_widget_t w, UF_MB_data_t client_data,  UF_MB_activated_button_p_t button);

// �˵���Ϊ����嶨�壬ע��˵�
static UF_MB_action_t action_table[]=
{
	{ "CreateFaceAttr", CreateAttr,NULL },	// �˵���Ϊ���壬ÿ��{}����һ���˵��������Ӷ��
	{ NULL,NULL,NULL}
};

// �˵���Ϊ�������壺����ʵ��
UF_MB_cb_status_t CreateAttr(UF_MB_widget_t w, UF_MB_data_t client_data,  UF_MB_activated_button_p_t button)
{
	CreateFaceAttrFun();	// ����ִ��ʲô����
	return UF_MB_CB_CONTINUE;	// �˵���Ϊ��������ֵ
}

// �������Եľ���ʵ�֣�����������ÿ����������ĸ��д��ͬʱ����������������ģ���д
void CreateFaceAttrFun()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CMyDlg myDlg;	// �����Ի��򣬱���һ���һ�����ʵ���ĸСд������ĵ�������ĸ��д
	myDlg.DoModal();	// �����Ի���
}

// ���������
extern DllExport void ufsta( char *param, int *returnCode, int rlen )
{
	// ��ʼ��
	int errorCode = UF_initialize();

	if ( 0 == errorCode )
	{
		// ���ò˵���Ϊ��
		UF_MB_add_actions(action_table);

		// һЩ������Ϣ
		errorCode = UF_terminate();
	}
}

// ж�غ���
extern int ufusr_ask_unload( void )
{
	return( UF_UNLOAD_SEL_DIALOG );
}