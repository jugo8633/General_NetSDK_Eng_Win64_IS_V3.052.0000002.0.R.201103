#if !defined(AFX_PREVIEWPARMSDLG_H__5B0E1DAD_D44D_4748_A668_E3E4E9271246__INCLUDED_)
#define AFX_PREVIEWPARMSDLG_H__5B0E1DAD_D44D_4748_A668_E3E4E9271246__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreviewParmsDlg.h : header file
//


typedef struct tagDemoRealPlayType 
{
    const char*     szType;
    DH_RealPlayType emType;         // CLIENT_RealPlayEx��Ӧ�Ķ໭��Ԥ������
    DH_SPLIT_MODE   emSplitMode;    // CLIENT_SetSplitMode��Ӧ�Ķ໭��ָ�ģʽ
}DemoRealPlayType;

const DemoRealPlayType stuRealPlayType[] = {
    {"Multiplay",       DH_RType_Multiplay,     (DH_SPLIT_MODE)0},
    {"Multiplay-1",     DH_RType_Multiplay_1,   DH_SPLIT_1},
    {"Multiplay-4",     DH_RType_Multiplay_4,   DH_SPLIT_4},
    {"Multiplay-6",     DH_RType_Multiplay_6,   DH_SPLIT_6},
    {"Multiplay-8",     DH_RType_Multiplay_8,   DH_SPLIT_8},
    {"Multiplay-9",     DH_RType_Multiplay_9,   DH_SPLIT_9},
    {"Multiplay-16",    DH_RType_Multiplay_16,  DH_SPLIT_16},
    {"Multiplay-25",    DH_RType_Multiplay_25,  DH_SPLIT_25},
    {"Multiplay-36",    DH_RType_Multiplay_36,  DH_SPLIT_36},
};

/////////////////////////////////////////////////////////////////////////////
// CPreviewParmsDlg dialog

class CPreviewParmsDlg : public CDialog
{
private:
    // �豸��Ϣ
    DeviceNode          m_stuDevInfo;
    // �໭��Ԥ������ģʽ
    CFG_EM_PREVIEW_MODE m_emPreviewMode;
    // �໭��Ԥ��ģʽ
    DH_RealPlayType     m_emRealPlayType;

public:
    const int&              GetStartChannel() const { return m_channelId; }
    const DH_RealPlayType&  GetRealPlayType() const { return m_emRealPlayType; }
    
protected:
    // ��ʼ�����ڽ���ؼ�
    void                InitDlg();
    // ��ʼ���໭��Ԥ����ؿؼ�����ͬģʽ��Ӧ��ͬѡ����ŵ�
    void                InitCommbo(UINT uiVideoIn, const CFG_ENCODECAP& stuEncodeCap);
    // ��ȡ�豸�Ķ໭��Ԥ������
    BOOL                GetEncodeCaps(CFG_ENCODECAP& stuEncodeCap);

// Construction
public:
	CPreviewParmsDlg(CWnd* pParent = NULL, DeviceNode* pstuDevInfo = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreviewParmsDlg)
	enum { IDD = IDD_PREVIEW_PARM };
	CComboBox	m_cmbSplitNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreviewParmsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreviewParmsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:	
	int m_channelId;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEWPARMSDLG_H__5B0E1DAD_D44D_4748_A668_E3E4E9271246__INCLUDED_)
