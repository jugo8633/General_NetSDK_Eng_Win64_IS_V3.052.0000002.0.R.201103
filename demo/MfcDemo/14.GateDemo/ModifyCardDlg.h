#pragma once
#include "afxwin.h"
#include "PictureCtrl.h"
#include "CardInfo.h"


// CModifyCardDlg �Ի���

class CModifyCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CModifyCardDlg)

public:
	CModifyCardDlg(LLONG lLoginId, const tagCardInfo& CardInfo, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModifyCardDlg();

// �Ի�������
	enum { IDD = IDD_MODIFYCARD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtn();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

private:
	BOOL		GetCardInfoFromUI();

	void		SetData(NET_TIME &stNetTime, int nID);
	void		SetTime(NET_TIME &stNetTime, int nID);

	void		InitControl();

	BOOL		ModifyCardInfo();
	BOOL		ModifyFaceInfo();
	void		SetCardInfoToUI();
	void		SetDateToUI(int nID);
	void		SetTimeToUI(int nID);

private:
	char		m_szFilePath[MAX_PIC_PATH];
	tagCardInfo m_CardInfo;
	LLONG		m_lLoginID;
	PictureCtrl m_modifyPic;


	CComboBox m_cbxCardStatus;
	CComboBox m_cbxCardType;
	CButton m_btnEnable;
	CButton m_btnIsFirst;
};
