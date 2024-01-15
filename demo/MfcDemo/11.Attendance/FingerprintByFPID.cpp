// FingerprintByFPID.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Attendance.h"
#include "FingerprintByFPID.h"
#include "Util.h"
#include "Base64.h"

// CFingerprintByFPID �Ի���

IMPLEMENT_DYNAMIC(CFingerprintByFPID, CDialog)

CFingerprintByFPID::CFingerprintByFPID(CAttendanceManager *pManager, CWnd* pParent /*=NULL*/)
	: CDialog(CFingerprintByFPID::IDD, pParent)
	, m_strUserID(_T(""))
	, m_strFingerID(_T(""))
{
	m_pManager = pManager;
}

CFingerprintByFPID::~CFingerprintByFPID()
{
}

void CFingerprintByFPID::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHOW_USERID, m_strUserID);
	DDX_Text(pDX, IDC_EDIT_FINGERPRINT_ID, m_strFingerID);
}


BEGIN_MESSAGE_MAP(CFingerprintByFPID, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_GETBYFINGERPRINTID, &CFingerprintByFPID::OnBnClickedButtonGetbyfingerprintid)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_BY_FINGERPRINTID, &CFingerprintByFPID::OnBnClickedButtonDeleteByFingerprintid)
END_MESSAGE_MAP()


// CFingerprintByFPID ��Ϣ�������

void CFingerprintByFPID::OnBnClickedButtonGetbyfingerprintid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT_SHOW_USERID, "");
	SetDlgItemText(IDC_EDIT_FINGERPRINT_DATA, "");
	UpdateData(TRUE);

	if (m_strFingerID == "")
	{
		MessageBox(ConvertString("Please input fingerprint ID"), ConvertString("Prompt"));
		return ;
	}

	NET_CTRL_IN_FINGERPRINT_GET stuInGet ={sizeof(stuInGet)};
	int nFingerprintID = atoi(m_strFingerID);
	stuInGet.nFingerPrintID = nFingerprintID;
	NET_CTRL_OUT_FINGERPRINT_GET stuOutGet = {sizeof(stuOutGet)};
	stuOutGet.szFingerPrintInfo = new char[100*1024];
	stuOutGet.nMaxFingerDataLength = 100*1024;
	bool bRet = m_pManager->GetFingerRecord(&stuInGet, &stuOutGet);
	if (bRet)
	{
		if (0 == stuOutGet.nRetLength)
		{
			MessageBox(ConvertString("No fingerprint data"), ConvertString("Prompt"));
		}
		else
		{
			m_strUserID = stuOutGet.szUserID;
			CString strFinger = "";
			base64Encode(stuOutGet.szFingerPrintInfo, stuOutGet.nRetLength, strFinger);
			SetDlgItemText(IDC_EDIT_FINGERPRINT_DATA, strFinger);
			UpdateData(FALSE);
		}
	}
	else
	{
		MessageBox(ConvertString("Search Failed"), ConvertString("Prompt"));
	}
	delete []stuOutGet.szFingerPrintInfo;
	stuOutGet.szFingerPrintInfo = NULL;
}

BOOL CFingerprintByFPID::OnInitDialog()
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this);


	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CFingerprintByFPID::OnBnClickedButtonDeleteByFingerprintid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if (m_strFingerID == "")
	{
		MessageBox(ConvertString("Please input fingerprint ID"), ConvertString("Prompt"));
		return ;
	}

	NET_CTRL_IN_FINGERPRINT_REMOVE stuInRemove ={sizeof(stuInRemove)};
	int nFingerprintID = atoi(m_strFingerID);
	stuInRemove.nFingerPrintID = nFingerprintID;
	NET_CTRL_OUT_FINGERPRINT_REMOVE stuOutRemove ={sizeof(stuOutRemove)};
	bool bRet = m_pManager->RemoveFingerRecord(&stuInRemove, &stuOutRemove);
	if (bRet)
	{
		MessageBox(ConvertString("Delete fingerprint Successfully"), ConvertString("Prompt"));
	}
	else
	{
		MessageBox(ConvertString("Delete fingerprint Failed"), ConvertString("Prompt"));
	}
}

BOOL CFingerprintByFPID::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (WM_KEYDOWN == pMsg->message)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:
		case VK_ESCAPE:
			return true;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
