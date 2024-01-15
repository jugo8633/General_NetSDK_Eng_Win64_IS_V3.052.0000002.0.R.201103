#ifndef _DEMO_SPEAK_UTIL_H_
#define _DEMO_SPEAK_UTIL_H_

#pragma warning(disable: 4786)
#include <map>
#include <vector>
#include <list>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

#include "include/dhnetsdk.h"

#ifdef _WIN64
#pragma comment(lib, "lib/Win64/dhnetsdk.lib")
#else
#pragma comment(lib, "lib/Win32/dhnetsdk.lib")
#endif

#define DEFAULT_WAIT_TIME 5000

#define WM_SPEAK_STATUS      WM_USER + 1

#define		FACE_PERSON_ADD		0X000001
#define		FACE_PERSON_EDIT	0X000002

#ifndef _countof
#define _countof(array)		sizeof(array) / sizeof(array[0])
#endif

#define	MAX_CAMERAS_COUNT	512
#define PERPAGE_INDEX_COUNT	10	
#define	GROUP_ID_NUM		64
#define FACE_MAX_PATH_LEN	512

CString ConvertString(CString strText);

const COLORREF RESERVED_COLOR = RGB(255, 255, 255);

void g_SetWndStaticText(CWnd * pWnd);
void	FillCWndWithDefaultColor(CWnd* cwnd);

#endif