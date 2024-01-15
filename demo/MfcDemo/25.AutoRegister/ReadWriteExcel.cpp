// ReadWriteExcel.cpp: implementation of the CReadWriteExcel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ActiveLoginDemo.h"
#include "ReadWriteExcel.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CReadWriteExcel::CReadWriteExcel()
{
    m_lpDisp = NULL;
}

CReadWriteExcel::~CReadWriteExcel()
{
    COleVariant
        covTrue((short)TRUE),
        covFalse((short)FALSE),
        covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
    m_book.Close(covTrue,COleVariant(m_strFilePath),covOptional);
    m_range.ReleaseDispatch();
    m_sheet.ReleaseDispatch();
    m_sheets.ReleaseDispatch();
    m_book.ReleaseDispatch();
    m_books.ReleaseDispatch();  
    m_excelapp.Quit();
    m_excelapp.ReleaseDispatch();
}

BOOL CReadWriteExcel::SetFilePath(CString strPath)
{
    CFileFind Finder;
    BOOL bFind = Finder.FindFile(strPath);
    if (!bFind)
    {
        return FALSE;
    }
	HANDLE hHandle = CreateFile(strPath, FILE_ALL_ACCESS, FILE_SHARE_READ,NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hHandle == INVALID_HANDLE_VALUE)
	{
		HRESULT hr = GetLastError();
		if (hr == ERROR_ACCESS_DENIED || hr == ERROR_SHARING_VIOLATION)
		{
			return FALSE;
		}
	}
	else
	{
		CloseHandle(hHandle);
	}
    COleVariant
        covTrue((short)TRUE),
        covFalse((short)FALSE),
        covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
    if(!m_excelapp.CreateDispatch("Excel.Application"))
    {
        return FALSE;
    }
    m_strFilePath = strPath;
    m_books.AttachDispatch(m_excelapp.GetWorkbooks());
    m_lpDisp = m_books.Open(strPath,     
        covOptional, covOptional, covOptional, covOptional, covOptional,
        covOptional, covOptional, covOptional, covOptional, covOptional,
        covOptional, covOptional, covOptional,covOptional);
    m_book.AttachDispatch(m_lpDisp);
    m_sheets.AttachDispatch(m_book.GetWorksheets());
    return TRUE;
}
void CReadWriteExcel::SetUseRange(int iSheet)
{
    m_sheet = m_sheets.GetItem(COleVariant((short)iSheet));  //  ��ȡ׼����ȡ��sheet
    //��ȡ�Ѿ�ʹ���������Ϣ�������Ѿ�ʹ�õ���������������ʼ�С���ʼ��
    m_usedRange.AttachDispatch(m_sheet.GetUsedRange());      //��ȡ�Ѿ�ʹ���������Ϣ
	m_range.AttachDispatch(m_sheet.GetCells());
}
CString CReadWriteExcel::GetCellString(int iRow,int iCol)
{
    COleVariant m_vResult;
    //��ȡ��Ԫ���ֵ
	m_range.AttachDispatch(m_sheet.GetCells());
    m_range.AttachDispatch(m_range.GetItem (COleVariant((long)iRow),
        COleVariant((long)iCol)).pdispVal);
    m_vResult = m_range.GetValue2();
    CString str;
    if(m_vResult.vt == VT_BSTR)     //�����ַ���
    {
        str = m_vResult.bstrVal;
    }
    else if (m_vResult.vt == VT_R8) //4�ֽڵ�����
    {
        int ndate = m_vResult.date;
        str.Format("%d",ndate);
    }
    else if(m_vResult.vt == VT_EMPTY) //��ԪΪ��
    {
        str="";
    }
    str.Replace(_T(" "),_T(""));
    return str;
}
BOOL CReadWriteExcel::SetCellString(int iRow,int iCol, CString str)
{
    m_range.AttachDispatch(m_sheet.GetCells());
	m_range.SetNumberFormat(COleVariant("@"));
    COleVariant Item(str);
    m_range.SetItem(COleVariant((long)iRow),COleVariant((long)iCol),Item);
    return FALSE;
}


int  CReadWriteExcel::GetRowCount()
{
    m_range.AttachDispatch(m_usedRange.GetRows());
    //ȡ���Ѿ�ʹ�õ�����
    long iRowNum = m_range.GetCount();         
    return iRowNum;
}
int CReadWriteExcel::GetColCount()
{
    m_range.AttachDispatch(m_usedRange.GetColumns());
    //ȡ���Ѿ�ʹ�õ�����
    long iColNum = m_range.GetCount();  
    return iColNum;
}
