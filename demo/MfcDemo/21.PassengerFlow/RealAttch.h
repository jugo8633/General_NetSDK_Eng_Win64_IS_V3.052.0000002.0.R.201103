#pragma once
#include "afxcmn.h"


// CRealAttch �Ի���

class CRealAttch : public CDialog
{
	DECLARE_DYNAMIC(CRealAttch)

public:
	CRealAttch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRealAttch();

// �Ի�������
	enum { IDD = IDD_REAL_ATTCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	static void CALLBACK VideoStatSumCallBackFunc(LLONG lAttachHandle, NET_VIDEOSTAT_SUMMARY* pBuf, DWORD dwBufLen, LDWORD dwUser);

public:
	void	InitRealAttchDlg(int nChannelNum, LLONG lLogind);
	void	SetChannelNum(int nChannel);
	void	ExitDlg();

private:
	void	InitCountingLct();
	void	VideoStatSummary(NET_VIDEOSTAT_SUMMARY* pSummaryInfo);

private:
	int		m_nChannel;
	LLONG	m_lLoginId;
	LLONG	m_lAttachID;

public:
	CListCtrl m_lctPeopleCounting;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonRealattach();
	afx_msg void OnBnClickedButtonRealdetach();
	

	LRESULT OnVideoSummaryCome(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
