// CardManager.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VTODemo.h"
//#include "CardManager.h"


// CCardManager �Ի���

IMPLEMENT_DYNAMIC(CCardManager, CDialog)

CCardManager::CCardManager(CWnd* pParent /*=NULL*/)
	: CDialog(CCardManager::IDD, pParent)
{

}

CCardManager::~CCardManager()
{
}

void CCardManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCardManager, CDialog)
END_MESSAGE_MAP()


// CCardManager ��Ϣ�������
