//
//  "$Id$"
//
//  Copyright (c)1992-2007, ZheJiang Dahua Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __DAHUA_BASE64_ORDER_H__
#define __DAHUA_BASE64_ORDER_H__

/// �����ű�������ݵĻ������ֽ���
int base64EncodeLen(int len);

/// Base64 ����
/// \param [in] dst ��ű������ı�����
/// \param [in] src ����ǰ�����ݻ���
/// \param [in] len ����ǰ�������ֽ���
/// \return ���ر������ı��ֽ���, �������ַ���������
int  base64Encode(char* dst, const char* src, int len);

/// �����Ž�������ݵĻ������ֽ���
int  base64DecodeLen(const char* src);

bool base64Encode(const char *src, int len, CString &strDst);

/// Base64 ����
/// \param [in] dst ����ǰ���ı�����
/// \param [in] src ���������ݻ���
/// \return ���ؽ����������ֽ���
int base64Decode(char* dst, const char* src);


#endif// __DAHUA_BASE64_ORDER_H__


