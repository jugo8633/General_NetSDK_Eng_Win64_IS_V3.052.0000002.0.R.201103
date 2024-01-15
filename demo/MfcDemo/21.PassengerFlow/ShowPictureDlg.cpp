// ShowPictureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PassengerFlow.h"
#include "ShowPictureDlg.h"


// CShowPictureDlg �Ի���

IMPLEMENT_DYNAMIC(CShowPictureDlg, CDialog)

CShowPictureDlg::CShowPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowPictureDlg::IDD, pParent)
{

}

CShowPictureDlg::~CShowPictureDlg()
{
}

void CShowPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PICTURE, m_showPicture);
}


BEGIN_MESSAGE_MAP(CShowPictureDlg, CDialog)
	ON_STN_CLICKED(IDC_STATIC_PICTURE, &CShowPictureDlg::OnStnClickedStaticShowpic)
END_MESSAGE_MAP()


// CShowPictureDlg ��Ϣ�������

void CShowPictureDlg::OnStnClickedStaticShowpic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(FALSE);
}


BOOL CShowPictureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	g_SetWndStaticText(this);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CShowPictureDlg::PreTranslateMessage(MSG* pMsg)
{
	// Enter key
	if(pMsg->message == WM_KEYDOWN &&
		pMsg->wParam == VK_RETURN)
	{
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CShowPictureDlg::ShowPicture(BYTE* data, DWORD size)
{
	m_showPicture.SetImageDate(data, size);
}