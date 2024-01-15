#pragma once
#include "AttendanceManager.h"
#include "afxwin.h"
// CFingerprintByFPID �Ի���

class CFingerprintByFPID : public CDialog
{
	DECLARE_DYNAMIC(CFingerprintByFPID)

public:
	CFingerprintByFPID(CAttendanceManager *pManager, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFingerprintByFPID();

// �Ի�������
	enum { IDD = IDD_DIALOG_OPERATE_FINGER_BY_FINGERID };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGetbyfingerprintid();
	virtual BOOL OnInitDialog();
private:
	CAttendanceManager *m_pManager;
	CString m_strUserID;
public:
	afx_msg void OnBnClickedButtonDeleteByFingerprintid();
private:
	CEdit m_Edit_FingerprintData;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	CString m_strFingerID;
};
