#pragma once
#include"math.h"

// ���ߣ�  www.gudianxiaoshuo.com    needdown.com
// ΢�ţ�  gudianxiaoshuo
// Q��     869321632
// �����  ���ֿ��á�����ʼǡ����Զ�ͼ���ŵ�С˵�ʶ���

#define PAI 3.1415926

class CPaopao{

public:
   CPaopao();
   ~CPaopao(void);
   CPaopao(int xPos,int yPos, int r,int nx,int ny,COLORREF color);

   CRect rc;//���ݵ�λ��
   bool bAdd;//�Ƕ�����
   int nx;  //���ݵ��˶� X����
   int ny;  //���ݵ��˶� Y����
   float fAngle;
   float rRadius;// �뾶
   COLORREF color;


   short nIdOfBitmap;

   void SetBitmapID(short nBitmapID);

   void Draw(CDC &dc,int nDrawStyle=0,BOOL bPransparent=TRUE);

   void Run(CRect clientRc);

   void RunCircle(CRect clientRc);//Բ���˶�

   void RunSin(CRect clientRc,float fStartAngle,float fEndAngle);//�����˶�

   float Distance(CPoint pt1, CPoint pt2);

   float GetAngle(CPoint centerPoint, CPoint pt);

};

