#include "afxwin.h"
#if !defined(_OPENDOORROUTE_)
#define _OPENDOORROUTE_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class OpenDoorRoute : public CDialog
{
	DECLARE_DYNAMIC(OpenDoorRoute)

public:
	OpenDoorRoute(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~OpenDoorRoute();

// �Ի�������
	enum { IDD = IDD_DIALOG_OPENDOORROUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOpendoorrouteButSet();
	afx_msg void OnBnClickedOpendoorrouteButGet();
	DECLARE_MESSAGE_MAP()
private:
	void InitDlg();
	void SetOpenDoorRouteInfoToCtrl();
	void GetOpenDoorRouteInfoFromCtrl();
	CFG_OPEN_DOOR_ROUTE_INFO	stuInfo;
};
#endif