// TestOSD.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


void g_SetWndStaticText(CWnd * pWnd);
CString ConvertString(CString strText);
void g_SetWndStaticText(CWnd * pWnd);
// CTestOSDApp:
// �йش����ʵ�֣������ TestOSD.cpp
//

class CTestOSDApp : public CWinApp
{
public:
	CTestOSDApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestOSDApp theApp;