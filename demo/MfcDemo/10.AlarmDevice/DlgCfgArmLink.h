#include "afxwin.h"
#include "afxcmn.h"
#if !defined(AFX_DLGCFGARMLINK_H__347D68CE_E649_497F_BB6E_D82FFCA286E8__INCLUDED_)
#define AFX_DLGCFGARMLINK_H__347D68CE_E649_497F_BB6E_D82FFCA286E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



// DlgCfgArmLink �Ի���

class DlgCfgArmLink : public CDialog
{
	DECLARE_DYNAMIC(DlgCfgArmLink)

public:
	DlgCfgArmLink(CWnd* pParent = NULL, LLONG lLoginId = 0);   // ��׼���캯��
	virtual ~DlgCfgArmLink();

// �Ի�������
	enum { IDD = IDD_DLG_CFG_ARMLINK };


	CButton m_chkMMSEnable;
	CButton m_chkPersonAlarmEnable;
	CButton m_chkNeedReportEnable;
	CListCtrl m_lsNumberList;
	afx_msg void OnBnClickedBtnCfgarmlinkAddindex();
	afx_msg void OnBnClickedBtnCfgarmlinkDelindex();
	afx_msg void OnBnClickedBtnCfgarmlinkGet();
	afx_msg void OnBnClickedBtnCfgarmlinkSet();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	void InitDlg(BOOL bShow = TRUE);
	BOOL SetConfigToDevice();
	BOOL GetConfigFromDevice();
	void DlgToStu();
	void StuToDlg();

private:
	LLONG				m_lLoginId;
	CFG_ARMLINK_INFO	m_stuInfo;


};

#endif