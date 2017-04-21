#include "stdafx.h"
#include "Paopao.h"


CPaopao::CPaopao()
{	
      nx=0;
	  ny=0;
	  fAngle = 0;
	  rRadius=0;

	  color=RGB(0,0,0);

}
CPaopao::CPaopao(int xPos,int yPos, int r,int nx,int ny,COLORREF color){

	  rc.top=yPos-r;
	  rc.left=xPos-r;
	  rc.right=xPos+r;
	  rc.bottom=yPos+r;
	  fAngle = 0;

      this->nx=nx;
	  this->ny=ny;
	  this->color=color;
   }

void CPaopao::SetBitmapID(short nBitmapID){

	nIdOfBitmap = nBitmapID;
}
 void CPaopao::Draw(CDC &dc,int nDrawStyle,BOOL bPransparent){


	   CPen pen;
	   pen.CreatePen(0,1,color);

       CPen *pOldPen=dc.SelectObject(&pen);

       CBrush* pOldBrush=NULL;
	   CBrush brush;
	   CBitmap bmp;
	   CDC memDC;
	   if(bPransparent)
			pOldBrush=(CBrush*)dc.SelectStockObject(NULL_BRUSH);
	   else{
		   brush.CreateSolidBrush(color);
		   pOldBrush=dc.SelectObject(&brush);
	   }

	   switch(nDrawStyle){

	   case 0:
		   {
              dc.Ellipse(rc);
		   }
		   break;

	   case 1:
		   {
              dc.Rectangle(rc);
		   }
		   break;

	   case 2:
		   {
			 bmp.LoadBitmap(nIdOfBitmap);
			 memDC.CreateCompatibleDC(&dc);
		     memDC.SelectObject(&bmp);

			 BITMAP bmpInfo;
			 bmp.GetBitmap(&bmpInfo);
             
		//	 dc.BitBlt(rc.left,rc.top,rc.Width(),rc.Height(),&memDC,0,0,SRCCOPY);
			 dc.StretchBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, NOTSRCCOPY);
		//	TransparentBlt(dc.GetSafeHdc(),rc.left,rc.top,rc.Width(),rc.Height(),memDC.GetSafeHdc(),0,0,bmpInfo.bmWidth,bmpInfo.bmHeight,RGB(255, 255, 255));

		   }
		   break;
	   }


	   dc.SelectObject(pOldBrush);
	   dc.SelectObject(pOldPen);

   }

   void CPaopao::Run(CRect clientRc)
   {
			//Œª÷√–≈œ¢
            rc.top+=ny;
			rc.bottom+=ny;

            rc.left+=nx;
			rc.right+=nx;

			if(rc.top<0)
				ny=abs(ny);

			if(rc.bottom>clientRc.bottom)
				ny=-abs(ny);


			if(rc.left<0)
				nx=abs(nx);

			if(rc.right>clientRc.right)
				nx=-abs(nx);

   }

   void CPaopao::RunCircle(CRect clientRc){

	   CPoint ptCenter = clientRc.CenterPoint();
	   CPoint ptPaoPaoCenter = rc.CenterPoint();

	//   int nRadius =Distance(ptCenter, ptPaoPaoCenter);
	   long x = ptCenter.x + rRadius*cos(fAngle);
	   long y = ptCenter.y + rRadius*sin(fAngle);

	   rc.OffsetRect(x-ptPaoPaoCenter.x, y-ptPaoPaoCenter.y );
	   fAngle += 0.03;
   }

   float CPaopao::Distance(CPoint pt1, CPoint pt2){

	   return sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x)*1.0 + (pt1.y - pt2.y)*(pt1.y - pt2.y));
   }

CPaopao::~CPaopao(void)
{
}
