// Attendance.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAttendanceApp:
// �йش����ʵ�֣������ Attendance.cpp
//

class CAttendanceApp : public CWinApp
{
public:
	CAttendanceApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAttendanceApp theApp;