// HydraulicValve.cpp
// definition file for HydraulicValve class
#include "stdafx.h"
#include "HydraulicValve.h"

void HydraulicValve::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around HydraulicValve for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top=scrY-(4*GRID_SIZE);		// setting top field of compTempRECT struct
	compTempRECT.left=scrX;						// setting left field of compTempRECT struct
	compTempRECT.right=scrX+(5*GRID_SIZE); 		// setting right field of compTempRECT 
	compTempRECT.bottom=scrY;					// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

	// alogorithm for drawing HydraulicValve
	//Top line w/ gap for valve
	MoveToEx(hdc, scrX, scrY-1*(getFuture0()*GRID_SIZE), NULL);								// move to (0,0)
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE)*3.5, scrY-1*(getFuture0()*GRID_SIZE));							// line to (5.5,0)
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE*4), scrY-1*(getFuture0()*GRID_SIZE), NULL);					// move to (6,0)
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE*5), scrY-1*(getFuture0()*GRID_SIZE));							// line to (7,0)

	//Solid bottom line
	MoveToEx(hdc, scrX, scrY, NULL);					// move to (1,-1)
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE*5), scrY);				// line to (7,-1)

	//Valve wall
	HBRUSH hbr1=CreateSolidBrush(RGB(160, 160, 160)); //Grey brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr1);
	Rectangle(hdc, scrX+GRID_SIZE*3.5, scrY-3*GRID_SIZE, scrX+GRID_SIZE*4, scrY);
	SelectObject(hdc,hOld);
	DeleteObject(hbr1);
	
	//Handle
	Rectangle(hdc, scrX+GRID_SIZE*1.5, scrY-3.5*GRID_SIZE, scrX+GRID_SIZE*2.5, scrY-1*GRID_SIZE);
	HBRUSH hbr2=CreateSolidBrush(RGB(255, 51, 51)); //Red brush
	HBRUSH hOther=(HBRUSH)SelectObject(hdc,hbr2);
	RoundRect(hdc, scrX, scrY-4*GRID_SIZE, scrX+GRID_SIZE*2.5, scrY-3.5*GRID_SIZE, GRID_SIZE, GRID_SIZE);
	SelectObject(hdc,hOther);
	DeleteObject(hbr2);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void HydraulicValve::animate(HDC hdc, UINT GRID_SIZE)
{

	// Creating brush of light blue color
	HBRUSH hBr3 = CreateSolidBrush(RGB(19, 183, 237));

	// Setting aniamtion length
	int animateLength = 2;

	// Checking if animation is out of bounds
	// and if so setting to zero
	if(getAnimationPosition()>=animateLength 
		|| getAnimationPosition()>getFuture0()
		|| getAnimationPosition()<0)
		setAnimationPosition(0);

	// drawing the animation
	// Creating RECT
	RECT a1;
	RECT a2;
	// Initializing count and setting to zero
	int count=0;

			//Left water rectangle
			getComponentRECT(a1);
			a1.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			a1.top = a1.top+(3*GRID_SIZE);
			a1.right=a1.left+GRID_SIZE-1;
			a1.bottom=a1.top+GRID_SIZE-1;
			a1.left+=2;
			a1.top+=2;
			FillRect(hdc, &a1, hBr3);
		
			//Right water rectangle
			getComponentRECT(a2);
			a2.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE)+(GRID_SIZE*3);
			a2.top = a2.top+(3*GRID_SIZE);
			a2.right=a2.left+GRID_SIZE-1;
			a2.bottom=a2.top+GRID_SIZE-1;
			a2.left+=2;
			a2.top+=2;
			FillRect(hdc, &a2, hBr3);

			count++;

	//Valve wall
	HBRUSH hbr1=CreateSolidBrush(RGB(255, 255, 255)); //white brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr1);
	Rectangle(hdc, scrX+GRID_SIZE*3.5, scrY-GRID_SIZE, scrX+GRID_SIZE*4, scrY);
	SelectObject(hdc,hOld);
	DeleteObject(hbr1);
	
	//Handle
	Rectangle(hdc, scrX+GRID_SIZE*1.5, scrY-3.5*GRID_SIZE, scrX+GRID_SIZE*2.5, scrY-1*GRID_SIZE);
	HBRUSH hbr2=CreateSolidBrush(RGB(51, 255, 51)); //Green brush
	HBRUSH hOther=(HBRUSH)SelectObject(hdc,hbr2);
	RoundRect(hdc, scrX, scrY-4*GRID_SIZE, scrX+GRID_SIZE*2.5, scrY-3.5*GRID_SIZE, GRID_SIZE, GRID_SIZE);
	SelectObject(hdc,hOther);
	DeleteObject(hbr2);

	deletePens(hdc);
	setAnimationPosition(getAnimationPosition()+1);
	DeleteObject(hBr3);
}
	


