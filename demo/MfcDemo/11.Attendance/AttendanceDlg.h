// AttendanceDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "CAttendanceObserver.h"

class CAttendanceManager;

// CAttendanceDlg �Ի���
class CAttendanceDlg : public CDialog, CAttendanceObserver
{
// ����
public:
	CAttendanceDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ATTENDANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
	virtual int updateAttendanceInfo(ATTENDANCE_MSG_TYPE msgType, void *pMsgInfo, BYTE *pBuffer, DWORD dwBufSize);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnAccessCtlEvent(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_listCtlUserInfo;
	afx_msg void OnLvnItemchangedListUserInfo(NMHDR *pNMHDR, LRESULT *pResult);
	int InitUserListCtl(void);
	CListCtrl m_EventListCtl;
	int InitEventListCtl(void);
	CIPAddressCtrl m_ipCtrl;
	afx_msg void OnBnClickedButtonLogin();
	int m_nPort;
	CString m_strLoginUser;
	CString m_strLoginPasswd;
	bool m_bLogined;   //�Ƿ��Ѿ���½����
	bool m_bSubscribed;  //�Ƿ��Ĺ���
	int initLoginParam(void);
	CAttendanceManager *m_pAttendanceManager;
public:
	afx_msg void OnDestroy();
private:
	void ShowLoginErrorReason(int nerror);
	void UpdateUserList(void *pUserList, int nUserCount, int nTotalCount, bool bUpdateTotalCount);
public:
	afx_msg void OnBnClickedButtonAdduser();
private:
	int EnableButtons(bool bEnable);
public:
	afx_msg void OnBnClickedButtonModifyuser();
	afx_msg void OnBnClickedButtonDeleteuser();
	afx_msg void OnBnClickedButtonGetuser();
	afx_msg void OnBnClickedEditSubscribe();
	afx_msg void OnBnClickedButtonFinduser();
private:
	int m_nOffset;
	int m_nQueryCount;
	int m_nTotal;
	CString m_strGetUser_USERID;
	int m_nEventIndex;
	void RefreshUI(void);
	int m_nFindUserCount;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonOperateFingerprintByuserid();
	afx_msg void OnBnClickedButtonOperateFingerprintByfpid();
};
