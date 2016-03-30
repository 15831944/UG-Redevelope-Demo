// 添加头文件
#include "stdafx.h"
#include "TestProgram.h"
#include "MyDlg.h"

#include <uf.h>
#include <uf_exit.h>
#include <uf_ui.h>
#include <uf_mb.h>

// 一些宏定义
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 函数声明
void CreateFaceAttrFun();	// 创建面属性的函数

//////////////////////////////////////////////////////////////////////////程序创建文件，不用管
BEGIN_MESSAGE_MAP(CTestProgramApp, CWinApp)
END_MESSAGE_MAP()

// CTestProgramApp 构造

CTestProgramApp::CTestProgramApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CTestProgramApp 对象
CTestProgramApp theApp;

// CTestProgramApp 初始化
BOOL CTestProgramApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
//////////////////////////////////////////////////////////////////////////程序创建文件，不用管

// 菜单行为函数声明
UF_MB_cb_status_t CreateAttr(UF_MB_widget_t w, UF_MB_data_t client_data,  UF_MB_activated_button_p_t button);

// 菜单行为表具体定义，注册菜单
static UF_MB_action_t action_table[]=
{
	{ "CreateFaceAttr", CreateAttr,NULL },	// 菜单行为定义，每个{}代表一个菜单命令，多添加多个
	{ NULL,NULL,NULL}
};

// 菜单行为函数定义：具体实现
UF_MB_cb_status_t CreateAttr(UF_MB_widget_t w, UF_MB_data_t client_data,  UF_MB_activated_button_p_t button)
{
	CreateFaceAttrFun();	// 具体执行什么函数
	return UF_MB_CB_CONTINUE;	// 菜单行为函数返回值
}

// 创建属性的具体实现，函数命名，每个单词首字母大写，同时尽量命名是有意义的，缩写
void CreateFaceAttrFun()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CMyDlg myDlg;	// 声明对话框，变量一般第一个单词的字母小写，往后的单词首字母大写
	myDlg.DoModal();	// 调出对话框
}

// 入口主函数
extern DllExport void ufsta( char *param, int *returnCode, int rlen )
{
	// 初始化
	int errorCode = UF_initialize();

	if ( 0 == errorCode )
	{
		// 调用菜单行为表
		UF_MB_add_actions(action_table);

		// 一些报错信息
		errorCode = UF_terminate();
	}
}

// 卸载函数
extern int ufusr_ask_unload( void )
{
	return( UF_UNLOAD_SEL_DIALOG );
}