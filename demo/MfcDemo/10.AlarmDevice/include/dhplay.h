#ifndef _DHPLAY_H
#define _DHPLAY_H

#if (defined(WIN32) || defined(WIN64))
	#ifdef dhplay_EXPORTS
		#define PLAYSDK_API __declspec(dllexport)
	#else
		#define PLAYSDK_API __declspec(dllimport)
	#endif
	#define CALLMETHOD __stdcall
	#define CALLBACK   __stdcall
#else
	#define CALLMETHOD
	#define CALLBACK
	#define PLAYSDK_API //extern "C"
#endif

#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#ifdef __OBJC__
#include "objc/objc.h"
#else
#define BOOL        int
#endif
#define BYTE		unsigned char
#define PBYTE		BYTE*
#define LPBYTE		BYTE*
#ifndef LONG
#define LONG		int
#endif
#ifndef DWORD
#define DWORD		unsigned int
#endif
#define WORD		unsigned short
#define COLORREF	DWORD
#define HDC			void*
#define HWND		void*
#define LPSTR		char*
#define UINT		unsigned int
#define TRUE		1
#define FALSE		0
#define ULONGLONG	unsigned long long
#define LONGLONG	long long

typedef struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;
#endif

#ifdef	__cplusplus
extern "C" {
#endif

/***********************************************************************************************/
/* ��������																					   */
/***********************************************************************************************/

/* ͨ���� */
#define  FUNC_MAX_PORT					511		// ���ͨ���ţ�ͨ���ŷ�Χ[0,512)

/* ��Ƶ��ֵ */
#define MIN_WAVE_COEF					-100	// PLAY_AdjustWaveAudioʹ��
#define MAX_WAVE_COEF					100		// PLAY_AdjustWaveAudioʹ��

/* ��Ƶ�ɼ����� */
#define MIN_AUDIO_RECORD_LEN			320		// ��С��Ƶ�ɼ�����
#define MAX_AUDIO_RECORD_LEN			4096	// �����Ƶ�ɼ�����

/* ��ʾ��� */
#define MAX_DISPLAY_WND					64      // ���õ�������ŵ����ֵ

/* ���Ż������ */
#define BUF_VIDEO_SRC					1		// ��ƵԴ����
#define BUF_AUDIO_SRC					2		// ��ƵԴ����
#define BUF_VIDEO_RENDER				3		// �������Ƶ���ݻ���
#define BUF_AUDIO_RENDER				4		// �������Ƶ���ݻ���

/* �ļ���ת��ʽ */
#define BY_FRAMENUM						1		// ��֡�ŷ�ʽ(PLAY_GetKeyFramePosʹ��)
#define BY_FRAMETIME					2		// ��ʱ�䷽ʽ(PLAY_GetKeyFramePosʹ��)

/* ��������� */
#define SOURCE_BUF_MAX					1024*100000	// ��������������󳤶�
#define SOURCE_BUF_MIN					1024*1024	// ��������������С����

#define STREAME_REALTIME				0		// ʵʱ��ģʽ
#define STREAME_FILE					1		// �ļ���ģʽ

/* ��Ƶλ�� */
#define T_AUDIO16						101		// 16λ��Ƶ��������
#define T_AUDIO8						100		// 8λ��Ƶ��������

/* ��������Ƶ��ʽ */
#define T_UYVY							1		// UYVY���͵�YUV���ݣ����ڲ�֧��
#define T_IYUV							3		// IYUV(I420)����YUV����
#define T_NV12							5		// NV12����yuv���ݣ�����ֻ֧��bmp32ץͼ
#define T_RGB32							7		// RGB32���ͣ����ڲ�֧��

/* aviת�� */
#define AVI_MEDIACHANGE_FRAMERATE		1		// ֡�ʸı�
#define AVI_MEDIACHANGE_RESOLUTION		2		// �ֱ��ʸı�

/* ˮӡ��� */
#define WATERMARK_DATA_TEXT				0		// ����
#define WATERMARK_DATA_JPEG_BMP			1		// JPEG����BMPͼƬ
#define WATERMARK_DATA_FRAMEDATA		3		// ֡����

/* ������ */
#define  DH_PLAY_NOERROR							0	//�޴���
#define  DH_PLAY_COMMON_ERROR						1	//��ͨ����
#define	 DH_PLAY_PARA_INVALID						2	//������Ч
#define  DH_PLAY_ORDER_ERROR						3	//����˳�򲻶�
#define	 DH_PLAY_PORT_OPEN							4	//ͨ���Ѿ�����
#define	 DH_PLAY_PORT_CLOSE							5	//ͨ���Ѿ����ر�
#define	 DH_PLAY_PORT_INVALID						6	//ͨ������Ч
#define	 DH_PLAY_PORT_EXIST							7	//ͨ���Ѿ�����
#define  DH_PLAY_OPEN_FILE_ERROR					8	//���ļ�ʧ��
#define  DH_PLAY_INTERFACE_NOT_SUPPORT				9	//�ӿڲ�֧��
#define  DH_PLAY_HWND_INVALID						10	//���ھ����Ч
#define  DH_PLAY_PLAY_ERROR							11	//����ʧ��
#define  DH_PLAY_SPEED_INVALID						12	//�ٶ���Ч
#define  DH_PLAY_NOT_FILE							13	//���ļ�ģʽ
#define  DH_PLAY_NOT_STREAM							14	//����ģʽ
#define  DH_PLAY_NO_FRAME							15	//��ǰû��֡����
#define  DH_PLAY_INDEX_NOT_COMPLETE					16	//����û�н������
#define  DH_PLAY_INDEX_COMPLETE						17	//�ѽ����ļ�����
#define  DH_PLAY_GET_FILE_SIZE_ERROR				18	//��ȡ�ļ���Сʧ��
#define  DH_PLAY_CREATE_THREAD_FAIL					19	//�����߳�ʧ��
#define  DH_PLAY_CREATE_EVENT_FAIL					20	//�������ʧ��
#define  DH_PLAY_SOUND_SHARE_MODE					21	//���ڹ�������ģʽ
#define  DH_PLAY_INCLUDE_SOUND_SHARE_PORT			22	//�ö˿��Ѱ���
#define  DH_PLAY_NOT_INCLUDE_SOUND_SHARE_PORT		23	//�ö˿�δ����
#define  DH_PLAY_CREATE_DIR_ERROR					24	//����·��ʧ��
#define  DH_PLAY_CREATE_FILE_ERROR					25	//�����ļ�ʧ��

#define  DH_PLAY_CONVERT_YUV_ERROR					26	//ת��yuvʧ��
#define  DH_PLAY_CONVERT_JPG_ERROR					27	//ת��jpgʧ��
#define  DH_PLAY_CONVERT_BMP_ERROR					28	//ת��bmpʧ��
#define  DH_PLAY_CONVERT_TIFF_ERROR					29	//ת��tiffʧ��
#define  DH_PLAY_HW_CATCH_ERROR					    30	//Ӳ����ץ��ʧ��
#define  DH_PLAY_CREATE_VIDEO_RENDER_ERROR			31	//������Ƶ��Ⱦʧ��
#define  DH_PLAY_NOT_SUPPORT_REF_VALUE				32	//��֧���ⲿ��������
#define  DH_PLAY_FORMAT_NOT_SUPPORT					33	//��ʽ��֧��
#define  DH_PLAY_CREATE_RECORD_ERROR				34	//����¼��ʧ��
#define  DH_PLAY_OPEN_RECORD_ERROR					35	//��¼��ʧ��
#define  DH_PLAY_FRAMERATE_ERROR					36	//֡�ʴ���
#define  DH_PLAY_CREATE_AUDIO_RECORD_ERROR			37	//������Ƶ¼��ʧ��
#define  DH_PLAY_OPEN_AUDIO_RECORD_ERROR			38	//����Ƶ¼��ʧ��
#define	 DH_PLAY_AES_ALLOC_ERROR					39	//����aes_allocʧ��

#define  DH_PLAY_BUF_OVER				            40  //����������
#define  DH_PLAY_ALLOC_MEMORY_ERROR		            41  //�����ڴ�ʧ��


/***********************************************************************************************/
/* ö�ٶ���																					   */
/***********************************************************************************************/
																								
/* ��Ⱦģʽ */
typedef enum
{
	RENDER_NOTSET = 0,				// δ����
	RENDER_GDI,						// GDI��Ⱦ
	RENDER_X11 = RENDER_GDI,		// ��windowsƽ̨X11��Ⱦ
	RENDER_DDRAW,					// ddraw��Ⱦ	
	RENDER_OPENGL = RENDER_DDRAW,	// ��windowsƽ̨opengl��Ⱦ
    RENDER_D3D,						// D3D��Ⱦ,Ĭ�ϵ�ͬ��D3D9��Ⱦ
	RENDER_D3D9 = RENDER_D3D,       // D3D9��Ⱦ
	RENDER_WGL,						// windowsƽ̨opengl��Ⱦ
	RENDER_D3D11                    // D3D11��Ⱦ
}RenderType;

/* ����ģʽ */
typedef enum
{
	DECODE_NOTSET = 0,		// δ����
	DECODE_SW,				// ���
	DECODE_HW,				// Ӳ���뿽��ģʽ(��ʹ��windowsƽ̨��ʹ��d3d9�ӿ�)
	DECODE_HW_FAST,			// Ӳ����ֱ����ʾģʽ(��ʹ��windowsƽ̨��ʹ��d3d9�ӿ�)
	DECODE_MSDK,			// Ӳ���룬����intel media sdk���ѷ���
	DECODE_HW_FAST_D3D11,		// Ӳ����ֱ����ʾģʽ,ʹ��d3d11�ӿ�,����windowsƽ̨
}DecodeType;

/* ͼƬ��ʽ */
typedef enum __tPicFormats
{
	PicFormat_BMP = 0,				        // BMP32����
	PicFormat_JPEG,							// JPEG����
	PicFormat_JPEG_70,						// 70%������JPEG����
	PicFormat_JPEG_50,						// 50%������JPEG����
	PicFormat_JPEG_30,						// 30%������JPEG����
	PicFormat_JPEG_10,						// 10%������JPEG����
	PicFormat_BMP24,                        // BMP24����
	PicFormat_TIFF							// TIFF����
} tPicFormats;

/* ��ȡý����Ϣ��ʽ */
typedef enum _CMD_TYPE
{
	PLAY_CMD_GetTime = 1,			// ������ʱ����Ϣ��Ϊ����������
	PLAY_CMD_GetFileRate = 2,		// ֡����Ϣ
	PLAY_CMD_GetMediaInfo = 3,		// ý����Ϣ
	PLAY_CMD_GetRenderNum = 4,		// ��ǰҪ��Ⱦ��֡��
	PLAY_CMD_GetRenderTime = 5,		// ��ǰҪ��Ⱦ��ʱ�䣬����ʱ��
	PLAY_CMD_GetSrcTime	= 6,		// ������ʱ����Ϣ��Ϊ1970��7��1�պ�����������
	PLAY_CMD_GetCurRenderNum = 7,   // ��ǰ֡�ţ�PLAY_CMD_GetRenderNum����һ֡��֡��
    PLAY_CMD_GetRenderTimeStamp = 8 // ��ǰҪ��Ⱦ��ʱ��������ʱ���
} CMD_TYPE_E;

/* ����Ƶͬ������ */
typedef enum
{
	AV_SYNC_VIDEO_MASTER,		  // ����ƵΪ��׼��������Ƶͬ����ʽ��
	AV_SYNC_AUDIO_TIME_STAMP      // ����Ƶʱ���Ϊ��׼
}AV_SYNC_TYPE;

/***********************************************************************************************/
/* �ṹ�嶨��																				   */
/***********************************************************************************************/

/* �ֲ���ʾ���� */
typedef struct _tagRECT
{
	LONG left;								
	LONG top;								
	LONG right;								
	LONG bottom;							
}DISPLAYRECT;

/* ʱ��ṹ */
#ifndef _DHTIME_
#define _DHTIME_
typedef struct _DHTIME								
{
	DWORD second	:6;						//	��	0-59		
	DWORD minute	:6;						//	��	0-59		
	DWORD hour		:5;						//	ʱ	0-23		
	DWORD day		:5;						//	��	1-31		
	DWORD month		:4;						//	��	1-12		
	DWORD year		:6;						//	��	2000-2063	
} DHTIME,*pDHTIME;
#endif

/* �ļ���Ϣ�ṹ������ʹ�� */
#define UUID_MAX_LEN		96		//����Ψһ��ʶ����
#define MAX_DEV_NAME_LEN	32		//�������Ƴ���
typedef struct _FILE_INFO
{
	UINT			channel;				//ͨ����
	BYTE			type;					//�ļ�����,������ֵ����
	BYTE			lock_flag;				//��������(���Ͷ����dhfs_file_state)
	BYTE			video_audio;			//��Ƶ����Ƶ
	BYTE			image;					//bit0~3ͼ������(bit4~6����, bit7 ��ʾ����ʱ)

	DHTIME			start_time;				//��ʼʱ��
	DHTIME			end_time;				//����ʱ��

	UINT			file_length;			//�ļ����ȣ���λΪKB

	UINT			first_clus_no;			//�ļ��״غ�
	UINT			ud_no;					//�û����ݺ�

	char			part[MAX_DEV_NAME_LEN];	//�ļ����ڵķ�������, ��:"dev/sda_0"
	char			uuid[UUID_MAX_LEN];		//�ļ����ڷ���uuid,ÿ��������Ψһ��ʶ,����ж��|���غ�����

	UINT		rev[9];
}FILE_INFO,*pFILE_INFO;

/* ֡λ����Ϣ */
typedef struct
{
	LONGLONG		nFilePos;				// ָ��֡���ļ��е�ƫ��λ��
	LONG			nFrameLen;				// ֡����
	LONG			nFrameNum;				// ֡���
	LONG			nFrameTime;				// ֡ʱ��
	LONG			nErrorFrameNum;			// ����������ʹ��
	SYSTEMTIME*		pErrorTime;				// ����������ʹ��
	LONG			nErrorLostFrameNum;		// ����������ʹ��
	LONG			nErrorFrameSize;		// ����������ʹ��
}FRAME_POS,*PFRAME_POS;

/* ֡��Ϣ */
typedef struct
{
	LONG			nWidth;					// �������λ���ء��������Ƶ������Ϊ0
	LONG			nHeight;				// ����ߣ��������Ƶ������Ϊ0
	LONG			nStamp;					// ʱ����Ϣ����λ����
	LONG			nType;					// ��Ƶ֡���ͣ�T_AUDIO16��T_RGB32��T_IYUV
	LONG			nFrameRate;				// ��Ƶ��ʾ֡�ʣ���Ƶ��ʾ������
}FRAME_INFO;

/* ֡��Ϣ��չ�ֶ� */
typedef struct
{
	#define FRAME_TYPE_VIDEO 0				// ��Ƶ֡
	#define FRAME_TYPE_AUDIO 1				// ��Ƶ֡
	int				nFrameType;				// ��Ƶ֡���ͣ������涨��
	int				nFrameSeq;				// ֡���
	int				nStamp;					// ʱ����Ϣ����λ����
	int				nWidth;					// �������λ���ء��������Ƶ������Ϊ0
	int 			nHeight;				// ����ߣ��������Ƶ������Ϊ0
	int				nFrameRate;				// ����ʱ������ͼ��֡��
	int				nChannels;				// ��Ƶͨ����
	int				nBitPerSample;			// ��Ƶ����λ��
	int				nSamplesPerSec;			// ��Ƶ����Ƶ��
	int				nRemainData;			// ����ʣ��������
	SYSTEMTIME		nDataTime;				// ʱ��
	int				nFrameSubType;			// ��Ƶ֡������
	int				nReserved[58];			// �����ֶ�
}FRAME_INFO_EX;

/* ������֡��Ϣ */
typedef struct 
{
	int				nFrameType;					// ֡���ͣ������FRAME_INFO_EX��nFrameType�ֶ�
	void*			pAudioData;				    // ��Ƶ���ݣ��������Ƶ֡
	int				nAudioDataLen;			    // ��Ƶ���ݳ���
	void*			pVideoData[3];			    // �ֱ��ʾ��Ƶ��YUV��������
	int				nStride[3];				    // �ֱ��ʾYUV���������Ŀ��
	int				nWidth[3];				    // �ֱ��ʾYUV���������Ŀ��
	int				nHeight[3];					// �ֱ��ʾYUV���������ĸ߶�
    SYSTEMTIME		nDataTime;				    // ֡ʱ��
	int				nReserved[60];				// �����ֶ�
}FRAME_DECODE_INFO;

/* ý����Ϣ */
typedef struct 
{
	int			lWidth;					//	�������λ����
	int			lHeight;				//	�����
	int			lFrameRate;				//	֡��
	int			lChannel;				//	��Ƶͨ����
	int			lBitPerSample;			//	��Ƶ����λ��
	int			lSamplesPerSec;			//	��Ƶ����Ƶ��
}MEDIA_INFO;

/***********************************************************************************************/
/* �ӿ�																						   */
/***********************************************************************************************/

/************************************************************************/
//> ��ȡ�汾��
/************************************************************************/

/**
 * ��ȡ���ſ�SDK���汾�ţ��ΰ汾�ź�SVN�汾�š�
 *
 * @return ���1λ��ʾ��ǰ�����汾�ţ���2~3λ��ʾ�ΰ汾�ţ�����ı�ʾSVN�汾�š�
 *         �磺����ֵ34033722��ʾ�����汾����3���ΰ汾����40��SVN�汾����33722��
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSdkVersion();

/************************************************************************/
//> ������
/************************************************************************/

/**
 * ��ȡ�����롣
 *
 * @return ������
 */
PLAYSDK_API DWORD  CALLMETHOD PLAY_GetLastErrorEx();

/************************************************************************/
//> ��־����
/************************************************************************/

/**
 * ��־���Կ��أ�Ĭ��ΪWarn�ȼ�����ӡ���١������Ҫ������ϸ��־��ӡ������ΪDebug�ȼ���
 * Windowsƽ̨����Ϊ��ǰ��Ŀ¼�µ�playsdk.log�ļ���������windowsΪ����̨��ӡ��
 *
 */
typedef enum
{
    LOG_LevelUnknown= 0, // δ֪�ȼ�
    LOG_LevelFatal,	     // fatal�ȼ���������Ϊ�˵ȼ�ʱ����һ�ִ�ӡ�����fatal���������
    LOG_LevelError,	     // error�ȼ���������Ϊ�˵ȼ�ʱ�������ִ�ӡ�����fatal��error���������
    LOG_LevelWarn,	     // warn�ȼ���������Ϊ�˵ȼ�ʱ�������ִ�ӡ�����fatal��error��warn���������
    LOG_LevelInfo,	     // info�ȼ���������Ϊ�˵ȼ�ʱ�������ִ�ӡ�����fatal��error��warn��info���������
    LOG_LevelTrace,	     // Trace�ȼ���������Ϊ�˵ȼ�ʱ�������ִ�ӡ�����fatal��error��warn��info��trace���������
    LOG_LevelDebug	     // Debug�ȼ���������Ϊ�˵ȼ�ʱ���������ִ�ӡ��fatal��error��warn��info��trace��debug���������
}LOG_LEVEL;
PLAYSDK_API void CALLMETHOD PLAY_SetPrintLogLevel(LOG_LEVEL logLevel);

/************************************************************************/
//> ���Ŷ˿ں�
/************************************************************************/

/**
 * ��ȡ����ͨ���ţ���Χ��101~511��
 *
 * @param[out] plPort ��ȡ���Ŀ���ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort(LONG *plPort);

/**
 * �ͷ�ͨ���š�
 *
 * @param[in] lPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_ReleasePort(LONG lPort);

/************************************************************************/
//> �ļ�����
/************************************************************************/

/**
 * �򿪲����ļ���
 *
 * @param[in] nPort ͨ����
 * @param[in] sFileName �ļ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenFile(LONG nPort,LPSTR sFileName);

/**
 * �ر��ļ���
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseFile(LONG nPort);

/**
 * �ļ������ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pUserData �û�����
 */
typedef void (CALLBACK *fFileEndCBFun)(DWORD nPort, void* pUserData);

/**
 * �ļ������ص���
 *
 * @param[in] nPort ͨ����
 * @param[out] pFileEndCBFun �ļ����������ص�ָ��
 * @param[in] pUserData �û�����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndCallBack(LONG nPort, fFileEndCBFun pFileEndCBFun, void* pUserData);

/************************************************************************/
//> ������
/************************************************************************/

/**
 * ����������ģʽ��
 *
 * @param[in] nPort ͨ����
 * @param[in] nMode ����ģʽ��0ʵʱ����1�ļ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetStreamOpenMode(LONG nPort,DWORD nMode);

/**
 * ��ȡ����ģʽ��
 *
 * @param[in] nPort ͨ����
 * @return LONG��STREAM_MODE_REALSTREAM��STREAM_MODE_FILESTREAM
 */
PLAYSDK_API LONG CALLMETHOD PLAY_GetStreamOpenMode(LONG nPort);

/**
 * ������
 *
 * @param[in] nPort ͨ����
 * @param[in] pFileHeadBuf �ļ�ͷ����
 * @param[in] nSize �ļ�ͷ����
 * @param[in] nBufPoolSize ���ò������д���������Ļ�������С����Χ��SOURCE_BUF_MIN~SOURCE_BUF_MAX
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

/**
 * �ر�����
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream(LONG nPort);

/**
 * ������������PLAY_Play֮��ʹ�á�
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf �����ݻ�������ַ
 * @param[in] nSize �����ݳ���
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);


/************************************************************************/
//> �������
/************************************************************************/

/**
 * �Զ�ռ��ʽ��������
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySound(LONG nPort);

/**
 * �ر���������ռ��ʽ����
 *
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound();

/**
 * �Թ���ʽ��������
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare(LONG nPort);

/**
 * �ر�����������ʽ����
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare(LONG nPort);

/**
 * ����������
 *
 * @param[in] nPort ͨ����
 * @param[in] nVolume ����ֵ����Χ0-0xFFFF
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVolume(LONG nPort,WORD nVolume);

/**
 * ��ȡ������
 *
 * @param[in] nPort ͨ����
 * @return WORD������ֵ
 * @note �����������ָ�������������������Ӱ�쵽����������Ӧ�á�
 */
PLAYSDK_API WORD CALLMETHOD PLAY_GetVolume(LONG nPort);

/**
 * ��Ƶ�ɼ����ݻص�������
 *
 * @param[in] pDataBuffer ���ݵ�ַ
 * @param[in] DataLength ���ݳ���
 * @param[in] pUserData �û�����
 */
typedef void (CALLBACK *pCallFunction)(LPBYTE pDataBuffer, DWORD DataLength, void* pUserData);

/**
 * ����Ƶ�ɼ����ܡ�
 *
 * @param[in] pProc��Ƶ�ɼ����ݻص�ָ��
 * @param[in] nBitsPerSample ��Ƶ����λ��
 * @param[in] nSamplesPerSec ��Ƶ������
 * @param[in] nLength ���ݻ���ĳ��ȣ���Χ320-4096
 * @param[in] encodetype �Բɼ����ݽ��б������ã�0��pcm��1��g711a��2��g711u��pcm�ص������ݣ�g711a��g711u�ص����´�ͷ������
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenAudioRecord(pCallFunction pProc, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG encodetype, void* pUserData);

/**
 * �ر���Ƶ�ɼ����ܡ�
 *
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseAudioRecord();

/**
 * ��Ƶ�ɼ��������ܡ�
 *
 * @param[in] bStart �����ر���Ƶ�ɼ�������1-������0-�رգ� ��֧��Andriod/IOS
 * @param[in] nPitch �����仯�ĳ̶ȣ���Χ��-50-50��0ʱ��������
 * @param[in] bQuick �ǿ���ʵ�֣�0-��ʹ�ܣ�������ߣ�cpu��������1-ʹ�ܣ������½���cpu���ļ��� 
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SpeechChange(BOOL bStart, int nPitch, BOOL bQuick);

/**
 * ������Ƶ�ɼ����ű�����
 *
 * @param[in] fRatio ���ű���������0С��1Ϊ��Ƶ��С��1Ϊԭʼ��Ƶ������1Ϊ��Ƶ�Ŵ�
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRecScaling(float fRatio);

/**
 * ��ȡ��Ƶ�ɼ����ű�����
 *
 * @param[out] pfRatio ���ű���������0С��1Ϊ��Ƶ��С��1Ϊԭʼ��Ƶ������1Ϊ��Ƶ�Ŵ�
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRecScaling(float* pfRatio);

/**
 * ������Ƶ�������ű�����
 *
 * @param[in] nPort ͨ����
 * @param[in] fRatio ���ű���������0С��1Ϊ��Ƶ��С��1Ϊԭʼ��Ƶ������1Ϊ��Ƶ�Ŵ�
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRenderScaling(LONG nPort, float fRatio);

/**
 * ��ȡ��Ƶ�������ű�����
 *
 * @param[in] nPort ͨ����
 * @param[out] pfRatio ���ű���������0С��1Ϊ��Ƶ��С��1Ϊԭʼ��Ƶ������1Ϊ��Ƶ�Ŵ�
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRenderScaling(LONG nPort, float* pfRatio);

/**
 * ����WAVE���Σ����Ըı������Ĵ�С������PLAY_SetVolume�Ĳ�ͬ���ڣ����ǵ����������ݣ�ֻ�Ը�·�����ã���PLAY_SetVolume��
 * �������������� ������ϵͳ�����á�
 *
 * @param[in] nPort ͨ����
 * @param[in] nCoefficient ����������0�ǲ�����������ȡֵ��Χ��MIN_WAVE_COEF��MAX_WAVE_COEF�����趨ΪMIN_WAVE_COEF��
 *                         ʾ������ͣ����趨ΪMAX_WAVE_COEF��ʾ�������
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustWaveAudio(LONG nPort,LONG nCoefficient);

/************************************************************************/
//> ���ſ���
/************************************************************************/

/**
 * �������š����ſ�ʼ��������Ƶ�����С������hWnd���ڵ�����Ҫȫ����ʾ��ֻҪ��hWnd���ڷŴ�ȫ������ʼ�����̣߳����������ʾ��   
 * �ھ��ΪNULL������ʾ�����ǲ�Ӱ����롣
*
* @param[in] nPort ͨ����
* @param[in] hWnd ������Ƶ�Ĵ��ھ��
* @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
* @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_Play(LONG nPort, HWND hWnd);

/**
 * �رղ��š�
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_Stop(LONG nPort);

/**
 * ��ͣ/�ָ����š�
 *
 * @param[in] nPort ͨ����
 * @param[in] nPause 1����ͣ��0���ָ�
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_Pause(LONG nPort,DWORD nPause);

/**
 * ���ٲ��š�ÿ�ε��ý�ʹ��ǰ�����ٶ���һ����Ҫ�ָ��������ŵ���PLAY_Play()���ӵ�ǰλ�ÿ�ʼ�������š�
 * �����ٶȷ�ΧΪ[1/64,64]��
 *
 * @param[in] nPort ͨ����
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_Slow(LONG nPort);

/**
 * ���ٲ��š�ÿ�ε��ý�ʹ��ǰ�����ٶȼӿ�һ����Ҫ�ָ��������ŵ���PLAY_Play()���ӵ�ǰλ�ÿ�ʼ������ 
   �ţ����������ڸ߱��ٲ���ʱ�������ܵ��������ʾ�����ƣ����ܴﲻ�������õ��ٶȡ�
 * �����ٶȷ�ΧΪ[1/64, 64]��
 *
 * @param[in] nPort ͨ����
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_Fast(LONG nPort);

/**
 * ��֡���š�Ҫ�ָ��������ŵ���PLAY_ Play��
 *
 * @param[in] nPort ͨ����
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOne(LONG nPort);

/**
 * ��֡���š�Ҫ�ָ��������ŵ���PLAY_ Play��ֻ֧���ļ����ţ��ұ������ļ���������֮����ܵ��á�
 *
 * @param[in] nPort ͨ����
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOneBack(LONG nPort);

/**
 * ������Ƶ������
 *
 * @param[in] nPort ͨ����
 * @param[in] nRegionNum ��ʾ�������ֻ��һ����ʾ����(ͨ�����)��Ϊ0
 * @param[in] nBrightness ���ȡ�Ĭ��64����Χ0-128
 * @param[in] nContrast �Աȶȡ�Ĭ��64����Χ0-128
 * @param[in] nSaturation ���Ͷȡ�Ĭ��64����Χ0-128
 * @param[in] nHue ɫ����Ĭ��64����Χ0-128
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

/**
 * ��ȡ��Ƶ������
 *
 * @param[in] nPort ͨ����
 * @param[in] nRegionNum ��ʾ����
 * @param[out] pBrightness ����
 * @param[out] pContrast �Աȶ�
 * @param[out] pSaturation ���Ͷ�
 * @param[out] pHue ɫ��
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);

/**
 * ��������Ƶ���Ų��ԡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] nAVSyncType �������Ż�׼����AV_SYNC_TYPE
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAVSyncType(LONG nPort,AV_SYNC_TYPE nAVSyncType);

/**
 * �ı���Ƶ�����ٶȡ��ڷ�1��������Ƶ�ᱻ������
 *
 * @param[in] nPort ͨ����
 * @param[in] fCoff �����ٶȣ���Χ��1/64-64���������ٶȽϿ�ʱ������Ҫ��֡����
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlaySpeed(LONG nPort, float fCoff);

/**
 * ���ò��ŷ���
 *
 * @param[in] nPort ͨ����
 * @param[in] emDirection ���ŷ���0�����ţ�1������
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE��
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayDirection(LONG nPort, DWORD emDirection);

/**
 * �����ӳٲ���ʱ�䡣[nDelay,nThreshold]��С��nDelay��΢���ţ�����nThreshold��΢��ţ�����֮���������š�
 *
 * @param[in] nPort ͨ����
 * @param[in] nDelay(ms) �ӳ�ʱ�䡣����ﵽ��ʱ���������ţ�С�ڸ�ʱ����΢����
 * @param[in] nThreshold(ms) ��ֵʱ�䡣����С�ڸ�ʱ���������ţ����ڸ�ʱ����΢���
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDelayTime(LONG nPort, int nDelay, int nThreshold);

/**
 * ���ò��Ų��ԣ�ֻ��ʵʱ����Ч��
 *
 * @param[in] nPort ͨ����
 * @param[in] nStartTime(ms) ��ʼ����ʱ��
 * @param[in] nSlowTime(ms) ��ֵʱ�䡣����С�ڸ�ʱ���������ţ����ڸ�ʱ����΢���
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayMethod(LONG nPort, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);


/* ʵʱ�����ݻ���ģʽ */
typedef enum
{
	CACHE_MODE_OFF = 0,		// �ر�ʵʱ������Ӧ����ģʽ
	ADAPTIVE_CACHE,			// ����Ӧ����
	REALTIME_FIRST,			// ʵʱ����
	FLUENCY_FIRST,			// �������� 
} CACHE_MODE;

/**
 * ���ò��Ż���ģʽ��ֻ��ʵʱ����Ч��
 *
 * @param[in] nPort ͨ����
 * @param[in] cacheMode ʵʱ���ݻ���ģʽ
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetCacheMode(LONG nPort, CACHE_MODE cacheMode);

/**
 * ������Ƶ���Ų��ԣ�ֻ�����ڶԽ�ҵ�񣩣�����PLAY_PlaySound֮�����
 *
 * @param[in] nPort ͨ����
 * @param[in] nClearTime(ms) ���������ֵ
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioPlayMethod(LONG nPort, int nClearTime);

/**
 * ����ͼ��ת����Χ0-3��
 *
 * @param[in] nPort ͨ����
 * @param[in] nrotateType ��ת���͡�0������ת��1����ת90�ȣ�2����ת180�ȣ�3����ת270��
 * @return �ɹ�����TURE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRotateAngle(LONG nPort , int nrotateType);

/************************************************************************/
//> �ļ���λ
/************************************************************************/

/**
 * �����ļ�����ָ������λ��(�ٷֱ�)��
 *
 * @param[in] nPort ͨ����
 * @param[in] fRelativePos �ļ����ȵİٷֱ�
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPos(LONG nPort,float fRelativePos);

/**
 * ��ȡ�ļ�����ָ������λ��(�ٷֱ�)��
 *
 * @param[in] nPort ͨ����
 * @return float�������ļ����ȵ����λ�ã���Χ0-100%
 */
PLAYSDK_API float CALLMETHOD PLAY_GetPlayPos(LONG nPort);

/**
 * �����ļ���ǰ����ʱ�䡣
 *
 * @param[in] nPort ͨ����
 * @param[in] nTime �����ļ�����λ�õ�ָ��ʱ�䣬��λ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedTimeEx(LONG nPort,DWORD nTime);

/**
 * ��ȡ�ļ���ǰ����ʱ�䡣
 *
 * @param[in] nPort ͨ����
 * @return DWORD���ļ���ǰ���ŵ�ʱ�䣬��λ����
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTimeEx(LONG nPort);

/**
 * ��ȡ��ǰ���ŵ�֡��ţ�PLAY_GetPlayedFrames���ܹ������֡��������ļ�
 * ����λ�ò����ı䣬��ô�����������ķ���ֵӦ�÷ǳ��ӽ�������������ʧ
 * ���ݡ�
 *
 * @param[in] nPort ͨ����
 * @return DWORD����ǰ���ŵ�֡���
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameNum(LONG nPort);

/**
 * �����ļ���ǰ֡����֡�ţ��˺����������ļ���������֮����ܵ��á�
 *
 * @param[in] nPort ͨ����
 * @param[in] nFrameNum ֡���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

/**
 * ��ȡ�Ѳ��ŵ�֡����
 *
 * @param[in] nPort ͨ����
 * @return DWORD���Ѿ����ŵ���Ƶ֡��
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedFrames(LONG nPort);

/**
 * ��ȡ��ǰ�ļ�����ʱ�䡣
 *
 * @param[in] nPort ͨ����
 * @return DWORD���ļ���ǰ���ŵ�ʱ�䣬��λ��
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTime(LONG nPort);

/**
 * ��ȡ�ļ���ʱ�䡣
 *
 * @param[in] nPort ͨ����
 * @return DWORD���ļ��ܵ�ʱ�䳤��ֵ����λ��
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTime(LONG nPort);

/**
 * ��ȡ�ļ���֡����
 *
 * @param[in] nPort ͨ����
 * @return DWORD���ļ��е���֡��
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTotalFrames(LONG nPort);

/************************************************************************/
//> �ļ�����
/************************************************************************/

/**
 * ���������ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pUserData �û��Զ������
 */
typedef void(CALLBACK *fFileRefDoneCBFun)(DWORD nPort, void* pUserData);	

/**
 * ���ý��������ص������ļ���ʱ�����ļ�������������̺�ʱ�Ƚϳ�����Լ
 * ÿ�봦��40M���ҵ����ݣ���Ϊ��Ӳ�̶����ݱȽ��������������Ĺ�������
 * ��̨��ɣ���Ҫʹ�������ĺ���Ҫ�ȴ�������̽����������ӿڲ���Ӱ�졣
 *
 * @param[in] nPort ͨ����
 * @param[out] pFileRefDoneCBFun ���������ص�����ָ��
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBack(LONG nPort,
													fFileRefDoneCBFun pFileRefDoneCBFunc,
													void* pUserData);
/**
 * ���������ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] bIndexCreated ����������־��TRUE���������ɹ���FALSEʧ��
 * @param[in] pUserData �û��Զ������
 */
typedef void (CALLBACK *fFileRefDoneCBFunEx)(DWORD nPort, BOOL bIndexCreated, void* pUserData);

/**
 * ���ý��������ص������ļ���ʱ�����ļ�������������̺�ʱ�Ƚϳ�����Լ
 * ÿ�봦��40M���ҵ����ݣ���Ϊ��Ӳ�̶����ݱȽ��������������Ĺ�������
 * ��̨��ɣ���Ҫʹ�������ĺ���Ҫ�ȴ�������̽����������ӿڲ���Ӱ�졣
 *
 * @param[in] nPort ͨ����
 * @param[out] pFileRefDoneCBFunEx ���������ص�����ָ��
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBackEx(LONG nPort, fFileRefDoneCBFunEx pFileRefDoneCBFunEx, void* pUserData);

/**
 * ����ָ��λ��֮ǰ�Ĺؼ�֡λ�ã�ͼ��������ӹؼ�֡��ʼ������û�����
 * ���ļ����Ǵӹؼ�֡��ʼ�ģ���ô����һ���ؼ�֮֡ǰ�����ݻᱻ���ԡ���
 * ���û�Ҫ��ȡ�ļ��е�һ�����ݣ���Ӧ�ÿ��Ǵӹؼ�֡��ʼ��ȡ������λ��
 * ���ϵ������ඪʧ3֡���ݡ����ļ�����������ȫ��ǰ���£���
 * PLAY_GetNextKeyFramePos����ʹ�ã���������ʵ�ּ���¼���ļ�����������
 * ��ؼ�֡����йء�
 *
 * @param[in] nPort ͨ����
 * @param[in] nValue ��ǰλ�ã�������ʱ���֡�ţ�������nTypeָ��
 * @param[in] nType ָ��nValue�����͡����nType��BY_FRAMENUM����nValue��ʾ֡�ţ�nType��BY_FRAMETIME����nValue��ʾʱ�䣬��λms��
 * @param[in] pFramePos ���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ�룬���PFRAME_POS��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

/**
 * ����ָ��λ��֮��Ĺؼ�֡λ�á�
 *
 * @param[in] nPort ͨ����
 * @param[in] nValue ��ǰλ�ã�������ʱ���֡�ţ�������nTypeָ��
 * @param[in] nType ָ��nValue�����͡����nType��BY_FRAMENUM,��nValue��ʾ֡�ţ�nType��BY_FRAMETIME,��nValue��ʾʱ��,��λms��
 * @param[in] pFramePos ���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ�룬���PFRAME_POS��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

/**
 * ��ȡ�ļ��������Ա��´δ�ͬһ���ļ�ʱֱ��ʹ�������Ϣ���������������ɺ���ܻ����Ϣ��
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuffer ������Ϣ
 * @param[in/out] pSize ����pBuffer�Ĵ�С�����������Ϣ��С�������ڵ�һ��ָ��pSize=0��pBuffer=NULL��
 *                  ��pSize�ķ���ֵ�����Ҫ�Ļ�������С��Ȼ������㹻�Ļ��壬�ٵ���һ�Ρ�
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);

/**
 * �����ļ�������������Ϣ���䳤�ȱ���׼ȷ������Ѿ������ļ�������Ϣ������
 * ���ٵ������������Ļص�����PLAY_SetFileRefCallBackEx��ֱ������������Ϣ��
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuffer ������Ϣ
 * @param[in] pSize ������Ϣ�ĳ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

/************************************************************************/
//> ��ȡ���Ż������Ϣ
/************************************************************************/

/**
 * ���ý���ص������ͣ���PLAY_Play֮ǰ���á�
 *
 * @param[in] nPort ͨ����
 * @param[in] nStream 1 ��Ƶ����2 ��Ƶ����3 ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCBStream(LONG nPort,DWORD nStream);

/**
 * ����ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pFrameDecodeInfo ����������Ƶ����
 * @param[in] pFrameInfo ͼ���������Ϣ����μ�FRAME_INFO�ṹ��
 * @param[in] pUser �û��Զ������
 */
typedef void (CALLBACK* fCBDecode)(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser);

/**
 * ���ý���ص����滻�������е���ʾ���֣����û��Լ�������ʾ���ú�����
 * PLAY_Play֮ǰ���ã���PLAY_Stopʱ�Զ�ʧЧ���´ε���PLAY_Play֮ǰ
 * ��Ҫ�������á����벿�ֲ������ٶȣ�ֻҪ�û��ӻص������з��أ�������
 * �ͻ������һ�������ݡ�������ֻ���벻��ʾ�����Ρ�
 *
 * @param[in] nPort ͨ����
 * @param[out] cbDec ����ص�����ָ�룬����ΪNULL
 * @param[in] pUser �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

/**
 * ��Ƶץͼ�ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ����ͼ������
 * @param[in] nSize ����ͼ�����ݴ�С
 * @param[in] nWidth �������λ����
 * @param[in] nHeight ����ߣ���λ����
 * @param[in] nStamp ʱ����Ϣ����λ����
 * @param[in] nType �������ͣ�T_RGB32��T_UYVY������궨��˵��
 * @param[in] nReceaved ��Ӧ�û��Զ������
 */
typedef void (CALLBACK* fDisplayCBFun)(LONG nPort,char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nStamp,LONG nType, void* pReserved);

/**
 * ������Ƶץͼ�ص����������Ҫֹͣ�ص������԰ѻص�����ָ����ΪNULL���ú����������κ�ʱ����á�
 *
 * @param[in] nPort ͨ����
 * @param[out] DisplayCBFun ץͼ�ص�����������ΪNULL
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayCallBack(LONG nPort, fDisplayCBFun DisplayCBFun, void* pUserData);

/**
 * ��Ƶ������WAVE���ݻص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pAudioBuf wave��ʽ��Ƶ����
 * @param[in] nSize ��Ƶ���ݳ���
 * @param[in] nStamp ʱ��(ms)
 * @param[in] nType ��Ƶ����T_AUDIO16�� ������8000����������ÿ��������16λ��ʾ
 * @param[in] pUserData �û��Զ�������
 */
typedef void (CALLBACK * fAudioCBFun)(LONG nPort, char * pAudioBuf, LONG nSize, LONG nStamp, LONG nType, void* pUserData);

/**
 * ��Ƶ������WAVE���ݻص���
 *
 * @param[in] nPort ͨ����
 * @param[out] AudioCBFun ��Ƶ����ص�����
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioCallBack(LONG nPort, fAudioCBFun AudioCBFun, void* pUserData);

/**
 * ����ص�����PLAY_SetDecodeCallBack������ͬ����ͬ���ǽ���ص���ͬʱ������ʾ��Ƶ�����鲻Ҫ�ڻص�������������ʱ����߼���������������ʾ����ʱ��
 *
 * @param[in] nPort ͨ����
 * @param[out] cbDec ����ص�����ָ�룬����ΪNULL
 * @param[in] pUser �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
typedef fCBDecode fVisibleDecodeCallBackFunc;
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecodeCallBack(LONG nPort, fVisibleDecodeCallBackFunc cbDec, void* pUser);

/**
 * ����ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ����������Ƶ����
 * @param[in] nSize ����������Ƶ����pBuf�ĳ���
 * @param[in] pFrameInfo ͼ���������Ϣ����μ�FRAME_INFO�ṹ��
 * @param[in] pUserData �û��Զ������
 * @param[in] nReserved2 ��������
 */
typedef void (CALLBACK* fDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved2);

/**
 * ���ý���ص����滻�������е���ʾ���֣����û��Լ�������ʾ���ú�����
 * PLAY_Play֮ǰ���ã���PLAY_Stopʱ�Զ�ʧЧ���´ε���PLAY_Play֮ǰ
 * ��Ҫ�������á����벿�ֲ������ٶȣ�ֻҪ�û��ӻص������з��أ�������
 * �ͻ������һ�������ݡ�������ֻ���벻��ʾ�����Ρ�
 *
 * @param[in] nPort ͨ����
 * @param[out] DecCBFun ����ص�����ָ�룬����ΪNULL
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBack(LONG nPort, fDecCBFun DecCBFun);

/**
 * ���ý���ص����滻�������е���ʾ���֣����û��Լ�������ʾ���ú�����
 * PLAY_Play֮ǰ���ã���PLAY_Stopʱ�Զ�ʧЧ���´ε���PLAY_Play֮ǰ
 * ��Ҫ�������á����벿�ֲ������ٶȣ�ֻҪ�û��ӻص������з��أ�������
 * �ͻ������һ�������ݡ�������ֻ���벻��ʾ�����Ρ�
 *
 * @param[in] nPort ͨ����
 * @param[out] DecCBFun ����ص�����ָ��,����ΪNULL
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBackEx(LONG nPort, fDecCBFun DecCBFun, void* pUserData);

/**
 * ����ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ����������Ƶ����
 * @param[in] nSize ����������Ƶ����pBuf�ĳ���
 * @param[in] pFrameInfo ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
 * @param[in] pUserData �û��Զ������
 * @param[in] nReserved1 ��������
 */
typedef void (CALLBACK* fVisibleDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved1);

/**
 * ����ص�����PLAY_SetDecCallBackEx������ͬ����ͬ���ǽ���ص���ͬʱ����
 * ��ʾ��Ƶ�����鲻Ҫ�ڻص�������������ʱ����߼���������������ʾ����ʱ��
 *
 * @param[in] nPort ͨ����
 * @param[out] DecCBFun ����ص�����ָ��,����ΪNULL
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecCallBack(LONG nPort, fVisibleDecCBFun DecCBFun, void* pUserData);

/**
 * ˮӡ���ݻص�������
 *
 * @param[in] buf ˮӡ����bufferָ��
 * @param[in] key ���ֲ�ͬˮӡ��Ϣ
 * @param[in] len �������󳤶�
 * @param[in] reallen �����ʵ�ʳ���
 * @param[in] len �������󳤶�
 * @param[in] reallen �����ʵ�ʳ���
 * @param[in] type 1û�д���2ˮӡ����3֡���ݴ���4֡�Ŵ���5֡ͷ����6û��֡ͷ
 * @param[in] pUserData �û��Զ������
 * @return int ������
 */
typedef int (CALLBACK* fGetWaterMarkInfoCallbackFunc)(char* buf, LONG key, LONG len, LONG reallen, LONG type, void* pUserData);	

/**
 * ����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ��
 *
 * @param[in] nPort ͨ����
 * @param[out] pFunc ˮӡ�ص�����ָ��
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBack(LONG nPort, fGetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

/**
 * ˮӡ���ݻص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] buf ˮӡ���ݻ���
 * @param[in] lTimeStamp ˮӡ��ʱ���
 * @param[in] lInfoType ˮӡ��Ϣ����,����������,WATERMARK_DATA_TEXT,WATERMARK_DATA_JPEG_BMP,WATERMARK_DATA_FRAMEDATA
 * @param[in] len �������󳤶�
 * @param[in] reallen �����ʵ�ʳ���
 * @param[in] lCheckResult 1û�д���2ˮӡ����3֡���ݴ���4֡�Ŵ���5֡ͷ����6û��֡ͷ
 * @param[in] pUserData �û��Զ������
 * @return int ������
 */
typedef int (CALLBACK* fGetWaterMarkInfoCallbackFuncEx)(LONG nPort, char* buf, LONG lTimeStamp, LONG lInfoType, LONG len, LONG reallen, LONG lCheckResult, void* pUserData);

/**
 * ����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ��
 *
 * @param[in] nPort ͨ����
 * @param[out] pFunc ˮӡ�ص�����ָ��
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBackEx(LONG nPort, fGetWaterMarkInfoCallbackFuncEx pFunc, void* pUserData);

/**
 * ͼ��ֱ��ʸı�֪ͨ�ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pUserData �û��Զ������
 */
typedef void (CALLBACK *fEncChangeCBFun)(LONG nPort, void* pUserData);

/**
 * ����ͼ��ֱ��ʸı�֪ͨ�ص������ļ�ǰʹ�á�
 *
 * @param[in] nPort ͨ����
 * @param[out] EncChangeCBFun �ֱ��ʸı�֪ͨ�ص�
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncTypeChangeCallBack(LONG nPort, fEncChangeCBFun EncChangeCBFun, void* pUserData);

/**
 * ͼ��ֱ��ʸı�֪ͨ�ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pUserData �û��Զ������
 * @param[in] nWidth ͼ���
 * @param[in] nHeight ͼ���
 */
typedef void(CALLBACK *fEncChangeCBFunEx)(LONG nPort, void* pUserData,LONG nWidth, LONG nHeight);

/**
 * ����ͼ��ֱ��ʸı�֪ͨ�ص������ļ�ǰʹ�á�
 *
 * @param[in] nPort ͨ����
 * @param[out] EncChangeCBFun �ֱ��ʸı�֪ͨ�ص�
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncTypeChangeCallBackEx(LONG nPort, fEncChangeCBFunEx EncChangeCBFun, void* pUserData);

/**
 * ��ѯ��Ϣ��
 *
 * @param[in] nPort ͨ����
 * @param[in] cmdType ָ��״̬��ѯָ���CMD_TYPE_E
 * @param[in] buf �����Ϣ�Ļ���
 * @param[in] buflen ���峤��
 * @param[out] returnlen ��ȡ����Ϣ����Ч���ݳ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryInfo(LONG nPort, int cmdType, char* buf, int buflen, int* returnlen);

/**
 * ��ȡ��Ƶʵʱ���ʡ�
 *
 * @param[in] nPort ͨ����
 * @param[out] pBitRate ���������������Ƶ����(��λΪk)
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);

/**
 * ��ȡ�ļ���֡����
 *
 * @param[in] nPort ͨ����
 * @return DWORD����ȡ��ǰ֡��
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameRate(LONG nPort);

/**
 * ��ȡ������ʾ��ͼ���С����������ۣ���Ϊ�����������ͼ�񣩣����ݴ˴�С��������ʾ���ڵ����򣬿��Բ����Կ�������
 * ������������Щ��֧��Ӳ�����ŵ��Կ���˵�ǳ����á�
 *
 * @param[in] nPort ͨ����
 * @param[out] pWidth ͼ���
 * @param[out] pHeight ͼ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);

/**
 * ֡���ݻص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ����ָ��
 * @param[in] nSize ���ݳ���
 * @param[in] pMutexInfo ֡��Ϣ,ָ��DEMUX_INFO�ṹ
 * @param[in] pMutexInfoEx ֡���ݻ������ݣ�ָ��DemuInfoEx�ṹ
 * @param[in] pUserData �û��Զ�������
 */
/* Demux֡���� */
typedef enum
{
	FRAME_UNKNOWN = 0,			// ֡���Ͳ���֪
	FRAME_VIDEO,				// ֡��������Ƶ֡
	FRAME_AUDIO,				// ֡��������Ƶ֡
	FRAME_DATA					// ֡����������֡
}FRAME_TYPE;

/* Demux֡������ */
typedef enum
{
	FRAME_SUB_TYPE_DATA_INVALID = 0,			// ������Ч
	FRAME_SUB_TYPE_VIDEO_I_FRAME = 1,			// I֡
	FRAME_SUB_TYPE_VIDEO_P_FRAME,				// P֡
	FRAME_SUB_TYPE_VIDEO_B_FRAME,				// B֡

	FRAME_SUB_TYPE_VIDEO_SMART_I_FRAME = 19,	// smart I֡
	FRAME_SUB_TYPE_VIDEO_SMART_P_FRAME, 		// smart P֡

	FRAME_SUB_TYPE_DATA_CIPHER_AUXILIARY = 26 	// ���븨��֡
}FRAME_SUB_TYPE;

/* Demux��Ƶ�����ʽ */
typedef enum
{
	ENCODE_VIDEO_UNKNOWN = 0,		// ��Ƶ�����ʽ����֪
	ENCODE_VIDEO_MPEG4,				// ��Ƶ�����ʽ��MPEG4
	ENCODE_VIDEO_HI_H264,			// ��Ƶ�����ʽ�Ǻ�˼H264
	ENCODE_VIDEO_JPEG,				// ��Ƶ�����ʽ�Ǳ�׼JPEG
	ENCODE_VIDEO_DH_H264,			// ��Ƶ�����ʽ�Ǵ�����H264
	ENCODE_VIDEO_JPEG2000 = 6,		// ��Ƶ�����ʽ�Ǳ�׼JPEG2000
	ENCODE_VIDEO_AVS = 7,			// ��Ƶ�����ʽ�Ǳ�׼AVS
	ENCODE_VIDEO_STD_H264 = 8,		// ��Ƶ�����ʽ�Ǳ�׼H264
	ENCODE_VIDEO_MPEG2 = 9,			// ��Ƶ�����ʽ��MPEG2
	ENCODE_VIDEO_VNC = 10,			// ��Ƶ�����ʽ��VNC
	ENCODE_VIDEO_SVAC = 11,			// ��Ƶ�����ʽ��SVAC
	ENCODE_VIDEO_DH_H265 = 12		// ��Ƶ�����ʽ��H265
}ENCODE_VIDEO_TYPE;

/* Demux��Ƶ�����ʽ */
typedef enum 
{
	ENCODE_AUDIO_UNKNOWN = 0,
	ENCODE_AUDIO_PCM = 7,			// ��Ƶ�����ʽ��PCM8
	ENCODE_AUDIO_G729,				// ��Ƶ�����ʽ��G729
	ENCODE_AUDIO_IMA,				// ��Ƶ�����ʽ��IMA
	ENCODE_PCM_MULAW,				// ��Ƶ�����ʽ��PCM MULAW
	ENCODE_AUDIO_G721,				// ��Ƶ�����ʽ��G721
	ENCODE_PCM8_VWIS,				// ��Ƶ�����ʽ��PCM8_VWIS
	ENCODE_MS_ADPCM,				// ��Ƶ�����ʽ��MS_ADPCM
	ENCODE_AUDIO_G711A,				// ��Ƶ�����ʽ��G711A
	ENCODE_AUDIO_AMR,				// ��Ƶ�����ʽ��AMR
	ENCODE_AUDIO_PCM16,				// ��Ƶ�����ʽ��PCM16
	ENCODE_AUDIO_G711U = 22,		// ��Ƶ�����ʽ��G711U
	ENCODE_AUDIO_G723 = 25,			// ��Ƶ�����ʽ��G723
	ENCODE_AUDIO_AAC,				// ��Ƶ�����ʽ��AAC
	ENCODE_AUDIO_G726_40,           // ��Ƶ�����ʽ��G726, 40kbps
	ENCODE_AUDIO_G726_32,           // ��Ƶ�����ʽ��G726, 32kbps
	ENCODE_AUDIO_G726_24,           // ��Ƶ�����ʽ��G726, 24kbps
	ENCODE_AUDIO_G726_16,           // ��Ƶ�����ʽ��G726, 16kbps
	ENCODE_AUDIO_MP2,				// ��Ƶ�����ʽ��mp2
	ENCODE_AUDIO_OGG,				// ��Ƶ�����ʽ��ogg vorbis
	ENCODE_AUDIO_MP3,				// ��Ƶ�����ʽ��mp3
	ENCODE_AUDIO_G722_1,		    // ��Ƶ�����ʽ��G722_1
	ENCODE_AUDIO_OPUS = 38          // ��Ƶ�����ʽ��OPUS
}ENCODE_AUDIO_TYPE;

/* ������װ��ʽ */
typedef enum
{
	STREAM_TYPE_UNKNOWN = 0,        // δ֪����
	STREAM_TYPE_MPEG4,              // MPEG4
	STREAM_TYPE_DHPT =3,	        // ����������DHPT
	STREAM_TYPE_NEW,                // ����������NEW
	STREAM_TYPE_HB,                 // ����������HB
	STREAM_TYPE_AUDIO,              // ��Ƶ��
	STREAM_TYPE_PS,                 // MPEG-2��PS
	STREAM_TYPE_DHSTD,              // �����µı�׼����
	STREAM_TYPE_ASF,                // ASF
	STREAM_TYPE_3GPP,               // 3GP
	STREAM_TYPE_RAW,	            // ����������������
	STREAM_TYPE_TS,                 // MPEG-2��TS
	STREAM_TYPE_SVC,                // svc
	STREAM_TYPE_AVI,                // AVI
	STREAM_TYPE_MP4,                // MP4
	STREAM_TYPE_CGI,                // CGI
	STREAM_TYPE_WAV,		        // WAV��Ƶ
	STREAM_TYPE_FLV,                // FLV

	STREAM_TYPE_MKV,                // mkv
	STREAM_TYPE_RTP,			    // RTP
	STREAM_TYPE_RAW_MPEG4,	        // MPEG4������
	STREAM_TYPE_RAW_H264,	        // H264������
	STREAM_TYPE_RAW_H265,	        // H265������
	STREAM_TYPE_WMV,			    // WMV
	STREAM_TYPE_RAW_MPEG2,	        // MPEG2������
	STREAM_TYPE_RAW_SVAC,	        // SVAC������
	STREAM_TYPE_MOV,
	STREAM_TYPE_VOB,			    // VOB
	STREAM_TYPE_RAW_H263,
	STREAM_TYPE_RM,
	STREAM_TYPE_DHPS,		        // DHPS
}STREAM_TYPE;

/* Demux��չ��Ϣ */
typedef struct 
{
	char*	pHead;				// ֡����(����ͷ)
	int		nLen;				// ֡���ݳ���
	char*	pBody;				// ������(������ͷ)
	int		nBodyLen;			// �����ݳ���

	int		nRet;				// 0:�������� 1:�����룬Ĭ��Ϊ0
	BYTE	nEncryptType;		// �������ͣ�0:������ 1:AES
    BYTE    nRotateAngle;       // ������ת�Ƕ� 0:����ת 1:90����ת 2:180����ת 3:270����ת
	char    reserved1[2];
	int     nStreamType;        // ������װ��ʽ,���STREAM_TYPE����
	char	reserved[120];
}DemuInfoEx;

/* Demux������Ϣ */
typedef struct
{
	int type;			 // ���FRAME_TYPE����
	int subtype;		 // ���FRAME_SUB_TYPE����
	int encode;			 // ���ENCODE_VIDEO_TYPE��ENCODE_AUDIO_TYPE����
	int sequence;		 // ֡���
	int width;			 // ��Ƶ��
	int height;			 // ��Ƶ��
	int rate;			 // ֡��
	int year;			 // ����ʱ����
	int month;           // ����ʱ����
	int day;             // ����ʱ����
	int hour;            // ����ʱ��ʱ
	int minute;          // ����ʱ���
	int secode;          // ����ʱ����
	LONG timestamp;      // ���ʱ���
	int channels;        // ��Ƶͨ����
	int bitspersample;   // ��Ƶ�������
	int samplespersecond;// ��Ƶ������
}DEMUX_INFO;

typedef void (CALLBACK* fDemuxDecCBFun)(LONG nPort,char * pBuf,	LONG nSize,void * pMutexInfo,void* pMutexInfoEx, void* pUserData);

/**
 * ����֡���ݻص���
 *
 * @param[in]  nPort ͨ����
 * @param[out] DecCBFun ֡���ݻص�����
 * @param[in]  pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDemuxCallBack(LONG nPort, fDemuxDecCBFun DecCBFun, void* pUserData);

/**
 * H264��Ϣ��ȡ�ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ����ָ��
 * @param[in] nLen ���ݳ���
 * @param[in] pUserData �û��Զ������
 */
typedef int (CALLBACK *fH264InfoCBFun)(LONG nPort, char* pBuf, LONG nLen, void* pUserData);

/**
 * ����H264��Ϣ��ȡ�ص�������
 *
 * @param[in]  nPort ͨ����
 * @param[out] pH264InfoCBFun H264��Ϣ��ȡ�ص�����
 * @param[in]  nUser �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_Set264EncodeInfoCallBack(LONG nPort, fH264InfoCBFun pH264InfoCBFun, void* nUser);

/**
 * ����aes������Կ��
 *
 * @param[in] nPort ͨ����
 * @param[in] szKey ��Կ��ָ��
 * @param[in] nKeylen ��Կ�ĳ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetSecurityKey(LONG nPort,const char* szKey,DWORD nKeylen);

/*��������*/
typedef enum
{
	ENCRYPT_UNKOWN = 0,
	ENCRYPT_AES,
	ENCRYPT_AES256,
	ENCRYPT_AES256_GDPR2,
	ENCRYPT_SM1_ECB,                     /*���ܼ����㷨SM1_ECB*/       
	ENCRYPT_SM1_OFB,                     /*���ܼ����㷨SM1_OFB*/ 
	ENCRYPT_SM4_ECB,                     /*���ܼ����㷨SM4_ECB*/ 
	ENCRYPT_SM4_OFB,                     /*���ܼ����㷨SM4_OFB*/  //��֪����ʬ�����ֹ��ܼ��ܣ���������SP_ENCRYPT_SM4_OFB
}ENCRYPT_TYPE;

typedef struct
{
	unsigned char x[32];
	unsigned char y[32];
}PUBLICKEY_PARAM;

//���ܲ���
typedef struct
{
	char* Key;                     //AES:key��AES256(GDPRһ��):key�� AES256(GDPR����)�͹���:vkek��  		   
	int KeyLen;			
	char* KeyId;       	           //AES:����� AES256(GDPRһ��):keyid�� AES256(GDPR����)�͹���:vkekid �� 	 
	int KeyIdLen;	
	bool bSetPublicKey;            //�Ƿ����ù�Կ  pPublicKey
	PUBLICKEY_PARAM* pPublicKey;   //svac2.0 ���ܽ�����Ҫ��;  ���඼��NULL
	char Reserved[19];             //�����ֶ�      
}DECRYPT_PARAM; 

/**
 * ����aes������Կ��
 *
 * @param[in] nPort ͨ����
 * @param[in] nType  ��������
 * @param[in] szKey ��Կ��ָ��
 * @param[in] nKeylen ��Կ�ĳ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetSecurityKeyEx(LONG nPort, ENCRYPT_TYPE nType, DECRYPT_PARAM* key, unsigned int key_len);

/************************************************************************/
//> ��ʾ����
/************************************************************************/

/**
 * ���û�������ʾ���򣬿������ֲ��Ŵ���ʾ��
 *
 * @param[in] nPort ͨ����
 * @param[in] nRegionNum ��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������
 * @param[in] pSrcRect �ֲ���ʾ����
 * @param[in] hDestWnd ��ʾ���ھ��
 * @param[in] bEnable ��(����)��ر���ʾ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayRegion(LONG nPort,DWORD nRegionNum, DISPLAYRECT *pSrcRect, HWND hDestWnd, BOOL bEnable);

/**
 * ˢ����ʾ�����û���ͣʱ���ˢ���˴��ڣ��򴰿��е�ͼ����Ϊˢ�¶���ʧ��
 * ��ʱ��������ӿڿ������°�ͼ����ʾ������ֻ������ͣ�͵�֡����ʱ��
 * ִ�У����������ֱ�ӷ��ء�
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlay(LONG nPort);

/************************************************************************/
//> ����������
/************************************************************************/

/**
 *  ��ȡ������ģʽ��Դ������ʣ�����ݴ�С(��λΪ�ֽ�)��
 *
 * @param[in] nPort ͨ����
 * @return DWORD����ǰԴ����Ĵ�С��λBYTE(��λΪ�ֽ�)
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSourceBufferRemain(LONG nPort);

/**
 * ���������ģʽ��Դ��������ʣ�����ݡ�
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBuffer(LONG nPort);

/**
 * ���������ģʽ��Դ��������ʣ�����ݡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] nBufType�����£�
 *			BUF_VIDEO_SRC 1 ��ƵԴ����
 *			BUF_AUDIO_SRC 2 ��ƵԴ����
 *			BUF_VIDEO_RENDER 3 �������Ƶ���ݻ���
 *			BUF_AUDIO_RENDER 4 �������Ƶ���ݻ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetBuffer(LONG nPort,DWORD nBufType);

/**
 * ��ȡָ���������Ĵ�С��
 *
 * @param[in] nPort ͨ����
 * @param[in] nBufType�����£�
 *			BUF_VIDEO_SRC 1 ��ƵԴ����
 *			BUF_AUDIO_SRC 2 ��ƵԴ����
 *			BUF_VIDEO_RENDER 3 �������Ƶ���ݻ���
 *			BUF_AUDIO_RENDER 4 �������Ƶ���ݻ���
 * @return DWORD�����ݲ�ͬ�������ػ�����ֵ��Դ����������byte������󻺳�������֡��
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetBufferValue(LONG nPort,DWORD nBufType);

/************************************************************************/
//> ����Ӳ��
/************************************************************************/

/**
 * ��ʼ��Ӳ��(Windows32ƽ̨)��
 *
 * @return UINT���ɹ�����Ӳ�������� ʧ�ܷ���0
 */
PLAYSDK_API UINT CALLMETHOD PLAY_InitDisk();

/**
 * ���Ȼص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] nPercent ���Ȱٷֱ�, -1��ʾ�쳣
 * @param[in] pUserData �û��Զ������
 */
typedef void (CALLBACK *fPercentCallbackFunc)(LONG nPort, int nPercent, void* pUserData);

/**
 * ���Ȼص��������趨�ļ���ʼ����ʱ�䣬���ָ������ҪPLAY_SetFileRefCallBack�ص������Ч��[0,0] ��ʾ�����ļ���С������Ҫ������������PLAY_OpenFile֮����á�
 *
 * @param[in] nPort ͨ����
 * @param[in] nStartTime �ļ���ʼʱ�䣬 ��λΪ��1970/1/1��ʼ����������
 * @param[in] nEndTime �ļ�����ʱ�䣬 ��λΪ��1970/1/1��ʼ����������
 * @param[out] pFunCallback ���Ȼص�����ָ��
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPercentCallBack(LONG nPort, LONG nStartTime, LONG nEndTime, fPercentCallbackFunc pFunCallback, void* pUserData);

typedef enum
{
	FORMAT_ALL_DATA, //�����������
	FORMAT_KEY_DATA  //����ؼ�������
}FormatType;

/**
 * ��ʽ��Ӳ��(Windows32ƽ̨)��
 *
 * @param[in] disk_no Ҫ��ȡ������Ϣ�Ĵ��̺�
 * @param[in] type ��ʽ��ѡ��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_FormatDisk(UINT disk_no, FormatType type);

/**
 * �ļ���ѯ�붨λ(Windows32ƽ̨)��
 *
 * @param[in] channel ��Ҫ��ѯ��¼���ͨ����
 * @param[in] start_time ¼���ѯ�Ŀ�ʼʱ��
 * @param[in] end_time ¼���ѯ�Ľ���ʱ��
 * @param[in/out] pmax_ret_num �����ѯ������ļ����������ز�ѯ�����ļ��������ļ�ϵͳ���һ�η���pmax_ret_num���������
 * @param[out] pfile_info ��ѯ����¼���ļ���ŵ�λ��
 * @param[in] type ��ѯ��¼���������룬���������졢��ͨ
 * @param[in] hint ��ʱ�����壬�̶�����Ϊ0
 * @param[in] driver_type �������������룬ָ����ĳЩ�����������ڲ�ѯ
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 * �ļ����ֲο�: "/part/uuid/%4d-%02d-%02d/%03d/%02d.%02d.%02d-%02d.%02d.%02d/cType/first_clus_no.dav"
 */
PLAYSDK_API UINT CALLMETHOD PLAY_QueryFileList(UINT nChannel,DHTIME start_time,DHTIME end_time,UINT *pmax_ret_num,pFILE_INFO pfile_info,UINT type, BYTE hint, UINT driver_type);

/************************************************************************/
//> ����
/************************************************************************/

typedef enum
{
	FISHEYEMOUNT_MODE_INVALID = 0,					// ��װģʽ��Ч
	FISHEYEMOUNT_MODE_CEIL = 1,						// ��װ
	FISHEYEMOUNT_MODE_WALL,							// ��װ
	FISHEYEMOUNT_MODE_FLOOR,						// ��װ
	FISHEYEMOUNT_MODE_NUM
}FISHEYE_MOUNTMODE;

typedef enum
{
	FISHEYECALIBRATE_MODE_INVALID = 0,							// ����ģʽ��Ч
	FISHEYECALIBRATE_MODE_OFF = 1,								// �ر������㷨�⣬�ⲿ�ر�
	FISHEYECALIBRATE_MODE_ORIGINAL,								// ԭʼģʽ(������),�����ű���
	FISHEYECALIBRATE_MODE_PANORAMA,								// 1p
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_ONE_EPTZ,				// 1p+1
	FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA,						// 2p
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_DOUBLE_PANORAMA,		// 1+2p
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_THREE_EPTZ_REGION,		// 1+3
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_THREE_EPTZ_REGION,		// 1p+3
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_TWO_EPTZ_REGION,		// 1+2
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_FOUR_EPTZ_REGION,		// 1+4
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_FOUR_EPTZ_REGION,		// 1p+4
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_SIX_EPTZ_REGION,		// 1p+6
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_EIGHT_EPTZ_REGION,		// 1+8
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_EIGHT_EPTZ_REGION,		// 1p+8
	FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION_WITH_ORIGINAL,		// 1F+2	
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_ORIGINAL,		// 1F+4	
	FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA_WITH_ORIGINAL,		// 1F+2p
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_PANORAMA,		// 1p(F)+4
	FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION,		                // 2����
	FISHEYECALIBRATE_MODE_SINGLE,								// ������
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION,						// 4����
	FISHEYECALIBRATE_MODE_USER_DEFINED,				    		// �û��Զ���
	FISHEYECALIBRATE_MODE_PHONE,								// �ֻ�ģʽ
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_ONE_EPTZ_REGION,		// 1+1
	FISHEYECALIBRATE_MODE_ONE_EPTZ_REGION,						// 1����
	FISHEYECALIBRATE_MODE_SEMI_SPHERE,							// ��Բ
	FISHEYECALIBRATE_MODE_CYLINDER,								// Բ��
	FISHEYECALIBRATE_MODE_LITTLE_PLANET,						// С����
	FISHEYECALIBRATE_MODE_DOUBLE_SPHERE,						// ˫Ŀ��
	FISHEYECALIBRATE_MODE_DOUBLE_CYLINDER,						// ˫ĿԲ��
	FISHEYECALIBRATE_MODE_DOUBLE_360,

	FISHEYECALIBRATE_MODE_NUM
}FISHEYE_CALIBRATMODE;

typedef enum
{
	FISHEYEEPTZ_CMD_INVALID = 0,	
	FISHEYEEPTZ_CMD_ZOOM_IN = 1,						// �Ŵ�
	FISHEYEEPTZ_CMD_ZOOM_OUT,							// ��С
	FISHEYEEPTZ_CMD_UP,									// �����ƶ�
	FISHEYEEPTZ_CMD_DOWN,								// �����ƶ�
	FISHEYEEPTZ_CMD_LEFT,								// �����ƶ�
	FISHEYEEPTZ_CMD_RIGHT,								// �����ƶ�
	FISHEYEEPTZ_CMD_ROTATE_CLOCKWISE_AUTO,				// �Զ�˳ʱ����ת
	FISHEYEEPTZ_CMD_ROTATE_ANTICLOCKWISE_AUTO,			// �Զ���ʱ����ת
	FISHEYEEPTZ_CMD_STOP,								// ֹͣ
	FISHEYEEPTZ_CMD_SHOW_REGION,						// ��ѡ�Ŵ�
	FISHEYEEPTZ_CMD_EXIT_SHOW_REGION,					// �˳���ѡ�Ŵ�
	FISHEYEEPTZ_CMD_DEFAULT,						    // �ָ�Ĭ��
	FISHEYEEPTZ_CMD_ORIGIN_ROTATE,						// Բ��ת

	FISHEYEEPTZ_CMD_SET_CUR_REGION = 0x20,              // ����ָ�����ڵ�λ����Ϣ
	FISHEYEEPTZ_CMD_GET_CUR_REGION,                     // ��ȡָ�����ڵ�λ����Ϣ
	FISHEYEEPTZ_CMD_IS_IN_PANORAMA_REGION,              // ������Ƿ��ڵ�ǰȫ������������
	FISHEYEEPTZ_CMD_TAP_VIEW,							// ��ʾָ��λ��,���㼴��
	FISHEYEEPTZ_CMD_SET_FOCUS,	 				        // ���ô���λ����Ϣ
	FISHEYEEPTZ_CMD_GET_FOCUS,							// ��ȡ����λ����Ϣ

	FISHEYEEPTZ_CMD_PTZ_CALI,							// ���������궨
	FISHEYEEPTZ_CMD_GET_PTZ_RLT,						// ��ȡ����������λ��Ϣ
    FISHEYEEPTZ_CMD_SET_CUR_REGION_PTZ,                 // �ⲿֱ������ptzģʽ
    FISHEYEEPTZ_CMD_GET_FOCUS_8192,                     // ��ȡ����λ����Ϣ8192����ϵ
	FISHEYEEPTZ_CMD_NUM
}FISHEYE_EPTZCMD;

typedef enum
{
	FISHEYE_SETPARAM,	// ���ò���
	FISHEYE_GETPARAM	// ��ȡ����
}FISHEYE_OPERATETYPE;

typedef enum
{
	/* ǹ������ */
	IPCTYPE_200WN				= 0,	//
	IPCTYPE_130WN				= 1,
	IPCTYPE_D1WN				= 2,
	IPCTYPE_100WN				= 3,
	IPCTYPE_FE					= 4,	// ����

	//�������
	SPCTYPE_D6501				= 100,	// sony��о65���
	HSPCTYPE_D6A2030E			= 101,	// �󻪻�о2030E��6A���
	HSPCTYPE_D65A2030E			= 102	// �󻪻�о2030E��65A���
}CAM_TYPE;

/* ��ͷ���� */
typedef enum
{
	LENTYPE_NORM				= 0,	// �޻��侵ͷ
	LENTYPE_Lens0361 			= 1,	// 3.6����ǹ����ͷ
	LENTYPE_Lens2880			= 2,	// 130�ȹ��ǹ����ͷ
	LENTYPE_Lens0362 			= 3,	// 3.6����ǹ����ͷ
	LENTYPE_Lens0401 			= 4,	// 4.0����ǹ����ͷ

	LENTYPE_TEST1				= 100	// �����ò���
}LEN_TYPE;

typedef struct
{
	int w;
	int h;
}FISHEYE_SIZE;

typedef struct
{
	short x;
	short y;
}FISHEYE_POINT2D;

typedef struct
{
	FISHEYE_MOUNTMODE     subMountMode;			    // ��ͼ��װģʽ, ����ͼ����У��ģʽΪ�û��Զ���ģʽʱ, ��ֵ��Ч
	FISHEYE_CALIBRATMODE  subCalibrateMode;	        // ��ͼ��У��ģʽ, ����ͼ����У��ģʽΪ�û��Զ���ģʽʱ, ��ֵ��Ч
	FISHEYE_SIZE          imgOutput;                // ��ͼ������ֱ���
	FISHEYE_POINT2D       upperLeft;                // ��ͼ��ƫ��
	int					  reserved[3];				// �����ֽ�
}FISHEYE_SUBMODE;

typedef struct
{
	FISHEYE_SIZE          mainShowSize;		        // ����ʾ���ڷֱ���, �㷨�ݴ�����ʺϵ����Ž��(����������¾����ﵽ�ñ���)
	FISHEYE_SIZE          floatMainShowSize;		// ���˫bufferʱʹ�ã�Ŀǰ��ʱ�������ϵĲ����������������ڵ�����ʾ���ڷֱ���, ����Բ�Ŀ�߱���ҪΪ1:1��������װȫ���Ŀ�߱���ҪΪ16:9
	FISHEYE_SIZE          imgOutput;                // ���ͼ��ֱ���(����ǰ), ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����
	FISHEYE_SUBMODE*	  subMode;                  // ��ģʽ��Ϣ, ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����
	int		              subModeNum;               // ��ģʽ��, ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����
	int                   outputSizeRatio;		    // �ݲ�����, У�����ͼ������ű�,Q8��ʽ,��Χ0-256, 256Ϊ�����������ֱ���
	int                   reserved[1];				// �����ֽ�
}FISHEYE_OUTPUTFORMAT;

typedef struct
{
	int x;
	int y;
	int hAngle;
	int vAngle;
	int available;
	int reserved[3];
}FISHEYE_REGIONPARAM;

typedef struct
{
	FISHEYE_REGIONPARAM   regionParam[9];
	int              circularOffset;
	int              panoramaOffset;
	int              useRegionParam;           // Ϊ1ʱ������Ч��ʹ�ø�ֵ���г�ʼ����û�б�����Ϣʱ����Ϊ0
	int              reserved[1];
}FISHEYE_MODEINITPARAM;

typedef struct
{	
	/*�������*/
	int zoom_type;							// ��������ģʽ----��������Ӧ�䱶�͸��ݿ�ѡĿ���С�䱶����ģʽ
	int hcam_wax;							// ����������Ӧ����Ƕ�x��ˮƽ��
	int hcam_way;							// ����������Ӧ����Ƕ�y����ֱ��
	int hcam_wmul;							// �����������ã���׼������
	int cfg_type;							// ���÷�ʽ��Ĭ��Ϊ1��ʹ�����ò�����ʽ,1��ʹ�ò������÷�ʽ��0��ʹ���豸�������÷�ʽ

	/* ��������� */							         
	/* ��ͷ���� */
	int prm_re;								// ͶӰ�뾶
	int prm_mul;							// ͶӰ����
	int prm_dx;								// x����ƫ��
	int prm_dy;								// y����ƫ��
	int prm_cw;								// CMOS��ʵ��ʹ�ÿ�
	int prm_ch;								// CMOS�ߣ�ʵ��ʹ�øߣ�

	/* ������ʹ�����������ã�cfg_typeΪ0ʱ���øò�������Ч��,Ĭ��130�ȡ�130��ǹ����200W65��� */
	LEN_TYPE mlen_type;						// �������ͷ����
	CAM_TYPE mcam_type;						// ���������
	CAM_TYPE hcam_type;						// ���������

	/* ������� */
	int himg_width;                         // �����ͼ���
	int himg_height;                        // �����ͼ���
	int prm_fax;                            // ���ˮƽ�ӳ���

	/* ��Ĭ�ϵĲ��� */
	/* ��������� */
	int mcam_fc;							// �����Ч����
	int mcam_cw;							// ��ͷ�����
	int mcam_ch;							// ��ͷ����� 
	int cam_height;                         // �������߶ȣ��ף�������ʱδʹ�ã�
	int prm_ma;								// �������

	/* ��������� */
	/* ������� */
	int prm_hw;								// CMOS��
	int prm_hh;								// CMOS��
	int prm_fo;								// ��Ч����
	int prm_ca;								// ��Ұ����
	int prm_mmul;							// �����
}MHFPTZ_CONFIGPARAM;

typedef struct
{
	FISHEYE_SIZE     mainStreamSize;		    // ��Ӧ������ԭʼ��ߣ�������ֱ�����֮����ʱ����Ϊ�������Ǵ˷ֱ������Ŷ���
	int              originX;					// ����ͼ��������Բ��Բ�ĺ�����, ��һ����0-8192����ϵ
	int              originY;					// ����ͼ��������Բ��Բ��������, ��һ����0-8192����ϵ
	int              radius;					// ����ͼ��������Բ�İ뾶, ��һ����0-8192����ϵ
	int              lensDirection;		        // ��ת�Ƕ�, Q7��ʽ, ��Χ0-360*128, һ����Ϊ0
	FISHEYE_MOUNTMODE     mainMountMode;		// ����װģʽ
	FISHEYE_CALIBRATMODE  mainCalibrateMode;	// ͼ����У��ģʽ
	FISHEYE_MODEINITPARAM modeInitParam;        // �ⲿ����ģʽ��ʼ����������Ϣ��������ģʽ�л��ָ�����һ�ε�״̬,
	FISHEYE_OUTPUTFORMAT *outputFormat;         // ���ͼ����Ϣ
	MHFPTZ_CONFIGPARAM   *configParam;          // �����������ò���
	int              enableAutoContrast;        // �����Զ��Աȶ�, 0�ر�, 1����, �ù��ܻ������㷨��ʱ, ��Ҫ���ܺõĻ����Ž��鿪��
	int              alphaHistogram;            // ֱ��ͼIIRǿ��0-255, Ĭ��128, Խ��Խ�ο���ǰ֡
	int              alphaGray;                 // �Ҷ�����ǿ��0-255, Ĭ��245, Խ��Խ�Աȶ���
	FISHEYE_SIZE     captureSize;		        // ��Ӧ��ǰģʽ�µ�ץͼ�ֱ���
	int              mhfptzIndex;               // IN ��������������0,1,2....
	int              reserved[1];				// �����ֽ�
}FISHEYE_OPTPARAM;

typedef struct
{
	FISHEYE_EPTZCMD   ePtzCmd;			// ��̨������˵����FISHEYE_EPtzCmd����
	int          winId;				    // Ҫ����eptz�Ĵ��ڱ�ţ����Ͻ�winIdΪ0�������ҵ���							
	int          arg1;
	int          arg2;
	int          arg3;
	int          arg4;
	int          arg5;
	int          arg6;
	int          reserved0[6];			   // �����ֽ�
	void*        pParam;                   // ��������
	void*        pResult;
	void*        pArg;   

	int          reserved1[7];			   // �����ֽ�
}FISHEYE_EPTZPARAM;

/**
 * ������Ƶ�����㷨���ܣ���Ҫ����fisheye.dll�⡣
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StartFisheye(LONG nPort);

/**
 * ����/��ȡ���۲�����
 *
 * @param[in] nPort ͨ����
 * @param[in] operatetype ��������
 * @param[in/out] pOptParam ���۲���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_OptFisheyeParams(LONG nPort, FISHEYE_OPERATETYPE operatetype, FISHEYE_OPTPARAM* pOptParam);

/**
 * ���ڸ���ģʽ�¿�����رյڶ������۴��ڡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] hDestWnd ��ʾ���ھ��
 * @param[in] pOptParam �ڶ������ڶ�Ӧ�����۲���
 * @param[in] bEnable �򿪻�ر���ʾ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeSecondRegion(LONG nPort, HWND hDestWnd, FISHEYE_OPTPARAM* pOptParam, BOOL bEnable);

/**
 * ����eptz(������̨�������������ƶ���
 *
 * @param[in] nPort ͨ����
 * @param[in/out] pEptzParam ���ڲ���
 * @param[in] bSecondRegion �Ƿ�Ϊ����ģʽ�µĵڶ������ڣ�1Ϊ�棬Ĭ����0
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeEptzUpdate(LONG nPort, FISHEYE_EPTZPARAM* pEptzParam, BOOL bSecondRegion);

/**
 * ֹͣ��Ƶ�����㷨���ܡ�
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StopFisheye(LONG nPort);

/**
 * ������Ϣ�ص�������
 *
 * @param[in] nPort ͨ����
 * @param[in] byCorrectMode ����ģʽ
 * @param[in] wRadius �뾶
 * @param[in] wCircleX Բ�ĺ�����
 * @param[in] wCircleY Բ��������
 * @param[in] widthRatio �����
 * @param[in] heightRatio �߱���
 * @param[in] gain ����
 * @param[in] denoiseLevel ����ȼ�
 * @param[in] InstallStyle ���۰�װ��ʽ
 * @param[in] pUserData �û��Զ������
 */
typedef void (CALLBACK* fFishEyeInfoFun)( 
	LONG nPort,
	BYTE byCorrectMode,
	WORD wRadius,
	WORD wCircleX,
	WORD wCircleY,
	UINT widthRatio,
	UINT heightRatio,
	BYTE gain,
	BYTE denoiseLevel,
	BYTE installStyle,
	void* pUserData );

/**
 * ���û�ȡ������Ϣ�ص���
 *
 * @param[in] nPort ͨ����
 * @param[out] pFishEyeInfoFun ������Ϣ�ص�����ָ�룬����ΪNULL
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFishEyeInfoCallBack(LONG nPort, fFishEyeInfoFun pFishEyeInfoFun, void* pUserData);

/************************************************************************/
//> ץͼ
/************************************************************************/

/**
 * ץͼ����BMPͼƬ����Ϊָ�����ļ���PLAY_SetDisplayCallBack���õ���Ƶ��
 * �ݻص�������ֻ��������Ƶ���ݽ������ʱ�ŵ��ã������û�������Ƶ��
 * ��(��ץͼ)����������н�������ݣ��Ͳ��ϵ�������ص���������PLAY_
 * CatchPicһ��ֻץһ��ͼ����������ͣ�͵�֡����ʱʵ��ץͼ�����飺���
 * �û���ʵ��ץͼ(һ��ץһ��ͼ)������PLAY_CatchPic���������õ�һ��
 * ʱ���ڵ���Ƶ���ݣ�����PLAY_SetDisplayCallBack��
 *
 * @param[in] nPort ͨ����
 * @param[in] sFileName �ļ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPic(LONG nPort,char* sFileName);

/**
* ץͼ����ͼƬ����Ϊָ�����ļ���PLAY_SetDisplayCallBack���õ���Ƶ��
* �ݻص�������ֻ��������Ƶ���ݽ������ʱ�ŵ��ã������û�������Ƶ��
* ��(��ץͼ)����������н�������ݣ��Ͳ��ϵ�������ص���������PLAY_
* CatchPicExһ��ֻץһ��ͼ����������ͣ�͵�֡����ʱʵ��ץͼ�����飺���
* �û���ʵ��ץͼ(һ��ץһ��ͼ)������PLAY_CatchPicEx���������õ�һ��
* ʱ���ڵ���Ƶ���ݣ�����PLAY_SetDisplayCallBack��
 * @param[in] nPort ͨ����
 * @param[in] sFileName �ļ���
 * @param[in] ePicfomat  ͼƬ��ʽ����tPicFormats
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPicEx(LONG nPort,char* sFileName,tPicFormats ePicfomat);

/**
 * ͼ���ʽתΪBMP��ʽ��
 *
 * @param[in] pBuf ͼ������ָ��
 * @param[in] nSize ͼ�����ݴ�С
 * @param[in] nWidth ͼ����
 * @param[in] nHeight ͼ��߶�
 * @param[in] nType �������ͣ���T_YV12��T_UYVY
 * @param[in] sFileName Ҫ������ļ����������BMP��Ϊ�ļ���չ��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName);

/*
 * ͼ���ʽתΪJPEG��ʽ��
 *
 * @param[in] pYUVBuf ͼ������ָ��
 * @param[in] nWidth ͼ����
 * @param[in] nHeight ͼ��߶�
 * @param[in] YUVtype YUV�������ͣ���T_YV12��T_UYVY
 * @param[in] quality ͼƬѹ����������Χ(0, 100]
 * @param[in] sFileName �ļ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToJpegFile(char *pYUVBuf, LONG nWidth, LONG nHeight, int YUVtype, int quality, char *sFileName);

/**
 * ץȡBMPͼ��
 *
 * @param[in] nPort ͨ����
 * @param[in] pBmpBuf ���BMPͼ�����ݵĻ����ַ�����û����䣬����С��bmp ͼ���С��
 *               �Ƽ���С��sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4��
 *        ����w��h�ֱ�Ϊͼ����
 * @param[in] dwBufSize ��������С
 * @param[out] pBmpSize ��ȡ����ʵ��bmpͼ���С
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMP(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize);

/**
 * ץȡBMPͼ��
 *
 * @param[in] nPort ͨ����
 * @param[in] pBmpBuf   ���BMPͼ�����ݵĻ����ַ�����û����䣬����С��bmp ͼ���С��
 *   �Ƽ���С��sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4��
 *   ����w��h�ֱ�Ϊͼ���ߡ�
 * @param[in] dwBufSize ��������С
 * @param[out] pBmpSize ��ȡ����ʵ��bmpͼ���С
 * @param[in] nWidth ָ����bmp�Ŀ�
 * @param[in] nHeight ָ����bmp�ĸ�
 * @param[in] nRgbType ָ��RGB��ʽ 0��RGB32��1��RGB24��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMPEx(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize, LONG nWidth, LONG nHeight, int nRgbType);

/**
 * ץȡJPEGͼ��
 *
 * @param[in] nPort ͨ����
 * @param[in] pJpegBuf ���JPEGͼ�����ݵĻ����ַ�����û����䣬����С��JPEGͼ���С��
         �Ƽ���С��w*h*3/2������w��h�ֱ�Ϊͼ����
 * @param[in] dwBufSize ��������С
 * @param[out] pJpegSize ��ȡ����ʵ��JPEGͼ���С
 * @param[in] quality JPEGͼ���ѹ��������ȡֵ��ΧΪ(0,100]
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicJPEG(LONG nPort, PBYTE pJpegBuf, DWORD dwBufSize, DWORD* pJpegSize, int quality);

/**
 * ץȡTIFFͼ��
 *
 * @param[in] nPort ͨ����
 * @param[in] pTiffBuf ���TIFFͼ�����ݵĻ����ַ�����û����䣬����С��tiffͼ���С��
   �Ƽ���С��w*h*3+1024��
   ����w��h�ֱ�Ϊͼ����
 * @param[in] dwBufSize ��������С
 * @param[out] pTiffSize ��ȡ����ʵ��TIFFͼ���С
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicTIFF(LONG nPort, PBYTE pTiffBuf, DWORD dwBufSize, DWORD* pTiffSize);

/**
 * ץͼ����ѡ���ʽ��ָ����ߡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] sFileName �ļ���
 * @param[in] lTargetWidth ָ����ͼ����
 * @param[in] lTargetHeight ָ����ͼ��߶�
 * @param[in] ePicfomat ͼƬ��ʽ�����tPicFomats
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

/************************************************************************/
//> ��ͼ�ص�
/************************************************************************/

/*
 *��ͼ�ص�����
 * 
 * @param[in] nPort ͨ����
 * @param[in] hDc OffScreen�����豸������
 * @param[in] pUserData �û��Զ������
 */
typedef void (CALLBACK* fDrawCBFun)(LONG nPort,HDC hDc, void* pUserData);

/*
 * ע��һ���ص���������õ�ǰ�����device context������������DC�ϻ�ͼ(������)��
 * �ͺ����ڴ��ڵĿͻ���DC�ϻ�ͼ�������DC���Ǵ��ڿͻ�����DC������DirectDraw��
 * ��Off-Screen�����DC��ע�⣬�����ʹ��overlay���棬����ӿ���Ч������ֱ����
 * �����ϻ�ͼ��ֻҪ����͸��ɫ�Ͳ��ᱻ���ǡ�
 *
 * @param[in] nPort ͨ����
 * @param[out] DrawFun ��ͼ�ص�����
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFun(LONG nPort, fDrawCBFun DrawCBFun, void* pUserData); 

/*
 *��ͼ�ص�����
 * 
 * @param[in] nPort ͨ����
 * @param[in] nReginNum ��ʾ������ţ���Χ[0,(MAX_DISPLAY_WND-1)]�����nRegionNumΪ0��
 *   �����õ�������ʾ���������С�
 * @param[in] hDc OffScreen�����豸������
 * @param[in] pUserData �û��Զ������
 */
typedef void (CALLBACK* fDrawCBFunEx)(LONG nPort,LONG nReginNum,HDC hDc, void* pUserData);

/*
 * ע��һ���ص���������õ�ǰ�����������(HDC)�����DC���Ǵ��ڿͻ�����DC��
 * ����DirectDraw���Off-Screen�����DC��ע�⡣�����ʹ��overlay���棬
 * ����ӿ���Ч��overlay��ʽ����ֱ���ڴ����ϻ�ͼ��ֻҪ����͸��ɫ�Ͳ��ᱻ���ǡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] nReginNum ��ʾ������ţ���Χ[0,(MAX_DISPLAY_WND-1)]�����nRegionNumΪ0��
 *   �����õ�������ʾ����������
 * @param[out] DrawFunEx ��ͼ�ص�����
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFunEx(LONG nPort, LONG nReginNum, fDrawCBFunEx DrawFunEx, void* pUserData);

/************************************************************************/
//> ¼�ƻ�ת�빦��
/************************************************************************/

/*
 * ��ʼԤ¼��
 *
 * @param[in] nPort ����ͨ��
 * @param[in] sFileName ¼��λ��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StartPrepareRecord(LONG nPort,const char* pFileName);

/*
 * ֹͣԤ¼��
 *
 * @param[in] nPort ����ͨ��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StopPrepareRecord(LONG nPort);

/*
 * ��ʼ������¼��ֻ����ģʽ���ã���PLAY_Play֮����á�
 *
 * @param[in] nPort ͨ����
 * @param[in] sFileName �ļ���
 * @param[in] idataType ȡֵDATA_RECORD_TYPE
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
typedef enum
{
	DATA_RECORD_ORIGINAL = 0,     // ¼��ԭʼ��Ƶ��
	DATA_RECORD_AVI,              // ¼��AVI
	DATA_RECORD_ASF,              // ¼��ASF  
	DATA_RECORD_ORIGINAL_SEGMENT, // ¼�Ʒֶε�ԭʼ��Ƶ�����������ֶ�������ʹ��PLAY_StartDataRecordEx�ӿڣ�
	DATA_RECORD_RESIZE_AVI,       // ¼��ת��ֱ��ʵ�AVI��ʹ��PLAY_ResolutionScale���ÿ��
	DATA_RECORD_MP4,              // ¼��MP4
	DATA_RECORD_RESIZE_MP4,       // ¼��ת��ֱ��ʵ�MP4��ʹ��PLAY_ResolutionScale���ÿ��
	DATA_RECORD_MP4_NOSEEK,       // ¼�Ʋ���дMP4 
    DATA_RECORD_RESIZE_MP4_NOSEEK,// ¼��ת��ֱ��ʵĲ���дMP4��ʹ��PLAY_ResolutionScale���ÿ��
	DATA_RECORD_TS,               // ¼��TS
    DATA_RECORD_PS,               // ��׼PS��װ
    DATA_RECORD_RESIZE_DAV,       // ¼��DAV(��Ҫ���±����) 
	DATA_RECORD_DAV,              // ¼��DAV(����Ҫ���±����)

	// �����Ҫ����ö�٣��ڴ�֮ǰ����
	DATA_RECORD_COUNT			  // ¼��������Ŀ 
}DATA_RECORD_TYPE;
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecord(LONG nPort, char *sFileName, int idataType);

/*
 * ����ԭʼ�������ýӿ�����PLAY_StartDataRecord����PLAY_StartDataRecordEx�����ʹ�á�
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ������
 * @param[in] nSize ��С
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_WriteData(LONG nPort, PBYTE pBuf,DWORD nSize);

/*
 * ֹͣ������¼��
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDataRecord(LONG nPort);

/*
 * �ص����� AVIConvertCallback��
 *
 * @param[in] nPort ͨ����
 * @param[in] lMediaChangeType AVI_MEDIACHANGE_FRAMERATE��ʾ֡�ʸı䣻AVI_MEDIACHANGE_RESOLUTION��ʾ�ֱ��ʸı�
 * @param[in] pUserData �û��Զ������
 * @param[out] pIsNewFile TRUE �ֶ�ת����FALSE ���ֶΣ�Ĭ�ϲ��ֶ�
 * @param[out] sNewFileName ����ֶ�ת�����µ�¼���ļ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
typedef void (CALLBACK* fAVIConvertCallback)(LONG nPort, LONG lMediaChangeType, void* pUserData, BOOL *pIsNewFile, char *sNewFileName);

/*
 * ��ʼAVIת��������AVIת��״̬�ص���
 *
 * @param[in] nPort ͨ����
 * @param[in] sFileName �ļ���
 * @param[out] pAVIFunc �ص�����
 * @param[in] pUserData �û��Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIConvert(LONG nPort, char *sFileName, fAVIConvertCallback pAVIFunc, void* pUserData);

/*
 * ֹͣAVIת����
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIConvert(LONG nPort);

/************************************************************************/
//> ���뼰��ʾ����
/************************************************************************/

/*
 * ָ��������(Windowsƽ̨)�� PLAY_Play֮ǰ������Ч��
 *
 * @param[in] nPort ͨ����
 * @param[in] decodeType ����ģʽ��������H264�� Hevc)
 * @param[in] renderType ��Ⱦģʽ
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEngine(LONG nPort,DecodeType decodeType,RenderType renderType);

/*
 * ����ͼ�������������óɸ�����ʱ����Ч���ã���CPU�����ʸߡ���֧�ֶ�·����ʱ��
 * ������Ϊ���������Խ���CPU�����ʡ���ĳ·�Ŵ󲥷�ʱ����·���óɸ�������
 * �Դﵽ�õĻ���Ч����
 *
 * @param[in] nPort ͨ����
 * @param[in] bHighQuality ΪTRUE(1)ʱͼ���������ΪFALSE(0)ʱ������(Ĭ��ֵ)
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPicQuality(LONG nPort,BOOL bHighQuality);

/*
 * ��ȡͼ��������
 *
 * @param[in] nPort ͨ����
 * @param[out] bHighQuality ���������TRUE��ʾ��������FALSE��ʾ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureQuality(LONG nPort,BOOL *bHighQuality);

/*
 * ��ֱͬ����ʾ���ء��˽ӿ�����PLAY_Play֮����ã����²���ʱ���������á�
 * �ڲ��Ŷ�̬ͼ����ֶϲ�ʱ������ʹ�ô˽ӿڴ򿪴�ֱͬ�����ܡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] bEnable TRUE�򿪴�ֱͬ����FALSE�رմ�ֱͬ��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_VerticalSyncEnable(LONG nPort, BOOL bEnable);

/*
 * �Ƿ����ø���ͼ���ڲ��������ԡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] bEnable ���PLAY_STRATEGE_E����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
typedef enum _PLAY_STRATEGE
{
	PLAY_THROW_FRAME_NO = 0,						// ����֡
	PLAY_THROW_FRAME_FLAG_HIGHT = 1,				// Ĭ�ϲ��Գ�֡������1080P����4����(��)���ϳ�֡��[1080P,720P]����8����(��)���ϳ�֡��С��720P����16����(��)���ϳ�֡
	PLAY_THROW_FRAME_FLAG_ALL = 2,					// ǿ�Ƴ�I֡����
	PLAY_THROW_FRAME_FLAG_ADAPTION = 3,				// ����Ӧ����������֡
	PLAY_THROW_FRAME_FLAG_ADAPTION_LOW_CPU = 4,		// ����Ӧ����������֡����cpuռ����
} PLAY_STRATEGE_E;
PLAYSDK_API BOOL CALLMETHOD PLAY_EnableLargePicAdjustment(LONG nPort, int bEnable);

/*
 * ���ý����߳�����
 *
 * @param[in] nPort ͨ����
 * @param[in] nNum �߳���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeThreadNum(LONG nPort, DWORD nNum);

/*
 * ���ý�����ԣ������������������롣
 *
 * @param[in] nPort ͨ����
 * @param[in] nStrategyType 
 *				16: ��ʾ����������frame����������ǰ����
 *               8: ��ʾ�����������������ݲ�����Э�鵱�ɽ������
 *				 0 : ��ʾ�����������������ݲ�����Э��������룬���������Ứ��
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeStrategy(LONG nPort, int nStrategyType);

/*
 * �����ʹ�ܿ��أ���֧��Windows��
 *
 * @param[in] nPort ͨ����
 * @param[in] bEnable TRUE�򿪿���ݴ���FALSE�رտ���ݴ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_AntiAliasEnable(LONG nPort, BOOL bEnable);

/************************************************************************/
//> ˽������
/************************************************************************/

/*
 * ��ʾ˽�����ݣ��������򣬹���򱨾����ƶ����ȡ�
 *
 * @param[in] nPort ͨ����
 * @param[in] bTrue TRUE���� FALSE���ر�
 * @param[in] nReserve ��������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_RenderPrivateData(LONG nPort, BOOL bTrue, LONG nReserve);

/*
 * ����֡�ص� PLAY_SetDataCallBack��
 *
 * @param[in] nPort ͨ����
 * @param[in] pBuf ����ͷ��ԭʼ����
 * @param[in] nSize  ���ݴ�С
 * @param[in] pUserData  �û��Զ�������
 */
typedef void (CALLBACK* fDataCBFun)(LONG nPort,char * pBuf,LONG nSize, void* pUserData);

/*
 * ����֡�ص����ص�����ͷ��ԭʼ���ݣ�����Լ�ʵ�ֽ�����
 *
 * @param[in] nPort ͨ����
 * @param[out] pDataCBFun �ص�����
 * @param[in] pUserData �û��Զ�������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDataCallBack(LONG nPort, fDataCBFun pDataCBFun, void* pUserData);

/*
 * IVS����ص�������
 *
 * @param[in] pIVSBuf ����֡����(json������֡�ṹ������)����Ϊ����֡�ṹ������ʱ��pIVSBufΪIVS Object�ṹ���������ʼ��ַ
 * @param[in] nIVSType ����֡��������,���IVS_TYPE
 *			ȡֵΪIVSINFOTYPE_RAWDATAʱ����Ӧԭʼjson����
 *			ȡֵΪIVSINFOTYPE_TRACKʱ������IVS object��Ӧ�ṹ�� SP_IVS_OBJ_EX��
 *			ȡֵΪIVSINFOTYPE_TRACK_EX_B0ʱ������IVS object��Ӧ�ṹ�� SP_IVS_COMMON_OBJ��
 * @param[in] nIVSBufLen ����֡���ݳ���(json������֡�ṹ������)��
 *			  ��Ϊ����֡�ṹ������ʱ��nIVSBufLenΪIVS Object�ĸ������Ե���IVS object�ĳ��ȣ�����IVS object�ĳ��ȿ���type��ע���ͻ��
 * @param[in] nFrameSeq ����֡id
 * @param[in] pReserved ��������
 * @param[in] pUserData �Զ������
 */
/* IVS���� */
typedef enum _IVS_TYPE
{
	IVSINFOTYPE_PRESETPOS			= 1,						
	IVSINFOTYPE_MOTINTRKS			= 2,				
	IVSINFOTYPE_MOTINTRKS_EX		= 3,			
	IVSINFOTYPE_LIGHT				= 4,			
	IVSINFOTYPE_RAWDATA				= 5,   // jason����
	IVSINFOTYPE_TRACK				= 6,   // ���ܷ�����Ϣ 
	IVSINFOTYPE_TRACK_EX_B0			= 7,   // ���ܽṹ��������Ϣ
	IVSINFOTYPE_MOTIONFRAME			= 9,	

	IVSINFOTYPE_VIDEO_CONCENTRATION = 10,
	IVSINFOTYPE_OVERLAY_PIC			= 11,	// ����ͼƬ֡
	IVSINFOTYPE_OSD_INFO			= 12,	// OSD����֡
	IVSINFOTYPE_GPS_INFO			= 13,  // GPS����֡
	IVSINFOTYPE_TAGGING_INFO		= 14,  // �������Ϣ��ע֡������֡(0x13)
	IVSINFOTYPE_TRACK_A1			= 15,  // NVRŨ����Ϣ�켣��
	IVSINFOTYPE_DATA_WITH_LARGE_AMOUNT = 16,
    IVSINFOTYPE_TRACK_A1_EX         = 17,  // NVRŨ����Ϣ�켣��(��չ)
	IVSINFOTYPE_DATA_WITH_WATER_LEVEL_MONITOR = 18, //ˮλ���ˮλ����Ϣ֡(0x17)
	IVSINFOTYPE_INTELFLOW			= 19,  // ���ܿ�����
	IVSINFOTYPE_DATA_WITH_SOUND_DECIBEL = 20,	//���������ֱ�ֵ��Ϣ֡(0x18)
	IVSINFOTYPE_DATA_WITH_SMART_MOTION = 21,	//���ܶ�����Ϣ֡(0x19)
}IVS_TYPE;

/* IVSINFOTYPE_OVERLAY_PIC���Ͷ�Ӧ�Ľṹ */
typedef struct 
{
	unsigned char nOverLayPicPurpose;	// ����ͼƬ��;
	unsigned char nOverLayPicAction;	// ����ͼƬ����
	unsigned char nOverLayPicCodeFormat;// ����ͼƬ�����ʽ
}OVERLAY_PIC_INFO;

/* IVSINFOTYPE_OSD_INFO���Ͷ�Ӧ�Ľṹ */
typedef struct 
{
	unsigned short nOsdTopLeftCornercoordinateX; // �ַ������������Ͻ�x����
	unsigned short nOsdTopLeftCornercoordinateY; // �ַ������������Ͻ�y���� 
	unsigned char  nOsdWordSize;				 // �ֺ�(�ַ���С)
	unsigned char  nOsdWordAlignment;			 // �ַ����뷽ʽ
	unsigned char  reverse[6];
	unsigned int   nOsdRgbaValue;				 // �ַ���ɫ	
}OSD_DATA_INFO;

typedef void (CALLMETHOD *fIVSInfoCallbackFunc)(char* pIVSBuf, LONG nIVSType, LONG nIVSBufLen, LONG nFrameSeq, void* pReserved, void* pUserData);

/*
 * IVS��Ϣ��ȡ������
 *
 * @param[in] nPort ͨ����
 * @param[out] pFunc ����ص�����
 * @param[in] pUserData �Զ������
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIVSCallBack(LONG nPort, fIVSInfoCallbackFunc pFunc, void* pUserData);

/*
 * GPS��Ϣ�ص�������
 *
 * @param[in] pBuf ����֡����
 * @param[in] nLen ����֡���� 
 * @param[in] pUserData �Զ���
 * @return int ������
 */
typedef int (CALLBACK *fGPSInfoCallbackFunc)(char* pBuf, LONG nLen, void* pUserData);

/*
 * GPS��Ϣ��ȡ������
 *
 * @param[in] nPort ͨ����
 * @param[out] pFunc �ص�����  
 * @param[in] pUserData �Զ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetGPSCallBack(LONG nPort, fGPSInfoCallbackFunc pFunc, void* pUserData);

/* ͳ����Ϣ���� */
typedef enum _STATISTIC_TYPE
{
	TYPE_UNUSE			= 0,		// δʹ������
	INPUT_DATA_INTERVAL,			// ���������ݼ��,����1Ϊʱ����������2Ϊ���ݳ���
	PRASE_VIDEO_INTERVAL,			// ��Ƶ֡�������������1Ϊʱ����������2λ֡��
	VIDEO_PTS_INTERVAL,				// ��Ƶpts���������1Ϊʱ����������2Ϊ֡��
	DECODE_VIDEO_TIME,				// ��Ƶ�����ʱ������1Ϊ�ӿں�ʱ������2Ϊ֡��
	PLAY_VIDEO_INTERVAL,			// ��Ƶ֡���ż��������1Ϊʱ����������2Ϊ֡��
	RENDER_VIDEO_TIME,				// ��Ƶ��Ⱦ��ʱ������1Ϊ�ӿں�ʱ
	VIDEO_DECODE_ERROR = 1000,		// ��Ƶ���뱨������1�����壬����2Ϊ֡��
}STATISTIC_TYPE;

/* ͳ����Ϣ��Ӧ�Ľṹ */
typedef struct statistic_info
{
	LONG			nPort;				// ͨ����
	LONG			nStatisticType;		// ��Ϣ����
	LONGLONG		nParam1;			// ����1
	LONGLONG		nParam2;			// ����2
	char			szReserved[16];		// ��������
} STATISTIC_INFO, *PSTATISTIC_INFO;

/*
 * ���벥��ͳ����Ϣ�ص�
 *
 * @param[in] pStatisticData ͳ������
 * @param[in] pUserData �Զ������
 * @return int ������
 */
typedef int (CALLBACK *fStatisticCallbackFunc)(PSTATISTIC_INFO pStatisticData, void* pUserData);

/*
 * ͳ����Ϣ��ȡ������
 *
 * @param[in] nPort,ͨ����
 * @param[out] pFunc �ص�����  
 * @param[in] pUserData �Զ���
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetStatisticCallBack(LONG nPort, fStatisticCallbackFunc pFunc, void* pUserData);

/*
 * ����ͼ����ʾ����
 *
 * @param[in] nPort,ͨ����
 * @param[in] nWidthProportion  ��ֵ��ͼ���߱�
 * @param[in] nHeightProportion ��ֵ��ͼ���߱�	
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetViewProportion(LONG nPort, int nWidthProportion, int nHeightProportion);

/************************************************************************/
//> ���Ƽ�ʹ�õĽӿ�
/************************************************************************/

/*
 * ��ȡ�����룬�˽ӿ���Ч����ʹ��PLAY_GetLastErrorEx�ӿڡ�
 *
 * @param[in] nPort,ͨ����
 * @return DWORD����ô����롣
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_GetLastError(LONG nPort);

/*
 * ���ļ����Զ�����ͨ���š�
 *
 * @param[in] sFileName �ļ���
 * @return DWORD��ʧ�ܷ���0�����򷵻�ͨ����
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateFile(LPSTR sFileName);

/*
 * �رղ����ļ����ͷ��Զ������ͨ���š�
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyFile(LONG nPort);

/*
 * �����ӿڲ��Զ�����ͨ���š�
 *
 * @param[in] nBufPoolSize �ò������д���������Ļ�������С����Χ��[SOURCE_BUF_MIN,SOURCE_BUF_MAX]
 * @return DWORD,ʧ�ܷ���0�����򷵻�ͨ����
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateStream(DWORD nBufPoolSize);

/*
 * �ر������������ͷ��Զ������ͨ���š�
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyStream(LONG nPort);

/*
 * ��PLAY_OneByOneBack�ظ�����ʹ��PLAY_OneByOneBack��
 *
 * @param[in] nPort ͨ����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_BackOne(LONG nPort);

/*
 * ���÷ֱ��ʸı�֪ͨ��Ϣ��
 *
 * @param[in] nPort ͨ����
 * @param[in] hWnd ��Ϣ���͵Ĵ���
 * @param[in] nMsg �û��������Ϣ��������ʱ�����ʽ�����ı�ʱ�û���hWnd���ڹ������յ������Ϣ
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);

/*
 * �����ļ�����ʱҪ���͵���Ϣ��
 *
 * @param[in] nPort ͨ����
 * @param[in] hWnd ��Ϣ���ʹ���
 * @param[in] nMsg �û��Զ�����������Ϣ�������ŵ��ļ�����ʱ�û���hWnd���ڹ�����
 * @return BOOL���ɹ�����TRUE��ʧ�ܷ���FALSE
 * @note �������ʧ�ܣ����Ե���PLAY_GetLastErrorEx�ӿڻ�ȡ�����롣
 */
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);

#ifdef __cplusplus
}
#endif

#endif
