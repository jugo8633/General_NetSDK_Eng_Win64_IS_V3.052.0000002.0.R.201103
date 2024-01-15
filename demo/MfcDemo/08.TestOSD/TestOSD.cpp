// TestOSD.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "TestOSD.h"
#include "TestOSDDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestOSDApp

BEGIN_MESSAGE_MAP(CTestOSDApp, CWinApp)
	ON_COMMAND(ID_HELP, OnHelp)
END_MESSAGE_MAP()


//Set static text in the dialogue box(English->current language) 
void g_SetWndStaticText(CWnd * pWnd)
{
	CString strCaption,strText;
	
	//Set main window title 
	pWnd->GetWindowText(strCaption);
	if(strCaption.GetLength()>0)
	{
		strText=ConvertString(strCaption);
		pWnd->SetWindowText(strText);
	}
	
	//Set sub-window title 
	CWnd * pChild=pWnd->GetWindow(GW_CHILD);
	CString strClassName;
	while(pChild)
	{
		//////////////////////////////////////////////////////////////////////////		
		//Added by Jackbin 2005-03-11
		strClassName = ((CRuntimeClass*)pChild->GetRuntimeClass())->m_lpszClassName;
		if(strClassName == "CEdit")
		{
			//The next sub-window 
			pChild=pChild->GetWindow(GW_HWNDNEXT);
			continue;
		}
		
		//////////////////////////////////////////////////////////////////////////	
		
		//Set current language text in the sub-window 
		pChild->GetWindowText(strCaption);
		strText=ConvertString(strCaption);
		pChild->SetWindowText(strText);
		
		//The next sub-window 
		pChild=pChild->GetWindow(GW_HWNDNEXT);
	}
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

CString ConvertString(CString strText)
{
    char *val = new char[200];
    CString strIniPath,strRet;
    
    memset(val,0,200);
    GetPrivateProfileString("String",strText,"",
        val,200,"./langchn.ini");
    strRet = val;
    if(strRet.GetLength()==0)
    {
        //If there is no corresponding string in ini file then set it to be default value(English)
        strRet=strText;
    }
    delete val;
    return strRet;
}

// CTestOSDApp ����

CTestOSDApp::CTestOSDApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTestOSDApp ����

CTestOSDApp theApp;


// CTestOSDApp ��ʼ��

BOOL CTestOSDApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CTestOSDDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
