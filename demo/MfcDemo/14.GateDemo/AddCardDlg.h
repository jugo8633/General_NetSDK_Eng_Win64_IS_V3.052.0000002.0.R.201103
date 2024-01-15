#pragma once
#include "afxwin.h"
#include "PictureCtrl.h"
#include "CardInfo.h"

// CAddCardDlg �Ի���

class CAddCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddCardDlg)

public:
	CAddCardDlg(LLONG lLoginId, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddCardDlg();

// �Ի�������
	enum { IDD = IDD_ADDCARD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	char	m_szFilePath[MAX_PIC_PATH];
	LLONG	m_lLoginID;
	tagCardInfo	m_StuAddCardInfo;

private:
	BOOL	InsertCardInfo();
	BOOL	InsertFaceInfo();

	BOOL	GetCardInfoFromUI();
	BOOL	IsFacePictureEmpty();

	void		SetDate(NET_TIME &stNetTime, int nID);
	void		SetTime(NET_TIME &stNetTime, int nID);

	void		InitControl();


public:
	virtual BOOL	PreTranslateMessage(MSG* pMsg);
	afx_msg void	OnBnClickedBtnAddOpenpic();
	PictureCtrl		m_addPic;
	afx_msg void OnBnClickedOk();
	CComboBox m_comboCardStatus;
	CComboBox m_comboCardType;
	CButton m_btnIsFirst;
	CButton m_btnEnable;
	virtual BOOL OnInitDialog();
};
