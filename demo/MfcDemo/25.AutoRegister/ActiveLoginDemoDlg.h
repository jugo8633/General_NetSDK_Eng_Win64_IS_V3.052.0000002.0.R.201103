// ActiveLoginDemoDlg.h : header file
//

#if !defined(AFX_ACTIVELOGINDEMODLG_H__1DC33715_C83D_4B0B_97D9_D4FC6971F5CE__INCLUDED_)
#define AFX_ACTIVELOGINDEMODLG_H__1DC33715_C83D_4B0B_97D9_D4FC6971F5CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PtzScreen.h"
#include "dhmutex.h"
#include "ReadWriteExcel.h"
#include "PluginLogging.h"
#include "TreeCtrlEx.h"
#include "PTZControlDlg.h"
#include <list>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "afxcmn.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CActiveLoginDemoDlg dialog
#define NEW new(std::nothrow)
#define RGB_OnLine  RGB(55,217,104)
#define RGB_OFFLine RGB(0,0,0)
#define RGB_CHECKED RGB(255,0,0)

#define WM_DEVICE_DISCONNECTED		(WM_USER + 200)
#define WM_LOGINSUCCESS				(WM_USER + 201)
#define WM_LOGIN_DISCONNECTED		(WM_USER + 202)

#define MAX_ROW    1001
#define SET_NULL   ""	

#define	HAND	0
#define AUTO	1
typedef struct tagDH_DEVICE_INFO 
{
    CString             szDevSerial;   
    CString             szDevName;
    CString             szIP;
    int                 nPort;
    CString             szUseName;
    CString             szPassWord;
    int                 nLoginType;				 // 0��IP��¼1������ע���¼
    BOOL                nLoginStatus;            // �豸״̬��0:���� 1:�Ŷӵ�¼ 2:����
    int                 nLoginTimes;             // ���Ե�¼����
    LLONG               lLoginID;				 // ��¼���
    int                 nDeviceRow;              // �豸����Excel�к�
    CString             strSecDirName;           // ����Ŀ¼����
    int                 nChannelNum;             // �豸��������ͨ����
    HTREEITEM           srcRoot;                 // �豸����Ŀ¼�ľ��
    HTREEITEM           DstRoot;                 // �豸����ڵ�ľ��
    BOOL                bSort;                   // �Ƿ����Ź���
	BOOL				bOnTree;				 // �豸�Ƿ�������
}DH_DEVICE_INFO;

typedef struct tagDIR_NAME_NUMBER
{
    CString             strSecDirName;             // ����Ŀ¼����
    int                 nSecDirNumber;             // ����Ŀ¼����Excel�к�
    HTREEITEM           root;                      // �ڵ���
}DIR_NAME_NUMBER;

// Ϊÿ�����ŵĴ��ڱ����豸�����ͨ���ţ�������̨����
typedef struct tagVideoInfo						 
{
    LLONG       lLoginID;
    int         nChannel;
}VideoInfo;

// Ϊÿ�����ŵĴ��ڱ�����Ϣ�������豸���ع����Ӧ���ں��豸�ڵ�
typedef struct tagPlayHandle					  
{
    int                 nChannel;                  // ���ڲ��ŵ�ͨ����
    HTREEITEM           hParent;                   // ���ڵ���
    HTREEITEM           root;                      // �ڵ���
    BOOL                bPlay;                     // �ڵ��Ƿ��Ѳ���
	int					bFrameType;				   // ���ŵ���������
}PlayHandle;

// �豸������Ϣ
typedef struct tagDisConnectionInfo
{
	CString				strIp;
	int					nPort;
	LLONG				lLoginID;
}DisConnectionInfo;

class CActiveLoginDemoDlg : public CDialog
{
// Construction
public:
	CActiveLoginDemoDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CActiveLoginDemoDlg();
public:
    friend void CALLBACK  MessageProcFunc(int nWndID, UINT message, DWORD dwUser);
    friend BOOL CALLBACK  GetParamsFunc(int nWndID, int type, DWORD dwUser);
    friend void CALLBACK SetParamsFunc(int nWndID, int type, DWORD dwUser);
	friend void CALLBACK RectEventFunc(RECT WinRect,CPoint &pointStart,CPoint &pointEnd,DWORD dwUser);
// Dialog Data
	//{{AFX_DATA(CActiveLoginDemoDlg)
	enum { IDD = IDD_ACTIVELOGINDEMO_DIALOG };
	CStatic	m_StaticInfo;
	CComboBox	m_Cmb_Split;
	CComboBox	m_Cmb_ShowType;
	CTabCtrl	m_CtlTab;
	CIPAddressCtrl	m_LocalAddr;
	CTreeCtrlEx 	m_DevTree;
	int		m_LocalPort;
	CString	m_strSearch;
	BOOL m_bInitExcel;
	BOOL m_bSorted;
	int m_nShowType;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveLoginDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	//}}AFX_VIRTUAL
    afx_msg void OnTreeMenu(UINT nID);
    public:
    void    ReName(HTREEITEM root, CString strName);
// Implementation
public:
    CString m_strPath;                                  // Excel�ļ�·��
	CString m_strPDFPath;								// PDF�����ĵ�·��
    CString m_strRootName;                              // ��Ŀ¼����
    CPTZControlDlg m_PtzControlDlg;
    HANDLE                      m_hEvent;
	unsigned int dwThreadID;
    BOOL    m_bExit;
    BOOL    m_bSort;
	BOOL	m_bDirSort;
	BOOL	m_bSearch;
	BOOL	m_bDeleteDev;
    LLONG   m_lListenHdl;
    LLONG   m_lLoginID;
    int     m_nChannel;
    LLONG   m_DispHanle[9];
    PlayHandle  m_stuPlayInfo[9];
    VideoInfo   m_stuVideoInfo[9];
	void LoginThread();
	void login(DH_DEVICE_INFO* pInfo);
    void InitExcel();
    void Sort();
	void DirSort();
	void DeleteDev();
    HWND GetDispHandle();
    void DealListenCB(LLONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen);
	void DoEvent();
	void ClearRecourse();
	void Search();												// �����豸
	void DeleteEmptyDir(HTREEITEM root);						// ɾ���յĶ���Ŀ¼
	void DeleteDeviceDir(HTREEITEM root);						// ɾ���豸Ŀ¼
protected:
	HICON m_hIcon;
private:
    void UpdataScreenPos(void);
    void MessageProc(int nWndID, UINT message);
    BOOL GetParams(int nWndID, int type);
    void SetParams(int nWndID, int type);
    BOOL GetExitDecode(int nCurWndID);
    BOOL GetExitCycle(int nCurWndID);
    void SetExitDecode(int nCurWndID);
	void SetExitCycle(int nCurWndID);
    void SetFastGOTO(int nposX, int nposY, int nZoom);
    void InitTabCtrl();
	void FindItem(HTREEITEM hRoot,int ShowType);              // ���ҽڵ�
    int				m_CurScreen;
    CPtzScreen		m_ptzScreen;
    CRect			m_screenRect;
	CRect			m_clientRect;
	BOOL			m_bWndExitCycle[16];
private:
    DHMutex                     m_cs;
    HANDLE	            m_hThread;				
    std::list<DH_DEVICE_INFO*>	m_lstDeviceInfos;	/* �豸��Ϣ�б� */
    DHMutex						m_csDeviceInfos;

    std::list<DIR_NAME_NUMBER*> m_lstSecDirInfos;   // Ŀ¼��Ϣ
    DHMutex                     m_csSecDirInfos; 

    void GetLocalIPAndPort(char *pcIPAddr, int *pnPort);
    void InitDeviceInfo(int iCol,DH_DEVICE_INFO* stuDevice_Info, CString str);
    HTREEITEM Initdirectory(CString strSecDir, HTREEITEM root);           // nDirLevel:Ŀ¼�ȼ�,nSecDir:Ŀ¼���,strSecDir:Ŀ¼����,root:Ŀ¼��ʾ
private:
    DH_DEVICE_INFO* Find(HTREEITEM hRoot);          // ���ڵ�����豸��Ϣ
    std::vector<std::string> m_vecIDInfo;           // ID��Ϣ
    std::vector<std::string> m_vecIPInfo;           // IP��Ϣ
    std::vector<std::string> m_vecNameInfo;         // �豸������Ϣ

    std::map<CString,char> m_mapDirName;
    std::map<CString,char> m_mapDeviceID;
    void DeleteVector(std::vector<std::string>& vec,char* string);
	// Generated message map functions
	//{{AFX_MSG(CActiveLoginDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnStartserver();
	afx_msg void OnStopserver();
    afx_msg LRESULT OnDeviceDisconnected(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLoginSuccess(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLoginDisconnected(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClickDevtree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkDevtree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickDevtree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeComboShowtype();
	afx_msg void OnBtnSearch();
	afx_msg void OnBtnStopall();
	afx_msg void OnSelchangeCmbSplit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedHelp();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTIVELOGINDEMODLG_H__1DC33715_C83D_4B0B_97D9_D4FC6971F5CE__INCLUDED_)
