// TestProgram.h : TestProgram DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestProgramApp
// �йش���ʵ�ֵ���Ϣ������� TestProgram.cpp
//

class CTestProgramApp : public CWinApp
{
public:
	CTestProgramApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
