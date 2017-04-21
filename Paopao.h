#pragma once
#include"math.h"


#define PAI 3.1415926

class CPaopao{

public:
   CPaopao();
   ~CPaopao(void);
   CPaopao(int xPos,int yPos, int r,int nx,int ny,COLORREF color);

   CRect rc;//泡泡的位置
   int nx;  //泡泡的运动 X分量
   int ny;  //泡泡的运动 Y分量
   float fAngle;
   float rRadius;// 半径
   COLORREF color;


   short nIdOfBitmap;

   void SetBitmapID(short nBitmapID);

   void Draw(CDC &dc,int nDrawStyle=0,BOOL bPransparent=TRUE);

   void Run(CRect clientRc);

   void RunCircle(CRect clientRc);

   float Distance(CPoint pt1, CPoint pt2);

};

