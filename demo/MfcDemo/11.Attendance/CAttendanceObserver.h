#ifndef _ATTENDANCE_OBSERVER_H_
#define _ATTENDANCE_OBSERVER_H_
#include  "./include/dhnetsdk.h"

typedef enum tagATTENDANCE_MSG_TYPE
{
	ATTENDANCE_MSG_TYPE_UNKNOWN,             // δ֪
	ATTENDANCE_MSG_TYPE_IVS_ACCESS_CTL,      // �����Ž��¼�  ��Ӧ�ṹ��DEV_EVENT_ACCESS_CTL_INFO
}ATTENDANCE_MSG_TYPE;

//�۲���  �����˭������Ϣ����Ҫ�̳������
class CAttendanceObserver
{
public:
	CAttendanceObserver();
	virtual ~CAttendanceObserver();

	// ���½ӿ�  
	/*
		msgType           ��Ϣ����
		void *pMsgInfo    ��Ϣ��Ӧ�ṹ��
		BYTE *pBuffer     ͼƬ���ݵȣ�����Ϊ��
		DWORD dwBufSize   buffer��С�����ܲ���
	*/
	virtual int updateAttendanceInfo(ATTENDANCE_MSG_TYPE msgType, void *pMsgInfo, BYTE *pBuffer, DWORD dwBufSize);
};



#endif