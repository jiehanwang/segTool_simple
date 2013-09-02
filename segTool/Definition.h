#pragma once
#include <opencv2\opencv.hpp>

#define LRB 3    //Left, right, both
#define FusedLRB 1
//#define CombineGallery    //If defined. Combined gallery is used. 
#ifdef CombineGallery
	#define Gallery_num 1
#endif
#ifndef CombineGallery
	#define Gallery_num 5
#endif

#define Posture_num 370
#define feature_dimension 1764
#define MaxKeyFrameNumber 6
#define delay2
#define iSIZE 64
#define ThreForOnline 0.5
#define MarryThre 0.0
#define topXValue   5   //The allowed top class index to be considered in doMatche.
#define trajectoryFactor 0
//#define DrawInOpenGL
//#define DrawSpeed
#define keyFrameGap 10
#define top2Tore   0.08   //used in function "doMatch" in Matching class. 
#define pairSumPenalty 0.02
#define finalResultThre 0//0.58 is for posture only.
#define allowedTraFrameSize 30

#define WordsNum 370       //����ʻ����
//#define heightThres	370
#define consistThres	5

#define MaxKeyPostureNum 10
#define Theda  0.0000001


//////////////////////////////////////////////////////////////////////////
const int F=512;
const int num=5;
const int dim=3;//3D
const int probenum=0;
const double PI= 3.1415;
const float eps=0.0001;
const int rsnum=200;


//////////////////////////////////////////////////////////////////////////
/// @author xu zhihao
/// @struct _Vector2i
/// @brief skeleton data transformed data
//////////////////////////////////////////////////////////////////////////
struct _Vector2i
{
	int x;
	int y;
};

//////////////////////////////////////////////////////////////////////////
/// @author xu zhihao
/// @struct SLR_ST_Skeleton
/// @brief skeleton data  real data
//////////////////////////////////////////////////////////////////////////
struct _Vector4f
{
	float x;
	float y;
	float z;
	float w;
};
//////////////////////////////////////////////////////////////////////////
/// @author xu zhihao
/// @struct SLR_ST_Skeleton
/// @brief skeleton data  real data and transformed data
//////////////////////////////////////////////////////////////////////////
struct SLR_ST_Skeleton
{
	_Vector4f _3dPoint[20];    ///< real point
	_Vector2i _2dPoint[20];    ///< pix in color image
}; 
struct KeyFrameUnit
{
	int StartFrame;
	int EndFrame;
};
struct HandSegment
{
	int keyframe_num;
	int* keyframe_no;
	IplImage*** keyframe_pic;
	int** keyframe_ID;
	int** keyframe_coor;
};
enum HANDTYPE
{
	LEFT,
	RIGHT,
	BOTH,
};

//////////////////////////////////////////////////////////////////////////
/// @author xu zhihao
/// @struct ColorModel
/// @brief skin color model, mean and variance of cr cb
//////////////////////////////////////////////////////////////////////////
struct ColorModel
{
	double mean_cr;     ///< mean of cr
	double mean_cb;     ///< mean of cb
	double d_cr;        ///< variance of cr
	double d_cb;        ///< variance of cb
	ColorModel():mean_cr(0),mean_cb(0),d_cr(0),d_cb(0){};
};

struct KeyFrameSegment
{
	int BeginFrameID;		//�ؼ�Ƭ�ο�ʼ֡��
	int EndFrameID;			//�ؼ�Ƭ��jie'shu֡��

	int BothLabel;			//0-��	1-��
	int LeftLabel;			//0-��	1-��
	int RightLabel;			//0-��	1-��

	int BothNum;			//˫��ͼƬ��Ŀ
	int LeftNum;			//����ͼƬ��Ŀ
	int RightNum;			//����ͼƬ��Ŀ

	int* BothID;			//ÿ��˫�ַָ�ͼƬ��֡��
	int* LeftID;			//ÿ�����ַָ�ͼƬ��֡��
	int* RightID;			//ÿ�����ַָ�ͼƬ��֡��

	int* BothCoor;			//ÿ��˫�ַָ�ͼƬ���Ͻǵ�����
	int* LeftCoor;			//ÿ�����ַָ�ͼƬ���Ͻǵ�����
	int* RightCoor;			//ÿ�����ַָ�ͼƬ���Ͻǵ�����

	IplImage** BothImages;	//˫��ͼƬ
	IplImage** LeftImages;	//˫��ͼƬ
	IplImage** RightImages;	//˫��ͼƬ
};