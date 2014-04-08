// segTool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Readvideo.h"
#include <string>
#include <atlstr.h>
//#include "CvvImage.h"
#include <opencv2\opencv.hpp>
#include "windows.h"
//#include "CvvImage.h"
//#include <fstream>
using namespace std;
using namespace cv;

int _tmain()
{
	CString videoFileName;
	Readvideo myReadVideo;
	int frameSize;
	videoFileName.Format("D:\\P01_0040_1_0_20140408.oni");
	//videoFileName.Format("D:\\iData\\isolatedWord\\P50\\P50_0000_1_0_20121002.oni");
	string  s   =   (LPCTSTR)videoFileName;
	myReadVideo.readvideo(s);
	frameSize = myReadVideo.vColorData.size();
	cvNamedWindow("color_skeleton",1);
	cvNamedWindow("depth",1);
	cout<<"The total frame is: "<<frameSize<<endl;

	for (int i=0; i<frameSize; i++)
	{
		CString fileName;
		IplImage* tempImage;
		tempImage = myReadVideo.vColorData[i];
		for (int j=2; j<=11; j++)
		{
			CvPoint p1;
			p1.x = myReadVideo.vSkeletonData[i]._2dPoint[j].x;
			p1.y = myReadVideo.vSkeletonData[i]._2dPoint[j].y;
			cvCircle(tempImage,p1,2,cvScalar(225,0,0),2,8,0);
			if (j!=7 && j!=3 && j!=11)
			{
				CvPoint p2;
				p2.x = myReadVideo.vSkeletonData[i]._2dPoint[j+1].x;
				p2.y = myReadVideo.vSkeletonData[i]._2dPoint[j+1].y;
				cvLine(tempImage,p1,p2,cvScalar(0,0,225),2,8,0);
			}
			if (j==2)
			{
				CvPoint p2;
				p2.x = myReadVideo.vSkeletonData[i]._2dPoint[j+2].x;
				p2.y = myReadVideo.vSkeletonData[i]._2dPoint[j+2].y;
				CvPoint p3;
				p3.x = myReadVideo.vSkeletonData[i]._2dPoint[j+6].x;
				p3.y = myReadVideo.vSkeletonData[i]._2dPoint[j+6].y;
				cvLine(tempImage,p1,p2,cvScalar(0,0,225),2,8,0);
				cvLine(tempImage,p1,p3,cvScalar(0,0,225),2,8,0);
			}
			
		}


		cvShowImage("color_skeleton",tempImage);

		//////////////////////////////////////////////////////////////////////////
		Mat depthMat = myReadVideo.retrieveColorDepth(myReadVideo.vDepthData[i]);
		IplImage* depthImage = &(IplImage)depthMat;
		cvShowImage("depth",depthImage);

		//
// 		if (i<10)
// 		{
// 			fileName.Format("..\\output\\000%d.jpg",i);
// 		}
// 		else if(i<100)
// 		{
// 			fileName.Format("..\\output\\00%d.jpg",i);
// 		}
// 		else if (i<1000)
// 		{
// 			fileName.Format("..\\output\\0%d.jpg",i);
// 		}
// 		
// 		cvSaveImage(fileName,tempImage);

		cvReleaseImage(&tempImage);
		cvWaitKey(30);
	}

	//
// 	CreateWnd(); 
// 	HDC hDC = GetDC(g_hWnd);
// 	int previousFrame;
// 	
// 	CString videoFileName;
// 	int frameSize;
// 	int width = 640;
// 	int height = 480;
// 	int sentenceIndex;
// 	ofstream outfile;
// 	cout<<"input index: "<<endl;
// 	cin>>sentenceIndex;
// 
// 	while (1)
// 	{
// 		outfile.open("..\\segManually.txt",ios::out | ios::app);
// 		Readvideo myReadVideo;
// 		if (sentenceIndex<10)
// 		{
// 			videoFileName.Format("D:\\iData\\p08_01\\S08_000%d_1_0_20130412.oni",sentenceIndex);
// 		}
// 		else if (sentenceIndex<100)
// 		{
// 			videoFileName.Format("D:\\iData\\p08_01\\S08_00%d_1_0_20130412.oni",sentenceIndex);
// 		}
// 		else if (sentenceIndex<1000)
// 		{
// 			videoFileName.Format("D:\\iData\\p08_01\\S08_0%d_1_0_20130412.oni",sentenceIndex);
// 		}
// 		string  s   =   (LPCTSTR)videoFileName;
// 		myReadVideo.readvideo(s);
// 		frameSize = myReadVideo.vColorData.size();
// 
// 		currentFrame = 0;
// 		previousFrame = currentFrame;
// 		int preOut = 0;
// 		outfile<<sentenceIndex<<'\t';
// 		int beginEnd = 0;
// 		int count = 0;
// 		while(1)
// 		{
// 			if (currentFrame>frameSize-1)
// 			{
// 				break;
// 			}
// 			if (currentFrame!=previousFrame)
// 			{
// 				//cout<<currentFrame<<" ";
// 				previousFrame = currentFrame;
// 			}
// 
// 			IplImage* frameCurrent = myReadVideo.vColorData[currentFrame];
// 			showImage(frameCurrent,0,0,width,height,hDC);
// 
// 			//Respond to mouse event.
// 			MSG	msg;
// 			if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))	// Is There A Message Waiting?
// 			{
// 				TranslateMessage(&msg);				// Translate The Message
// 				DispatchMessage(&msg);				// Dispatch The Message
// 			}
// 			else										// If There Are No Messages
// 			{
// 				if (keys[VK_SPACE])
// 				{
// 					if (currentFrame!=preOut)
// 					{
// 						outfile<<currentFrame<<'\t';
// 						cout<<count<<" cut: "<<currentFrame<<endl;
// 						if (count%2 == 1)
// 						{
// 							cout<<"--------------------------------"<<endl;
// 						}
// 						count++;
// 						//::TextOut(hDC,0,0,TEXT("up, down "),12);
// 						preOut = currentFrame;
// 					}
// 				}
// 				if (keys[VK_RIGHT])
// 				{
// 
// 				}
// 				if (keys[VK_LEFT])
// 				{
// 					currentFrame--;
// 					currentFrame = currentFrame>0?currentFrame:0;
// 				}
// 				if (keys[VK_RIGHT])
// 				{
// 					currentFrame++;
// 				}
// 			}
// 			Sleep(10);
// 		}
// 		outfile<<endl;
// 		outfile.close();
// 		cout<<"Done"<<endl;
// 		//cin>>sentenceIndex;
// 		sentenceIndex++;
// 	}

	cvDestroyWindow("color_skeleton");
	cvDestroyWindow("depth");
	cout<<"Done!"<<endl;
	getchar();
	return 0;
}

