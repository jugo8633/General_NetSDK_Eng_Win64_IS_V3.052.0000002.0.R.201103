#pragma once

struct tagCardInfo
{
	char	szCardNo[DH_MAX_CARDNO_LEN];
	char	szUserID[DH_MAX_USERID_LEN];
	char	szCardName[DH_MAX_CARDNAME_LEN];
	char	szPsw[DH_MAX_CARDPWD_LEN];
	int		nRecNo;

	NET_ACCESSCTLCARD_STATE			emStatus;				// ��״̬
	NET_ACCESSCTLCARD_TYPE			emType;					// ������
	int								nUserTime;				// ʹ�ô���
	BOOL							bFirstEnter;            // �Ƿ�ӵ���׿�Ȩ��
	BOOL							bIsValid;               // �Ƿ���Ч,TRUE��Ч;FALSE��Ч

	NET_TIME        stuValidStartTime;                      // ��ʼ��Ч��, �豸�ݲ�֧��ʱ����
	NET_TIME        stuValidEndTime;                        // ������Ч��, �豸�ݲ�֧��ʱ����
};
