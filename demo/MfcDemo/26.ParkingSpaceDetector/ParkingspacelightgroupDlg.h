#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// ParkingspacelightgroupDlg �Ի���

class CController;
class ParkingspacelightgroupDlg : public CDialog
{
	DECLARE_DYNAMIC(ParkingspacelightgroupDlg)

public:
	ParkingspacelightgroupDlg(CController* pCtl, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ParkingspacelightgroupDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_PARKINGSPACELIGHTGROUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonGet();
	afx_msg void OnBnClickedButtonSet();
	CListCtrl m_listLightGroup;
	afx_msg void OnNMDblclkListLightgroupList(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_edit;
	afx_msg void OnEnKillfocusEdit2();

private:
	void	InitControl();		//��ʼ������
	void	getConfig();		//��ȡ����
	void	setConfig();		//�·�����

	void	getDataFromControl();	//�ӿؼ���ȡ����
	void	showDataToControl();	//��������ʾ���ؼ���

private:
	int										m_row;
	int										m_column;
	CController*							m_pCtl;

	int										m_nCfgNum;
	int										m_nLanesNum;
	CFG_PARKING_SPACE_LIGHT_GROUP_INFO_ALL	m_stuInfo;

};
