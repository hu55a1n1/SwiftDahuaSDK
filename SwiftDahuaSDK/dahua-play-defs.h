/************************************************************************/
/* dhplay   版本:  3.34			                                    */
/************************************************************************/

#ifndef _DHPLAY_DEFS_H
#define _DHPLAY_DEFS_H

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
#define LONG		long
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

typedef struct _tagRECT
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
}DISPLAYRECT;

#ifdef	__cplusplus
extern "C" {
#endif

/************************************************************************/
/* 宏定义			                                                    */
/************************************************************************/

#define  FUNC_MAX_PORT					501		//最大通道号

#define MIN_WAVE_COEF					-100	//PLAY_AdjustWaveAudio使用
#define MAX_WAVE_COEF					100		//PLAY_AdjustWaveAudio使用

#define TIMER_1							1		//多媒体定时器
#define TIMER_2							2		//线程定时器

#define BUF_VIDEO_SRC					1		//视频源缓冲
#define BUF_AUDIO_SRC					2		//音频源缓冲
#define BUF_VIDEO_RENDER				3		//解码后视频数据缓冲
#define BUF_AUDIO_RENDER				4		//解码后音频数据缓冲

#define MAX_DISPLAY_WND					4

#define DISPLAY_NORMAL					1		//正常分辨率显示
#define DISPLAY_QUARTER					2		//1/4分辨率显示

#define MAX_DIS_FRAMES					50		//播放缓冲区最大缓冲帧数
#define MIN_DIS_FRAMES					6		//播放缓冲区最小缓冲帧数

#define BY_FRAMENUM						1		//按帧号方式(PLAY_GetKeyFramePos使用)
#define BY_FRAMETIME					2		//按时间方式(PLAY_GetKeyFramePos使用)

#define SOURCE_BUF_MAX					1024*100000	//数据流缓冲区最大长度
#define SOURCE_BUF_MIN					1024*50		//数据流缓冲区最小长度

#define STREAME_REALTIME				0		//实时流模式
#define STREAME_FILE					1		//文件流模式

#define T_AUDIO16						101		//16位音频数据类型
#define T_AUDIO8						100		//8位音频数据类型

#define T_UYVY							1		//UYVY类型的YUV数据,现在不支持.
#define T_IYUV							3		//IYUV(I420)类型YUV数据
#define T_RGB32							7		//RGB32类型

#define SUPPORT_DDRAW					1		//支持DIRECTDRAW,如果不支持,则播放器不能工作
#define SUPPORT_BLT						2		//显卡支持BLT操作,如果不支持,则播放器不能工作
#define SUPPORT_BLTFOURCC				4		//显卡BLT支持颜色转换,如果不支持,播放器会使用软件方式作RGB转换
#define SUPPORT_BLTSHRINKX				8		//显卡BLT支持X轴缩小,如果不支持,系统使用软件方式转换
#define SUPPORT_BLTSHRINKY				16		//显卡BLT支持Y轴缩小,如果不支持,系统使用软件方式转换
#define SUPPORT_BLTSTRETCHX				32		//显卡BLT支持X轴放大,如果不支持,系统使用软件方式转换
#define SUPPORT_BLTSTRETCHY				64		//显卡BLT支持Y轴放大,如果不支持,系统使用软件方式转换
#define SUPPORT_SSE						128		//CPU支持SSE指令,Intel Pentium3以上支持SSE指令
#define SUPPORT_MMX						256		//CPU支持MMX指令集

#define PLAY_CMD_GetTime				1		//编码中时间信息
#define PLAY_CMD_GetFileRate			2		//帧率信息
#define PLAY_CMD_GetMediaInfo			3		//媒体信息
#define PLAY_CMD_GetRenderNum			4		//当前要渲染的帧号
#define PLAY_CMD_GetRenderTime			5		//当前要渲染的时间
#define PLAY_CMD_GetSrcTime				6

#define AVI_MEDIACHANGE_FRAMERATE		1		//帧率改变
#define AVI_MEDIACHANGE_RESOLUTION		2		//分辨率改变

#define WATERMARK_DATA_TEXT				0		//文字
#define WATERMARK_DATA_JPEG_BMP			1		//JPEG或者BMP图片
#define WATERMARK_DATA_FRAMEDATA		3		//帧数据

#define	DH_PLAY_NOERROR					0		//没有错误
#define DH_PLAY_PARA_OVER				1		//输入参数非法
#define DH_PLAY_ORDER_ERROR				2		//调用顺序不对
#define DH_PLAY_TIMER_ERROR				3		//多媒体时钟设置失败
#define DH_PLAY_DEC_VIDEO_ERROR			4		//视频解码失败
#define DH_PLAY_DEC_AUDIO_ERROR			5		//音频解码失败
#define DH_PLAY_ALLOC_MEMORY_ERROR		6		//分配内存失败
#define DH_PLAY_OPEN_FILE_ERROR			7		//文件操作失败
#define DH_PLAY_CREATE_OBJ_ERROR		8		//创建线程事件等失败
#define DH_PLAY_CREATE_DDRAW_ERROR		9		//创建directDraw失败
#define DH_PLAY_CREATE_OFFSCREEN_ERROR	10		//创建后端缓存失败
#define DH_PLAY_BUF_OVER				11		//缓冲区满,输入流失败
#define DH_PLAY_CREATE_SOUND_ERROR		12		//创建音频设备失败
#define DH_PLAY_SET_VOLUME_ERROR		13		//设置音量失败
#define DH_PLAY_SUPPORT_FILE_ONLY		14		//只能在播放文件时才能使用
#define DH_PLAY_SUPPORT_STREAM_ONLY		15		//只能在播放流时才能使用
#define DH_PLAY_SYS_NOT_SUPPORT			16		//系统不支持,解码器只能工作在Pentium 3以上
#define DH_PLAY_FILEHEADER_UNKNOWN		17		//没有文件头
#define DH_PLAY_VERSION_INCORRECT		18		//解码器和编码器版本不对应
#define DH_PLAY_INIT_DECODER_ERROR		19		//初始化解码器失败
#define DH_PLAY_CHECK_FILE_ERROR		20		//文件太短或码流无法识别
#define DH_PLAY_INIT_TIMER_ERROR		21		//初始化多媒体时钟失败
#define DH_PLAY_BLT_ERROR				22		//位拷贝失败
#define DH_PLAY_UPDATE_ERROR			23		//显示overlay失败
#define DH_PLAY_MEMORY_TOOSMALL			24		//缓冲太小


// 大华SVAC解码库宏定义
//SVC  flags
#define SVC_LAYER_BASE    0x0001
#define SVC_LAYER_ENHANCE 0x0002

#define MAX_CUSTOM_EXT_COUNT            8
#define MAX_EXT_ROI_REGION_NUM          32  //最大ROI区域扩展的个数    //标准协议里没规定最大值是多少，这里我们暂定为32应该够用
#define MAX_EXT_EVENT_REGION_NUM        32  //最大监控事件扩展的个数
#define MAX_EXT_ALERT_NUM               32  //最大监控报警扩展的个数

//扩展数据的类型
#define EXT_TYPE_ROI        0x0001      //ROI区域扩展
#define EXT_TYPE_TIME       0x0002      //绝对时间扩展
#define EXT_TYPE_ALERT      0x0004      //报警扩展
#define EXT_TYPE_EVENT      0x0008      //监控事件扩展
#define EXT_TYPE_AUTH       0x0010      //认证数据
#define EXT_TYPE_CUSTOM     0x1000      //自定义扩展


/************************************************************************/
/* 结构体	                                                            */
/************************************************************************/

typedef enum __tPicFormats
{
	PicFormat_BMP = 0,				        //BMP32类型
    PicFormat_JPEG,							//JPEG类型
	PicFormat_JPEG_70,						//70%质量的JPEG类型
	PicFormat_JPEG_50,						//50%质量的JPEG类型
	PicFormat_JPEG_30,						//30%质量的JPEG类型
	PicFormat_JPEG_10,						//10%质量的JPEG类型
	PicFormat_BMP24,                        //BMP24类型
	PicFormat_TIFF							//TIFF类型
} tPicFormats;

typedef struct
{
	LONG			nFilePos;				//指定帧在文件中的偏移位置
	LONG			nFrameLen;				//帧长度
	LONG			nFrameNum;				//帧序号
	LONG			nFrameTime;				//帧时间
	LONG			nErrorFrameNum;			//保留,暂无使用
	SYSTEMTIME*		pErrorTime;				//保留,暂无使用
	LONG			nErrorLostFrameNum;		//保留,暂无使用
	LONG			nErrorFrameSize;		//保留,暂无使用
}FRAME_POS,*PFRAME_POS;

typedef struct
{
	LONG			nWidth;					//画面宽,单位像素.如果是音频数据则为0.
	LONG			nHeight;				//画面高,如果是音频数据则为0
	LONG			nStamp;					//时标信息,单位毫秒
	LONG			nType;					//视频帧类型,T_AUDIO16,T_RGB32,T_IYUV
	LONG			nFrameRate;				//编码时产生的图像帧率
}FRAME_INFO;

typedef struct
{
	#define FRAME_TYPE_VIDEO 0				//视频帧
	#define FRAME_TYPE_AUDIO 1				//音频帧
	int				nFrameType;				//视频帧类型,见上面定义
	int				nFrameSeq;				//帧序号
	int				nStamp;					//时标信息,单位毫秒
	int				nWidth;					//画面宽,单位像素.如果是音频数据则为0.
	int 			nHeight;				//画面高,如果是音频数据则为0
	int				nFrameRate;				//编码时产生的图像帧率
	int				nChannels;				//音频通道数
	int				nBitPerSample;			//音频采样位数
	int				nSamplesPerSec;			//音频采样频率
	int				nRemainData;			//缓冲剩余数据量
	SYSTEMTIME		nDataTime;				//时间
	int				nReserved[59];			//保留字段
}FRAME_INFO_EX;

typedef struct 
{
	int				nFrameType;					//帧类型,定义见FRAME_INFO_EX里nFrameType字段
	
	void*			pAudioData;				//音频数据,如果是音频帧
	int				nAudioDataLen;			//音频数据长度

	void*			pVideoData[3];			//分别表示视频的YUV三个分量
	int				nStride[3];				//分别表示YUV三个分量的跨距
	int				nWidth[3];				//分别表示YUV三个分量的宽度
	int				nHeight[3];				//分别表示YUV三个分量的高度
	int				nReserved[64];			//保留字段
}FRAME_DECODE_INFO;

typedef struct 
{
	int			lWidth;					//画面宽,单位像素.
	int			lHeight;				//画面高
	int			lFrameRate;				//帧率
	int			lChannel;				//音频通道数
	int			lBitPerSample;			//音频采样位数
	int			lSamplesPerSec;			//音频采样频率
}MEDIA_INFO;

typedef struct 
{
	char*			pDataBuf;				//帧数据
	LONG			nSize;					//帧数据长度
	LONG			nFrameNum;				//帧序号
	BOOL			bIsAudio;				//是否音频帧
	LONG			nReserved;				//保留
}FRAME_TYPE;



// 解码附加信息
typedef struct
{
    LONG			nVideoEncodeType;   // 码流类型
    LONG	        nDataLen;           // 解码数据长度
    char*           pUserData;              // 解码信息
    LONG	        nReserved[2];
}FRAME_DEC_EXT_INFO;

// 大华SVAC解码库解码附加信息自定义字段
typedef struct
{
    unsigned char type;             // 信息类型
    unsigned char length;           // 信息长度
    unsigned char *pbuf;            // 信息指针
    unsigned char reserved[2];      // 保留
}DEC_EXT_INFO_CUSTOM;

typedef struct
{
    int flags;                              //扩展数据类型标记

    int time_year;                          //绝对时间扩展
    int time_month;
    int time_day;
    int time_hour;
    int time_minute;
    int time_second;
    int time_sec_fractional;
    int time_frame_num;

    int roi_region_num;                             // ROI区域扩展
    int roi_top_left_x[MAX_EXT_ROI_REGION_NUM];     // ROI区域左上角像素x坐标
    int roi_top_left_y[MAX_EXT_ROI_REGION_NUM];     // ROI区域左上角像素y坐标
    int roi_width[MAX_EXT_ROI_REGION_NUM];          // ROI区域宽度
    int roi_height[MAX_EXT_ROI_REGION_NUM];         // ROI区域高度

    int event_region_num;                           // 监控事件扩展
    int event_num[MAX_EXT_EVENT_REGION_NUM];
    int event_region_event_id[MAX_EXT_EVENT_REGION_NUM][16];

    int alert_num;                                  // 监控报警扩展
    int alert_region_id[MAX_EXT_ALERT_NUM];
    int alert_event_id[MAX_EXT_ALERT_NUM];
    int alert_frame_num[MAX_EXT_ALERT_NUM];

    //认证数据相关参数
    int *auth_buf[2];                               // 认证数据buf, auth_buf[0]是基本层认证数据, auth_buf[1]是增强层认证数据
    int auth_len[2];                                // 认证数据长度, 不存在认证数据时，长度应该设置为 0
    int auth_signature_type[2];
    int auth_hash_hierarchy_flag[2];

    DEC_EXT_INFO_CUSTOM svac_ext_info_custom[MAX_CUSTOM_EXT_COUNT];     // 扩展
}DEC_EXT_PARAM_SVAC;

/***begin鱼眼定义***/
typedef enum
{
	FISHEYEMOUNT_MODE_INVALID = 0,
	FISHEYEMOUNT_MODE_CEIL = 1,						/*顶装*/
	FISHEYEMOUNT_MODE_WALL,							/*壁装*/
	FISHEYEMOUNT_MODE_FLOOR,						/*地装*/
	FISHEYEMOUNT_MODE_NUM
}FISHEYE_MOUNTMODE;

typedef enum
{
	FISHEYECALIBRATE_MODE_INVALID = 0,
	FISHEYECALIBRATE_MODE_OFF = 1,								/*关闭鱼眼算法库，外部关闭*/
	FISHEYECALIBRATE_MODE_ORIGINAL,								/*原始模式(正方形),带缩放比例*/
	FISHEYECALIBRATE_MODE_PANORAMA,								/*1p*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_ONE_EPTZ,				/*1p+1*/
	FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA,						/*2p*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_DOUBLE_PANORAMA,		/*1+2p*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_THREE_EPTZ_REGION,		/*1+3*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_THREE_EPTZ_REGION,		/*1p+3*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_TWO_EPTZ_REGION,		/*1+2*/	
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_FOUR_EPTZ_REGION,		/*1+4*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_FOUR_EPTZ_REGION,		/*1p+4*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_SIX_EPTZ_REGION,		/*1p+6*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_EIGHT_EPTZ_REGION,		/*1+8*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_EIGHT_EPTZ_REGION,		/*1p+8*/
	FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION_WITH_ORIGINAL,		/*1F+2*/	
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_ORIGINAL,		/*1F+4*/	
	FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA_WITH_ORIGINAL,		/*1F+2p*/
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_PANORAMA,		/*1p(F)+4*/
	FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION,		                /*2画面*/
	FISHEYECALIBRATE_MODE_SINGLE,								/*单画面*/
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION,						/*4画面*/
	FISHEYECALIBRATE_MODE_USER_DEFINED,				    		/*用户自定义*/
	FISHEYECALIBRATE_MODE_PHONE,								/*手机模式*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_ONE_EPTZ_REGION,		/*1+1*/
	FISHEYECALIBRATE_MODE_ONE_EPTZ_REGION,						/*1画面*/

	FISHEYECALIBRATE_MODE_NUM
}FISHEYE_CALIBRATMODE;

typedef enum
{
	FISHEYEEPTZ_CMD_INVALID = 0,	
	FISHEYEEPTZ_CMD_ZOOM_IN = 1,						/*放大*/
	FISHEYEEPTZ_CMD_ZOOM_OUT,							/*缩小*/
	FISHEYEEPTZ_CMD_UP,									/*向上移动*/
	FISHEYEEPTZ_CMD_DOWN,								/*向下移动*/
	FISHEYEEPTZ_CMD_LEFT,								/*向左移动*/
	FISHEYEEPTZ_CMD_RIGHT,								/*向右移动*/
	FISHEYEEPTZ_CMD_ROTATE_CLOCKWISE_AUTO,				/*自动顺时针旋转*/
	FISHEYEEPTZ_CMD_ROTATE_ANTICLOCKWISE_AUTO,			/*自动逆时针旋转*/
	FISHEYEEPTZ_CMD_STOP,								/*停止*/
	FISHEYEEPTZ_CMD_SHOW_REGION,						/*框选放大*/
	FISHEYEEPTZ_CMD_EXIT_SHOW_REGION,					/*退出框选放大*/
	FISHEYEEPTZ_CMD_DEFAULT,						    /*恢复默认*/
	FISHEYEEPTZ_CMD_ORIGIN_ROTATE,						/*圆旋转*/

	FISHEYEEPTZ_CMD_SET_CUR_REGION = 0x20,             /*配置指定窗口的位置信息*/
	FISHEYEEPTZ_CMD_GET_CUR_REGION,                    /*获取指定窗口的位置信息*/
	FISHEYEEPTZ_CMD_IS_IN_PANORAMA_REGION,             /*输入点是否在当前全景点链区域内*/
	FISHEYEEPTZ_CMD_TAP_VIEW,							/*显示指定位置,即点即看*/
	FISHEYEEPTZ_CMD_SET_FOCUS,	 				        /*设置窗口位置信息*/
	FISHEYEEPTZ_CMD_GET_FOCUS,							/*获取窗口位置信息*/

	FISHEYEEPTZ_CMD_PTZ_CALI,							/*鱼球联动标定*/
	FISHEYEEPTZ_CMD_GET_PTZ_RLT,						/*获取鱼球联动定位信息*/
	FISHEYEEPTZ_CMD_NUM
}FISHEYE_EPTZCMD;

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
	FISHEYE_MOUNTMODE     subMountMode;			    /*子图像安装模式, 仅当图像主校正模式为用户自定义模式时, 该值有效*/
	FISHEYE_CALIBRATMODE  subCalibrateMode;	        /*子图像校正模式, 仅当图像主校正模式为用户自定义模式时, 该值有效*/
	FISHEYE_SIZE          imgOutput;                /*子图像输出分辨率*/
	FISHEYE_POINT2D       upperLeft;                /*子图像偏移*/
	int					  reserved[3];				/*保留字节*/
}FISHEYE_SUBMODE;

typedef struct
{
	FISHEYE_SIZE          mainShowSize;		        /*暂不启用, 主显示比例, 4:3, 16:9等, 算法据此输出适合的最优结果（不变形情况下尽量达到该比例）*/
	FISHEYE_SIZE          floatMainShowSize;		/*输出双buffer时使用，目前暂时还是用老的操作方法，浮动窗口的主显示窗口分辨率, 浮动圆的宽高比需要为1:1，浮动壁装全景的宽高比需要为16:9*/
	FISHEYE_SIZE          imgOutput;                /*输出图像分辨率(缩放前), 图像主校正模式为用户自定义模式时为外部输入, 其他模式为内部返回*/
	FISHEYE_SUBMODE*	  subMode;                  /*子模式信息, 图像主校正模式为用户自定义模式时为外部输入, 其他模式为内部返回*/
	int		              subModeNum;               /*子模式数, 图像主校正模式为用户自定义模式时为外部输入, 其他模式为内部返回*/
	int                   outputSizeRatio;		    /*暂不启用, 校正输出图像的缩放比,Q8格式,范围0-256, 256为保持最大输出分辨率*/
	int                   reserved[1];				/*保留字节*/
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
	int              useRegionParam;           /*为1时表明有效，使用该值进行初始化；没有保存信息时请置为0*/
	int              reserved[1];
}FISHEYE_MODEINITPARAM;

/*枪机类型*/
typedef enum CAM_TYPE
{
	//枪机类型
	IPCTYPE_200WN				= 0,	//
	IPCTYPE_130WN				= 1,
	IPCTYPE_D1WN				= 2,
	IPCTYPE_100WN				= 3,
	IPCTYPE_FE					= 4,	//鱼眼

	//球机类型
	SPCTYPE_D6501				= 100,	//sony机芯65球机
	HSPCTYPE_D6A2030E			= 101,	//大华机芯2030E，6A球机
	HSPCTYPE_D65A2030E			= 102,	//大华机芯2030E，65A球机
}CAM_TYPE;

/*镜头类型*/
typedef enum LEN_TYPE
{
	LENTYPE_NORM				= 0,	//无畸变镜头
	LENTYPE_Lens0361 			= 1,	//3.6毫米枪机镜头
	LENTYPE_Lens2880			= 2,	//130度广角枪机镜头
	LENTYPE_Lens0362 			= 3,	//3.6毫米枪机镜头
	LENTYPE_Lens0401 			= 4,	//4.0毫米枪机镜头

	LENTYPE_TEST1				= 100,	//调试用参数
}LEN_TYPE;

typedef struct
{	
	/*必设参数*/
	int zoom_type;							//倍数控制模式----期望自适应变倍和根据框选目标大小变倍两种模式
	int hcam_wax;							//期望倍数对应球机角度x（水平）
	int hcam_way;							//期望倍数对应球机角度y（垂直）
	int hcam_wmul;							//期望倍数设置（基准倍数）
	int cfg_type;							//配置方式，默认为1：使用配置参数方式,1：使用参数配置方式，0：使用设备类型配置方式

	//主相机参数							         
	//镜头参数
	int prm_re;								//投影半径
	int prm_mul;							//投影倍率
	int prm_dx;								//x方向偏移
	int prm_dy;								//y方向偏移
	int prm_cw;								//CMOS宽（实际使用宽）
	int prm_ch;								//CMOS高（实际使用高）

	//主相机和从相机类型配置（cfg_type为0时设置该参数才有效）            //默认130度、130万枪机和200W65球机
	LEN_TYPE mlen_type;						//主相机镜头类型
	CAM_TYPE mcam_type;						//主相机类型
	CAM_TYPE hcam_type;						//从相机类型

	//球机参数
	int himg_width;                         //从相机图像宽
	int himg_height;                        //从相机图像高
	int prm_fax;                            //球机水平视场角

	/*可默认的参数*/
	//主相机参数
	int mcam_fc;							//相机等效焦距
	int mcam_cw;							//镜头靶面高
	int mcam_ch;							//镜头靶面宽 
	int cam_height;                         //相机架设高度（米），（暂时未使用）
	int prm_ma;								//焦距参数

	//从相机参数
	//球机参数
	int prm_hw;								//CMOS宽
	int prm_hh;								//CMOS高
	int prm_fo;								//等效焦距
	int prm_ca;								//视野参数
	int prm_mmul;							//最大倍率
}MHFPTZ_CONFIGPARAM;

typedef struct
{
	FISHEYE_SIZE     mainStreamSize;		    /*对应主码流原始宽高，当传入分辨率与之不等时表明为辅码流是此分辨率缩放而来*/
	int              originX;					/*输入图像中鱼眼圆的圆心横坐标, 归一化至0-8192坐标系*/
	int              originY;					/*输入图像中鱼眼圆的圆心纵坐标, 归一化至0-8192坐标系*/
	int              radius;					/*输入图像中鱼眼圆的半径, 归一化至0-8192坐标系*/ 
	int              lensDirection;		        /*旋转角度, Q7格式, 范围0-360*128, 一般配为0*/
	FISHEYE_MOUNTMODE     mainMountMode;		/*主安装模式*/
	FISHEYE_CALIBRATMODE  mainCalibrateMode;	/*图像主校正模式*/
	FISHEYE_MODEINITPARAM modeInitParam;        /*外部传入模式初始化各画面信息，适用于模式切换恢复到上一次的状态,*/
	FISHEYE_OUTPUTFORMAT *outputFormat;         /*输出图像信息*/
	MHFPTZ_CONFIGPARAM   *configParam;          /*鱼球联动配置参数*/
	int              enableAutoContrast;       /*开启自动对比度, 0关闭, 1开启, 该功能会增加算法耗时, 需要性能好的机器才建议开启*/
	int              alphaHistogram;           /*直方图IIR强度0-255, 默认128, 越大越参考当前帧*/
	int              alphaGray;                /*灰度拉伸强度0-255, 默认245, 越大越对比度弱*/
	FISHEYE_SIZE     captureSize;		       /*对应当前模式下的抓图分辨率*/

	int              reserved[1];				/*保留字节*/
}FISHEYE_OPTPARAM;

typedef struct
{
	FISHEYE_EPTZCMD   ePtzCmd;			/*云台操作，说明见FISHEYE_EPtzCmd定义*/
	int          winId;				    /*要进行eptz的窗口编号，左上角winId为0，从左到右递增*/							
	int          arg1;
	int          arg2;
	int          arg3;
	int          arg4;
	int          arg5;
	int          arg6;
	int          reserved0[6];			   /*保留字节*/
	void*        pParam;                   /*鱼球联动*/
	void*        pResult;
	void*        pArg;   

	int          reserved1[7];			   /*保留字节*/

}FISHEYE_EPTZPARAM;

typedef enum
{
	FISHEYE_SETPARAM,
	FISHEYE_GETPARAM

}FISHEYE_OPERATETYPE;
/***end鱼眼定义***/


// Extension API
    
    
#define PIC_BMP_32                      0       //BMP32
#define PIC_BMP_24                      1       //BMP24

/*兼容旧版本鱼眼接口*/
typedef enum
{
    FISHSHOWMODE_WALL_PANORAMA = 0,       //壁装全景模式
    FISHSHOWMODE_CEIL_PANORAMA,           //顶装360度全景
    FISHSHOWMODE_CEIL_PANORAMA_TWO,       //顶装180度全景
    FISHSHOWMODE_FLOOR_PANORAMA,          //地板安装360度全景
    FISHSHOWMODE_FLOOR_PANORAMA_TWO,      //地板安装180度全景
    FISHSHOWMODE_ONE_O_THREE,             //1+3模式
    FISHSHOWMODE_CEIL_ONE_REGION = 10,    //顶装单窗口eptz
    FISHSHOWMODE_CEIL_FOUR_REGION,        //顶装4窗口eptz
    FISHSHOWMODE_ORIGINAL,                //原始模式，不做处理直接输出原始数据
    FISHSHOWMODE_WALL_ONE_REGION,         //壁装单窗口eptz
    FISHSHOWMODE_WALL_FOUR_REGION,        //壁装4窗口eptz
    FISHSHOWMODE_FLOOR_ONE_REGION,        //地板安装单窗口eptz
    FISHSHOWMODE_FLOOR_FOUR_REGION,       //地板安装4窗口eptz数据原始数据
    FISHSHOWMODE_WALL_ONE_O_THREE,	      //地板1+3模式
    FISHSHOWMODE_CEIL_ONE_O_THREE,	      //顶装1+3模式
    FISHSHOWMODE_FLOOR_ONE_O_THREE,	      //壁装1+3模式
    
}FISHSHOWMODES;

typedef enum
{
    FISHEPTZOPT_UPDATE_FOCUS,                   //更新焦点
    FISHEPTZOPT_ZOOM_IN,                        //放大
    FISHEPTZOPT_ZOOM_OUT,                       //缩小
    FISHEPTZOPT_MOVE_UP,                        //向上移动
    FISHEPTZOPT_MOVE_DOWN,                      //向下移动
    FISHEPTZOPT_MOVE_LEFT,                      //向左移动
    FISHEPTZOPT_MOVE_RIGHT,                     //向右移动
    FISHEPTZOPT_AUTO_ROTATE_CLOCKWISE,          //自动顺时针旋转
    FISHEPTZOPT_AUTO_ROTATE_COUNTERCLOCKWISE,   //自动逆时针旋转
    FISHEPTZOPT_STOP_AUTO_ROTATE,				//停止自动旋转
    FISHEPTZOPT_GET_POSITION,					//获取当前云台窗口所在位置
    FISHEPTZOPT_SELECT_REGION_ZOOMIN_ON,        //框选放大
    FISHEPTZOPT_SELECT_REGION_ZOOMIN_OFF,		//退出框选放大
    FISHEPTZOPT_RESTORE_DEFAULT_LOCATION,		//云台恢复默认位置
    
}FISHEPTZOPTS;
/***************/

//@begin鱼球联动
typedef struct
{
    int   himg_width;                       //从相机图像宽
    int   himg_height;                      //从相机图像高
    int   *zoom_list;						/*球机倍数表*/
    int    zoom_list_size;					/*球机倍数表档位个数*/
}MHFPTZ_INITPARAM;
//@end鱼球联动

// 日期信息
typedef struct __DATETIME_INFO
{
    unsigned int			nYear;			// 年
    unsigned int			nMonth;			// 月
    unsigned int			nDay;			// 日
    unsigned int			nHour;			// 时
    unsigned int			nMinute;		// 分
    unsigned int			nSecond;		// 秒
    unsigned int			nMilliSecond;	// 毫秒
}DATETIME_INFO;

typedef struct
{
    char*	pHead;
    int		nLen;
    char*	pBody;
    int		nBodyLen;
    
    int		nRet;				//0: decode 1://don't decode
    char	reserved[128];
}DemuInfoEx;

typedef struct
{
    int type;			// 1:VIDEO, 2:AUDIO, 3:DATA
    int subtype;		// I Frame, BP Frame, PCM8, MS-ADPCM etc.
    int encode;			// MPEG4, H264, STDH264
    int sequence;		// I帧间隔里面的序号
    
    // 图像大小信息
    int width;
    int height;
    
    // 帧率信息
    int rate;
    
    // 时间信息
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int secode;
    LONG timestamp;
    
    int channels;
    int bitspersample;
    int samplespersecond;
}DEMUX_INFO;

// 文件信息帧
typedef struct __FILE_INFO_FRAME
{
    unsigned int		nFrameSubType;	  // 帧子类型，动检数据帧、事件帧等
    DATETIME_INFO*		pstDateTimeStart; // 开始时间
    DATETIME_INFO*		pstDateTimeEnd;   // 结束时间
    unsigned char*		pFrameData;		  // 帧数据
    unsigned int		nFrameDataLen;	  // 帧数据长度
} FILE_INFO_FRAME;

typedef struct __FILE_INFO_FRAME_SEARCH
{
    unsigned int		nFileFrameType;		//搜索类型，可以组合，如 PLAYER_INFO_TYPE_MOTIONDECT | PLAYER_INFO_TYPE_EVENT
    DATETIME_INFO		stStartDataTime;    //开始时间
    DATETIME_INFO		stEndDataTime;      //结束时间
    DISPLAYRECT			rtDetectedRegion;   //总区域中的动检检测范围，动检帧时有效，区域矩形为0时，表示全区域搜索
    DISPLAYRECT			rtTotal;			//总区域, 动检帧时有效
} FILE_INFO_FRAME_SEARCH;

typedef struct __FILE_INFO_IMAGE
{
    tPicFormats	   imageType;				// 图片的类型
    unsigned char* pPicBuf;					// 图片的缓冲指针
    unsigned int   nPicBufLen;				// 图片的长度
    
} FILE_INFO_IMAGE;

typedef struct NativeHandle
{
    void* display;
    void* context;
    void* surface;
    
}Android_NativeHandle;

// 文件信息帧的搜索类型，对应FILE_INFO_FRAME_SEARCH结构体中的nFileFrameType
#define PLAY_INFO_TYPE_MOTIONDECT     1         // 动检
#define PLAY_INFO_TYPE_EVENT		  2         // 事件

/************************************************************************/
/* 增强支持的功能                                                         */
/************************************************************************/
typedef enum
{
    IVSEFUNCTYPE_DEHAZE,	    // 去雾
    IVSEFUNCTYPE_DENOISE,		// 去噪
    IVSEFUNCTYPE_WB,			// 偏色校正
    IVSEFUNCTYPE_LOWLIGHT,		// 低照度增强
    IVSEFUNCTYPE_HDR,			// 宽动态
    IVSEFUNCTYPE_NUM			// 支持增强的功能个数
}IVSEFUNCTYPE;

/************************************************************************/
/* ROI数据类型定义                                                        */
/************************************************************************/
typedef struct
{
    int x;          // 左上角x坐标
    int y;          // 左上角y坐标
    int width;      // 区域宽度
    int height;     // 区域高度
}IVSEROI;

/************************************************************************/
/* 视频增强算法输入参数                                                           */
/************************************************************************/
typedef struct
{
    IVSEFUNCTYPE eFuncType;   // 功能选项
    IVSEROI		 cRoi;        // ROI 配置
    int			 nMode;       // 0表示图片模式， 1表示视频模式
    int			 nProcess_param[2];     // 处理参数，范围[1,5]
    /*
     功能函数	                process_param[0]	    process_param[1]
     IVSEFUNCTYPE_DEHAZE	        灵敏度	                饱和度
     IVSEFUNCTYPE_DENOISE	    灵敏度	                - （视频模式有效）
     IVSEFUNCTYPE_WB	        -	                    -
     IVSEFUNCTYPE_LOWLIGHT	-   灵敏度	                饱和度
     IVSEFUNCTYPE_HDR	        0:白天 1:黑夜 2:自动  	灵敏度
     */
    
}IVSEPARAMS;
    
    
#ifdef __cplusplus
}
#endif

#endif  //  _DHPLAY_DEFS_H
