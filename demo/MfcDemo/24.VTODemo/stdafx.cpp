// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// VTODemo.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

#if defined(_WIN64)

#pragma comment(lib, "./lib/win64/dhconfigsdk.lib")
#pragma comment(lib, "./lib/win64/dhnetsdk.lib")
#else
#pragma comment(lib,"./lib/win32/dhconfigsdk.lib")
#pragma comment(lib,"./lib/win32/dhnetsdk.lib")
#endif