#include "StdAfx.h"
#include "Bmp.h"
#include <vector>
/////////////////////////////////////////////////////////////////////////

const COLORREF RESERVED_COLOR = RGB(255, 255, 255);

static int originalWidth = 1920;
static int originalHeight = 1080;
const int nLimitColor = 5;

typedef struct tagColorTable
{
    BYTE red;  
    BYTE green;  
    BYTE blue; 
}TableColor;

#define NEW new(std::nothrow)

// ͼ����
CBmp::CBmp()
	 :m_pBkColorImg(NULL),
	  m_pGrayOverLayerbuf(NULL),
	  m_pColorOverLayerbuf(NULL),
	  m_bkImgWidth(0),
	  m_bkImgHeight(0)
{

}

CBmp::~CBmp()
{
	if ( m_pBkColorImg)
	{
		delete []m_pBkColorImg;
		m_pBkColorImg = NULL;
	}
	if ( m_pGrayOverLayerbuf)
	{
		delete []m_pGrayOverLayerbuf;
		m_pGrayOverLayerbuf = NULL;
	}
	if ( m_pColorOverLayerbuf)
	{
		delete []m_pColorOverLayerbuf;
		m_pColorOverLayerbuf = NULL;
	}
}

void CBmp::SetBmpPathName(const char *szBmpPathName,int iImgWidth,int iImgHeight)
{
	m_strBkImgName = szBmpPathName;
	m_bkImgHeight = iImgHeight;
	m_bkImgWidth = iImgWidth;
}

void CBmp::SetoriginalValue(int ioriginalWidth,int ioriginalHeight)
{
	originalWidth = ioriginalWidth;
	originalHeight = ioriginalHeight;
}


bool CBmp::CreateHeatMapBmp(unsigned char *szData)
{
	bool bReturn = false;
	// 1. �����������ط�Χ
	bReturn = EnlargeGrayRange(szData, originalWidth * originalHeight, 0, 255);
	if ( false == bReturn)
	{
		return bReturn;
	}
	// 2.  ����24λ�Ҷ�ͼ
	BYTE *pGrayImg = Create24bitGrayImg(szData); 
	if (NULL == pGrayImg)
	{
		return false;
	}	
	// 3. �Ŵ󵽱���ͼ��ߴ�
	bReturn = GrayImgZoomInToBkSize(pGrayImg);
		
	// 4. ��ֵƽ������Ҷ�ͼ��
	bReturn &= SmoothGrayImgByMeida();
	
	// 5. �Ҷ�ͼ��ת��Ϊα��ɫͼ��
	bReturn &= ImgChangeGray2ColorByRainbow();

	// 6. �ϳ��ȶ�ͼͼ��
	bReturn &= ComposeColorImg();
	
	return bReturn;
}

bool CBmp::EnlargeGrayRange(unsigned char* &pImg, int length, int Gmin, int Gmax)
{
	if (length < 1 || Gmin == Gmax)
	{
		return false;
	}

	int histogram[256] = {0};
	int i = 0; 
	for ( i = 0; i < length; ++i)
	{
		histogram[*(pImg + i)]++;
	}
	int gMin = 0, gMax = 0;
	for (i = 0 ; i < 256; ++i)
	{
		if (histogram[i])
		{
			gMin = i;
			break;
		}
	}	
	for ( i = 255; i >=0; --i)
	{
		if (histogram[i])
		{
			gMax = i;
			break;
		}
	}
	
    BYTE LUT[256] = {0};
	// б��
	float k = (Gmax - Gmin) * 1.0F / (gMax - gMin);  //y = k*x + b
	for ( i = 0; i < 256; ++i)
	{
		LUT[i] =  (BYTE)(i * k + (Gmax - gMax * k));
	}

	for ( i = 0; i < length; ++i)
	{
		*(pImg + i) = LUT[*(pImg + i)];
	}
	return true;
}

BYTE * CBmp::Create24bitGrayImg(unsigned char *szBmpData)
{	
	int i =0;
	int j =0;
	int nIndex = 0;
	//  λͼ����ָ��
	BYTE *pBmp24bitBuf = new BYTE[originalWidth * originalHeight * 3];
	memset(pBmp24bitBuf, 0, sizeof(BYTE) * originalWidth * originalHeight * 3);

	for (i = 0; i < originalHeight; ++i)
	{
		for ( j = 0 ; j < originalWidth; ++j)
		{
			BYTE gray = *(szBmpData + nIndex++);

			//ͼ��ת 
#ifdef WIN32
			pBmp24bitBuf[(originalHeight -1 - i) * originalWidth * 3 + j * 3 + 0] =  gray;
			pBmp24bitBuf[(originalHeight -1 - i) * originalWidth * 3 + j * 3 + 1] =  gray;
			pBmp24bitBuf[(originalHeight -1 - i) * originalWidth * 3 + j * 3 + 2] =  gray;
#else
            pBmp24bitBuf[(i) * originalWidth * 3 + j + 0] = gray;
            pBmp24bitBuf[(i) * originalWidth * 3 + j + 1] = gray;  
            pBmp24bitBuf[(i) * originalWidth * 3 + j + 2] = gray; 
#endif
		}
	}
	return pBmp24bitBuf;
}

// �Ŵ�Ҷ�ͼ������ͼ�ߴ�
bool CBmp::GrayImgZoomInToBkSize(BYTE *pGrayImg)
{
	if ( 0 == m_strBkImgName.length())
	{
        delete  []pGrayImg;
        pGrayImg = NULL;
		return false;
	}
	// ÿ�����ش�С
	int bytesPerPixel = 0;

	// �Ƿ񱳾�λͼ�ڴ�
	if (m_pBkColorImg)
	{
		delete []m_pBkColorImg;
		m_pBkColorImg = NULL;
	}

    // ��ȡ����ͼ�ߴ�--  All to 24Bit Bmp
	m_pBkColorImg = ReadBmp_Test(m_strBkImgName.c_str(), m_bkImgWidth, m_bkImgHeight, bytesPerPixel);
    
	if (NULL == m_pBkColorImg || 0 == m_bkImgWidth || 0 == m_bkImgHeight || 24 != bytesPerPixel)
	{
        delete  []pGrayImg;
        pGrayImg = NULL;
		return false;
	}	

	int lineByte=(m_bkImgWidth * bytesPerPixel / 8 + 3) / 4 * 4;   // be equal to ...lineByte = m_bkImgWidth * 3;

	// �ͷ��ȶ�ͼλͼ�ڴ�
	if ( m_pGrayOverLayerbuf)
	{
		delete []m_pGrayOverLayerbuf;
		m_pGrayOverLayerbuf = NULL;
	}

	// �洢�Ŵ󵽱����ߴ�ĻҶ�ͼ����ָ��
    m_pGrayOverLayerbuf = new BYTE[lineByte * m_bkImgHeight];
	memset(m_pGrayOverLayerbuf, 0, sizeof(BYTE) * m_bkImgWidth * 3 /*lineByte*/ * m_bkImgHeight);

	BYTE *pTmpGrayBmp = new BYTE[lineByte * m_bkImgHeight];
	memset(pTmpGrayBmp, 0, sizeof(BYTE) * m_bkImgWidth * 3 /*lineByte*/ * m_bkImgHeight);
	
	int i =0 , j = 0;
	int ii = 0, jj = 0;	
	float fRation = originalWidth * 1.0F / m_bkImgWidth;
	int f1 = 0, f2 = 0;
	//��Ȳ�ֵ
	for (j = m_bkImgWidth-1; j >=0 ; --j)
	{
		jj = static_cast<int>(j * fRation);
		if ( jj > originalWidth-2)
		{
			continue;
		}
		f1 = static_cast<int>(1024 * j * fRation - 1024 * jj);
		f2 = 1024 - f1;
		for ( i = 0 ; i < originalHeight; ++i)
		{
			*(pTmpGrayBmp + i * m_bkImgWidth * 3 + j * 3 + 0) = (*(pGrayImg + i * originalWidth * 3 + jj * 3 + 0) * f2 + *(pGrayImg + i * originalWidth * 3 + (jj + 1) * 3 + 0) * f1 )>>10;
			*(pTmpGrayBmp + i * m_bkImgWidth * 3 + j * 3 + 1) = (*(pGrayImg + i * originalWidth * 3 + jj * 3 + 1) * f2 + *(pGrayImg + i * originalWidth * 3 + (jj + 1) * 3 + 1) * f1 )>>10;
			*(pTmpGrayBmp + i * m_bkImgWidth * 3 + j * 3 + 2) = (*(pGrayImg + i * originalWidth * 3 + jj * 3 + 2) * f2 + *(pGrayImg + i * originalWidth * 3 + (jj + 1) * 3 + 2) * f1 )>>10;
		}
	}

	//�߶Ȳ�ֵ
	fRation = originalHeight * 1.0F / m_bkImgHeight;
	for ( i = m_bkImgHeight - 1; i >=0; --i)
	{
		ii = static_cast<int>(i * fRation);
		if ( ii > originalHeight-2)
		{
			continue;
		}
		f1 = static_cast<int>(1024 * i * fRation - 1024 * ii);
		f2 = 1024 - f1;
		for ( j = 0; j < m_bkImgWidth; ++j)
		{
			*(m_pGrayOverLayerbuf + i * m_bkImgWidth * 3 + j * 3 + 0) = (*(pTmpGrayBmp + ii * m_bkImgWidth * 3 + j * 3 + 0) * f2 + *(pTmpGrayBmp + (ii+1) * m_bkImgWidth * 3 + j * 3 + 0) * f1)>>10;
			*(m_pGrayOverLayerbuf + i * m_bkImgWidth * 3 + j * 3 + 1) = (*(pTmpGrayBmp + ii * m_bkImgWidth * 3 + j * 3 + 1) * f2 + *(pTmpGrayBmp + (ii+1) * m_bkImgWidth * 3 + j * 3 + 1) * f1)>>10;
			*(m_pGrayOverLayerbuf + i * m_bkImgWidth * 3 + j * 3 + 2) = (*(pTmpGrayBmp + ii * m_bkImgWidth * 3 + j * 3 + 2) * f2 + *(pTmpGrayBmp + (ii+1) * m_bkImgWidth * 3 + j * 3 + 2) * f1)>>10;
		}		
	}

	delete []pTmpGrayBmp;
	pTmpGrayBmp = NULL;
	delete []pGrayImg;
	pGrayImg = NULL;
	return true;
}


void CBmp::Gethistogram(BYTE *pCur, int width, int height, int *histogram)
{
	for ( int i = 0; i < height; ++i)
	{
		for ( int j = 0; j < width; ++j)
		{
			histogram[*(pCur + i * m_bkImgWidth * 3 + j * 3)]++;
		}
	}	
}

//GetMedian(histogram,N,M,&med);
void  CBmp::GetMedian(int *histogram, int N, int  M, int *med)
{
	int sum=0;
	for(*med=0; *med<256; (*med)++)
	{
		sum += histogram[*med];
		if(sum * 2 > N*M) 
		{
			break;
		}
	}
	return;
}


bool CBmp::SmoothGrayImgByMeida()
{
	if ( NULL == m_pGrayOverLayerbuf)
	{
		return false;
	}
	/*
	    .......N........
	  	.			   .	
		M			   M
		.			   .
		 ........N......
	  2 2 2 
	  2 2 2
	  2 2 2

  */
	BYTE *pMedia = new BYTE[m_bkImgHeight * m_bkImgWidth * 3];
	memcpy(pMedia, m_pGrayOverLayerbuf, sizeof(BYTE) * m_bkImgHeight * m_bkImgWidth * 3);

	// ģ��ߴ� N * M 
	const int N = 15;
	const int M = 15;
	int med = 0;
	int histgram[256] = {0};
	int nNum = 0;              
	int thred = N * M / 2 + 1;
	BYTE gray = 0;
	int i = 0, j = 0;
	int k = 0;

    i = 0;
	for ( i = M/2; i < m_bkImgHeight - M/2; ++i)
	{
		memset(histgram, 0, sizeof(int) * 256);
		
		Gethistogram((pMedia + (i - M/2) * m_bkImgWidth * 3 ), N, M, histgram);
		
		GetMedian(histgram, N, M, &med);
		
		for ( k = 0; k <= med; ++k)
		{
			nNum += histgram[k];
		}
		
		for ( j = N/2; j < m_bkImgWidth - N/2; ++j)
		{
			*(m_pGrayOverLayerbuf + i * m_bkImgWidth * 3 + j * 3 + 0) = med;
			*(m_pGrayOverLayerbuf + i * m_bkImgWidth * 3 + j * 3 + 1) = med;
			*(m_pGrayOverLayerbuf + i * m_bkImgWidth * 3 + j * 3 + 2) = med;
			for ( k = -M/2; k <= M/2 && (j + N/2 + 1) < m_bkImgWidth; ++k)
			{
				gray = *(pMedia + (i + k) * m_bkImgWidth * 3 + (j - N/2) * 3);
				histgram[gray]--;
				if (gray <= med)
				{
					nNum --;
				}
				
				gray = *(pMedia + (i + k) * m_bkImgWidth * 3 + (j + N/2 + 1) * 3);
				histgram[gray]++;
				if (gray <= med)
				{
					nNum ++;
				}
			}
			if (nNum > thred)
			{
				do 
				{
					nNum -= histgram[med];
					med--;
				}while(nNum > thred);
				
				med++;
				nNum += histgram[med];
			}
			else
			{
				do 
				{
					med++;
					nNum += histgram[med];
				}while(nNum <= thred);
			}	
		}
		nNum = 0;		
	}
	delete []pMedia;
	pMedia = NULL;
	return true;
} 


//�Ҷ�ͼ��ת��Ϊα��ɫͼ��- �ʺ�ͼ�㷨
bool CBmp::ImgChangeGray2ColorByRainbow()
{
	int i =0, j =0, k = 0;
	
	// ���ұ�
	TableColor LUT[256]= {0};
	for ( i = 0; i < 256; ++i)
	{
		k = i;
		if ( i > nLimitColor && i <= 51) 
		{
			LUT[i].blue = (BYTE)(255);
			LUT[i].green = (BYTE)(i* 5);
			LUT[i].red = (BYTE)0;
 		}
 		else if ( i > 51 && i <= 102)  
 		{
			k -= 51;
			LUT[i].blue = (BYTE)(255 - k *5);
 			LUT[i].green = (BYTE)(255);
			LUT[i].red = (BYTE)0;
		}
		else if ( i > 102 && i <= 153)
		{
			k -= 102;
			LUT[i].blue = (BYTE)0;
			LUT[i].green = (BYTE)255;
			LUT[i].red = (BYTE)(k * 5);
		}
		else if (i > 153 && i <= 204)
		{
			k -= 153;
			LUT[i].blue = (BYTE)0;
			LUT[i].green = (BYTE)(255 - (128.0 * k /51 + 0.5));
			LUT[i].red = (BYTE)255;
		}
		else if (i > 204)
		{
			k -= 204;
			LUT[i].blue = (BYTE)0;
			LUT[i].green = (BYTE)(127 - (127.0 * k /51 + 0.5));
			LUT[i].red = (BYTE)255;
		}
	}
	
	// �ͷźϳ�ͼ�ڴ�
	if ( m_pColorOverLayerbuf)
	{
		delete []m_pColorOverLayerbuf;
		m_pColorOverLayerbuf = NULL;
	}

    m_pColorOverLayerbuf = new BYTE[m_bkImgWidth * m_bkImgHeight * 4];
    memset(m_pColorOverLayerbuf, 0, sizeof(BYTE) * m_bkImgWidth * m_bkImgHeight * 4);

    // All to 32Bit ColorBmp
	for (i = 0; i < m_bkImgHeight; ++i)
	{
		for (j = 0; j < m_bkImgWidth; ++j)
		{
#ifdef WIN32  
            BYTE gray = *(m_pGrayOverLayerbuf + i* m_bkImgWidth * 3  + j* 3 + 0);
			*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 0) = LUT[gray].blue;
			*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 1) = LUT[gray].green;
			*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 2) = LUT[gray].red;       
#else
            BYTE gray = *(m_pGrayOverLayerbuf + i* m_bkImgWidth * 3  + j + 0);
            *(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 0) = LUT[gray].red;
			*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 1) = LUT[gray].green;
			*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 2) = LUT[gray].blue;
#endif
            *(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 3) = 255;
		}
	}
	return true;
}

// bkImg-24Bit  OverLayer:32Bit
bool CBmp::ComposeColorImg()
{
	if(NULL == m_pColorOverLayerbuf || NULL == m_pBkColorImg)
	{
		return false;
	}

	int i = 0, j = 0;
	float bkRation = 0.3f;
	BYTE overR = 0, overG = 0, overB = 0;
	BYTE bkR = 0, bkG = 0, bkB = 0;
	for (i = 0 ; i < m_bkImgHeight; ++i)
	{
		for (j = 0; j < m_bkImgWidth; ++j)
		{		
			// ����RGB
			bkR = *(m_pBkColorImg + i * m_bkImgWidth * 3 + j * 3 + 0);
			bkG = *(m_pBkColorImg + i * m_bkImgWidth * 3 + j * 3 + 1);
			bkB = *(m_pBkColorImg + i * m_bkImgWidth * 3 + j * 3 + 2);

			// ǰ��RGB
			overR = *(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 0);
			overG = *(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 1);
			overB = *(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 2);

			if ( overR <= nLimitColor && overG <= nLimitColor && overB <= nLimitColor)
			{
				*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 0) = bkR;
				*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 1) = bkG;
				*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 2) = bkB;
			}
			else
			{
				*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 0) = static_cast<BYTE>(bkR * bkRation + overR * (1-bkRation));
				*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 1) = static_cast<BYTE>(bkG * bkRation + overG * (1-bkRation));
				*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 2) = static_cast<BYTE>(bkB * bkRation + overB * (1-bkRation));			
			}			
			*(m_pColorOverLayerbuf + i * m_bkImgWidth * 4 + j * 4 + 3) = 255;			
		}
	}
	SaveBmp_Test(m_strBkImgName.c_str(), m_pColorOverLayerbuf, m_bkImgWidth, m_bkImgHeight, 32);
	return true;
}

bool CBmp::SaveBmp_Test(const char *szSavedName, BYTE *pImgBuf, int width, int height, int biBitCount)
{
	if( NULL == pImgBuf)
	{
		return false;
	}
	int colorTablesize=0;//��ɫ��Ĵ�С

	if( 8 == biBitCount)
	{
		colorTablesize = 1024;//�Ҷ�ͼ����ɫ���СΪ1024
	}
	//ÿ����ռ���ֽ���
	int lineByte=( width * biBitCount / 8 + 3) / 4 * 4;    

	//�Զ����Ʒ�ʽ���ļ�
	FILE *pFile = fopen(szSavedName, "wb");
	if (NULL == pFile)
	{
		return false;
	}

	//����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;                                            //bmp������ 
	fileHead.bfSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte * height;
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	fileHead.bfOffBits=54+colorTablesize;             //bfOffBits��ͼ���ļ�ǰ������������Ҫ�Ŀռ��

	//д�ļ�ͷ���ļ�
	fwrite(&fileHead,sizeof(BITMAPFILEHEADER), 1, pFile);

	//����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ
	BITMAPINFOHEADER head;
	head.biBitCount = biBitCount;
	head.biClrImportant = 0;
	head.biClrUsed = 0;
	head.biCompression = 0;
	head.biHeight = height;
	head.biPlanes = 1;
	head.biSize = 40;
	head.biSizeImage = lineByte*height;
	head.biWidth = width;
	head.biXPelsPerMeter = 0;
	head.biYPelsPerMeter = 0;
	//дλͼ��Ϣͷ���ڴ�
	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, pFile);

	//����ǻҶ�ͼ������ɫ����Ҫд���ļ� 
	if( 8 == biBitCount)
	{
		RGBQUAD rgbquad[256];
		for ( int i = 0; i <  256; ++i)
		{
			rgbquad[i].rgbBlue = i;
			rgbquad[i].rgbGreen = i;
			rgbquad[i].rgbRed = i;
			rgbquad[i].rgbReserved = 0;
		}
		fwrite(rgbquad, sizeof(RGBQUAD), 256, pFile);
	}
	//дλͼ���ݽ��ļ�      
	fwrite(pImgBuf, height * lineByte , 1, pFile);
	fclose(pFile);    
	return true;
}

BYTE *CBmp::ReadBmp_Test(const char *szSavedName, int & bmpWidth, int & bmpHeight, int & biBitCount)
{
	int lineByte;     
	BITMAPINFOHEADER head = {0};
	FILE *pFile = NULL; 
	size_t nCount = 0;
	int bmpclrused = 0;
	RGBQUAD pColorTable[256] = {0};
	BYTE *pBmpBuf = NULL;
	BYTE *pTmpBmpBuf = NULL;
	BYTE *pTmpBit24BmpBuf = NULL;
	BYTE *pBit24BmpBuf = NULL;
	int nBit24Width = 0;
	int tmpBmpWidth = 0;
	int tmpBmpHeight = 0;
	int tmpbiBitCount = 0;
	
	pFile = fopen(szSavedName, "rb");
	if( NULL == pFile)
	{
		goto ERROR_OUT;
	}        

	//����λͼ���ļ�ͷ
	(void)fseek(pFile, sizeof(BITMAPFILEHEADER), 0);
    
	//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head֮��    
	nCount = fread(&head, sizeof(BITMAPINFOHEADER), 1, pFile);
    if (nCount == 0)
    {
		goto ERROR_OUT;
    }

	//��ȡͼ��ߣ���ÿ��������ռ��λ����Ϣ
	tmpBmpWidth = head.biWidth;
	tmpBmpHeight = head.biHeight;
	tmpbiBitCount = head.biBitCount;
	bmpclrused = head.biClrUsed;

	// �߶ȺͿ����������, ���֧��8K����4K��ͼƬ
	if(tmpBmpWidth <= 0 || tmpBmpWidth > 8000)
	{
		goto ERROR_OUT;
	}

	if(tmpBmpHeight <= 0 || tmpBmpHeight > 4000)
	{
		goto ERROR_OUT;
	}

	// ����32λBMPͼ��ֱ���˳�
	if (tmpbiBitCount != 32)
	{
		goto ERROR_OUT;
	}

	bmpWidth = tmpBmpWidth;
	bmpHeight = tmpBmpHeight;


	//�������������ͼ��ÿ��������ռ���ֽ��� 
	lineByte=(bmpWidth * tmpbiBitCount/8+3)/4*4;

	//�Ҷ�ͼ��
	if( 8 == tmpbiBitCount )
	{
		nCount = fread(pColorTable, sizeof(RGBQUAD), 256, pFile);
        if (nCount == 0)
        {
			goto ERROR_OUT;
        }
	}

	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�
	pBmpBuf = NEW BYTE[(lineByte * bmpHeight)];
	if (NULL == pBmpBuf)
	{
		goto ERROR_OUT;
	}

	//��������      
	nCount = fread(pBmpBuf, 1, lineByte*bmpHeight, pFile);
    if (nCount == 0)
    {
        goto ERROR_OUT;
    }

	// ��32λͼƬ����ת��Ϊ24λ��ͼƬ����
    nBit24Width = lineByte / 4 * 3;
    nBit24Width = (nBit24Width + 3) / 4 *4;

    pBit24BmpBuf = NEW BYTE[nBit24Width * bmpHeight];
	if (NULL == pBit24BmpBuf)
	{
		goto ERROR_OUT;
	}

    for (int i=0; i<bmpHeight; ++i)
    {
        pTmpBmpBuf = pBmpBuf + i*lineByte;
        pTmpBit24BmpBuf = pBit24BmpBuf + i*nBit24Width;
       
        for (int j=0; j<lineByte/4; ++j)
        {
            memcpy(pTmpBit24BmpBuf, pTmpBmpBuf, 3);
            pTmpBmpBuf += 4;
            pTmpBit24BmpBuf += 3;
        }
    }
	
    // �����ὫͼƬ����ǿ�ƴ�32λ���24λ����������ǿ�Ƹ�ֵΪ24λ
    biBitCount = 24;

ERROR_OUT:
	if (NULL != pFile)
	{
		fclose(pFile);
		pFile = NULL;
	}
	
	if (NULL != pBmpBuf)
	{
		delete []pBmpBuf;
		pBmpBuf = NULL;
	}
    
	return  pBit24BmpBuf;
}


