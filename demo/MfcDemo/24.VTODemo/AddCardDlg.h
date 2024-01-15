#pragma once


// CAddCardDlg �Ի���
#include "afxwin.h"
#include "PictureCtrl.h"
#include "CardInfo.h"
#include "CMyListCtl.h"

#define MAX_PIC_PATH 512

typedef enum tagEM_Operate
{
	EM_Operate_add,
	EM_Operate_modify,
}EM_Operate;


class CAddCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddCardDlg)

public:
	CAddCardDlg(LLONG lLoginID, EM_Operate em_Operate, CardInfo& cardinfo, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddCardDlg();

// �Ի�������
	enum { IDD = IDD_ADDCARD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnGet();
	afx_msg void OnBnClickedBtnOpenpicture();

private:
	LLONG	m_lLoginID;

	CardInfo	m_stuCardInfo;
	char		m_szFilePath[MAX_PIC_PATH];
	char		m_byFingerprintData[6*1024];
	int			m_nFingerprintLen;
	EM_Operate  m_emOperate;

	PictureCtrl		m_addPic;

public:
		virtual BOOL OnInitDialog();
		BOOL GetCardInfoFromUI();
		BOOL AddModifyCard();
		BOOL ModifyCardInfo();
		BOOL InsertCardInfo();
		BOOL isCardEmpty();
		BOOL DeleteCardByRecNo(int nRecNo);
		virtual BOOL PreTranslateMessage(MSG* pMsg);
};
