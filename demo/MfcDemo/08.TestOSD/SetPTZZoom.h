#pragma once


// CSetPTZZoom �Ի���

class CSetPTZZoom : public CDialog
{
	DECLARE_DYNAMIC(CSetPTZZoom)

public:
	CSetPTZZoom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetPTZZoom();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };
protected:
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGet();
	int m_nLeft; // [0, 8191]
	int m_nTop;  // [0, 8191]
	int m_nTime;
	BOOL m_bMainBlend;
	BOOL m_bPreviewBlend;
	NET_OSD_PTZZOOM_INFO m_stuPTZZoom;
	afx_msg void OnBnClickedSet();
};
