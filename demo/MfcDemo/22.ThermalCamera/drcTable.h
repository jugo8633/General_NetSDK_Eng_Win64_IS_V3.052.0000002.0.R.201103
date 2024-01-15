#pragma once
//#ifdef DLL_IMPLEMENT
//#define DLL_API __declspec(dllexport)
//#else
//#define DLL_API __declspec(dllimport)
//#endif
//#define DLL_API
#ifndef _DRC_TABLE_H_
#define _DRC_TABLE_H_
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* ������  : drcTable
* ��  ��  : raw����ת����Y����
* ��  ��  : - pRaw: 14bit������
* ��  ��  : - height: ���������ݵĸ�
* ��  ��  : - width:  ���������ݵĿ�
* ��  ��  : - sel:  Ĭ����0
* ��  ��  : - lut:  ��selΪ1ʱ���ò���Ϊ����drc��Ĭ����0
* ��  ��  : pYData��ת�����Y����
* ����ֵ  : 0  : �ɹ�
*           -1: ʧ��
*******************************************************************************/
/*DLL_API*/ int /*__stdcall*/ drcTable(unsigned short *pRaw, unsigned short width, unsigned short height, int sel, unsigned char *pYData, unsigned short* lut);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif