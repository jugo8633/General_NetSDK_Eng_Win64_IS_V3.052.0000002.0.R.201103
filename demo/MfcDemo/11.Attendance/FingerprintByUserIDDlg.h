#pragma once
#include "afxcmn.h"
#include "AttendanceManager.h"
#include "CMyListCtl.h"

// CFingerprintByUserIDDlg �Ի���

class CFingerprintByUserIDDlg : public CDialog
{
	DECLARE_DYNAMIC(CFingerprintByUserIDDlg)

public:
	CFingerprintByUserIDDlg(CAttendanceManager *pManager, CString szUserID, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFingerprintByUserIDDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_OPERATE_FINGER_BY_USERID };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	CMyListCtl m_lstFingerprint;
	CAttendanceManager *m_pManager;
public:
	afx_msg void OnBnClickedButtonSearchByuserid();
	afx_msg void OnBnClickedButtonAddFingerByUserid();
	afx_msg void OnBnClickedButtonDeleteFingerByUserid();
private:
	CString m_strUserID;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnPaint();
};
