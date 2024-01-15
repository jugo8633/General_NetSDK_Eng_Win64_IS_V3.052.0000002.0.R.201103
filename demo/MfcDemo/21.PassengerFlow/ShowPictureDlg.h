#pragma once
#include "afxwin.h"
#include "PictureCtrl.h"


// CShowPictureDlg �Ի���

class CShowPictureDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowPictureDlg)

public:
	CShowPictureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowPictureDlg();

// �Ի�������
	enum { IDD = IDD_PICTURE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	PictureCtrl m_showPicture;

public:
	void ShowPicture(BYTE* data, DWORD size);
	afx_msg void OnStnClickedStaticShowpic();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
