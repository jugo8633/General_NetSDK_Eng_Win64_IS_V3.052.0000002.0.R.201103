// VTODemoDlg.h : ͷ�ļ�
//

#pragma once

#include <afxmt.h>
#include <afxtempl.h>

// CVTODemoDlg �Ի���
class CVTODemoDlg : public CDialog
{
// ����
public:
	CVTODemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VTODEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void DealAudioData(LLONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag);

private:
	BOOL InitSDK();
	void ResetDlg();

	BOOL StartAttach();
	BOOL StopAttach();
	void CloseAttchHandle();
	LRESULT OnMessCallback(WPARAM wParam, LPARAM lParam);
	BOOL DealWithAlarmEvent(LONG lCommand, char *pBuf, DWORD dwBufLen);
	void UpdateAccessControlListCtrl();
	CString EmOpenMethodToCString(NET_ACCESS_DOOROPEN_METHOD  emOpenMethod);
	void GetZoneTime(NET_TIME& netTime);


	LLONG StartPreview(const HWND& hWnd);
	BOOL StopPreview();
	void ClosePreviewHandle();

	BOOL StartTalk();
	BOOL StopTalk();
	void CloseTalkHandle();

	void CloseLoginHandle();

public:
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnLogout();
	afx_msg void OnBnClickedBtnStartpreview();
	afx_msg void OnBnClickedBtnStoppreview();
	afx_msg void OnBnClickedBtnAttach();
	afx_msg void OnBnClickedBtnDettach();
	afx_msg void OnBnClickedBtnStarttalk();
	afx_msg void OnBnClickedBtnStoptalk();
	afx_msg void OnBnClickedBtnOpendoor();
	afx_msg void OnBnClickedBtnCardmanager();

private:
	LLONG	m_lLoginID;
	LLONG	m_lTalkID;
	LLONG	m_lPreviewID;
	
	int		m_nChannelNum;
	int		m_nChannelIndex;

	CListCtrl m_listCtrlAlarm;

	CCriticalSection m_csAccessControl;
	CList<ALARM_ACCESS_CTL_EVENT_INFO, ALARM_ACCESS_CTL_EVENT_INFO&> m_listAccessControlInfo;
public:
	afx_msg void OnDestroy();
};
