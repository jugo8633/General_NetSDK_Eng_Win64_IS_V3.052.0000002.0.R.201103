#pragma once

typedef enum tagEM_USER_OPERATOR_TYPE
{
	EM_USER_OPERATOR_TYPE_UNKNOWN,
	EM_USER_OPERATOR_TYPE_ADD,
	EM_USER_OPERATOR_TYPE_MODIFY,
}EM_USER_OPERATOR_TYPE;

// CUserDetailDlg �Ի���
class CAttendanceManager;
class CUserDetailDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDetailDlg)

public:
	CUserDetailDlg(CAttendanceManager *pManager, CString strUserID, CString strUserName, CString strCardNo, 
		EM_USER_OPERATOR_TYPE type, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserDetailDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_USERDETAil };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CAttendanceManager *m_pManager;
	CString m_strUserDetail_userid;
	CString m_struserdetail_username;
	CString m_struserdetail_cardno;
	EM_USER_OPERATOR_TYPE m_type;
public:
	afx_msg void OnBnClickedButtonUserdetail();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
