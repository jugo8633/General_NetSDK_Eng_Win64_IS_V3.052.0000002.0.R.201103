#ifndef _BMP_H
#define _BMP_H

#include <string>

using namespace std;


/// \λͼ����
class CBmp
{
public:

    CBmp();
    ~CBmp();

    ///\ �����ȶȱ���ͼ·��
    ///\ szBmpPathName : ����ͼƬ·������
    void SetBmpPathName(const char *szBmpPathName,int iImgWidth,int iImgHeight);

    ///\ ����original
    void SetoriginalValue(int ioriginalWidth,int ioriginalHeight);

    ///\ �����ȶ�ͼ
    bool CreateHeatMapBmp( unsigned char * szData);

private:

    //  ��ɫ֮ǰ�ȴ���24λ�Ҷ�ͼ

    // ��ȡģ�崰���ڵ�ֱ��ͼ
    void Gethistogram(BYTE *pCur, int width, int height, int *histogram);

    // ��ȡģ���ڵ���ֵ
    void GetMedian(int *histogram,int N,int  M,int *med);

    //  ����ͼ��ĻҶȷ�Χ
    bool EnlargeGrayRange(unsigned char* &pImg, int length, int Gmin, int Gmax);

    ///\ ����������ת��Ϊ24λλͼ
    BYTE * Create24bitGrayImg(unsigned char *szBmpData);

    ///\ �Ŵ�Ҷ�ͼ������ͼ�ߴ�
    bool GrayImgZoomInToBkSize( BYTE *pGrayImg);

    ///\ ��ֵƽ������Ҷ�ͼ��     
    bool SmoothGrayImgByMeida();

    ///\ �Ҷ�ͼ��ת��Ϊα��ɫͼ��- �ʺ�ͼ�㷨
    bool ImgChangeGray2ColorByRainbow();

    ///\ �ϳ��ȶ�ͼͼ��
    bool ComposeColorImg();

    ///\ ��ȡBmpͼƬ
    BYTE *ReadBmp_Test(const char *szSavedName, int & bmpWidth, int & bmpHeight, int & biBitCount);

    ///\ ����BmpͼƬ
    bool SaveBmp_Test(const char *szSavedName, BYTE *pImgBuf, int width, int height, int biBitCount);

private:	
    // ����ͼ��ָ��
    BYTE *m_pBkColorImg;
    // �Ҷȸ���ָ��
    BYTE *m_pGrayOverLayerbuf;
    // ��ɫ����ָ��
    BYTE *m_pColorOverLayerbuf;
    // ����ͼƬ����
    string m_strBkImgName;	
    // ����ͼ����
    int m_bkImgWidth;
    // ����ͼ��߶�
    int m_bkImgHeight;	
};

#endif //_BMP_H


