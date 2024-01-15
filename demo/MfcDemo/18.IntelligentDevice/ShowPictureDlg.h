#pragma once

#include "PictureCtrl.h"
// CShowPictureDlg �Ի���

class CShowPictureDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowPictureDlg)

public:
	CShowPictureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowPictureDlg();

// �Ի�������
	enum { IDD = IDD_SHOWPIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	void ShowPicture(BYTE* data, DWORD size);
	afx_msg void OnStnClickedStaticShowpic();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

private:
	PictureCtrl m_showPicture;
};
