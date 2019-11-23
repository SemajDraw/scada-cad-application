// PneumaticPump.cpp
// definition file for PneumaticPump class
#include "stdafx.h"
#include "PneumaticPump.h"

void PneumaticPump::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around PneumaticPump for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top=scrY-(5*GRID_SIZE);		// setting top field of compTempRECT struct
	compTempRECT.left=scrX-(2*GRID_SIZE);		// setting left field of compTempRECT struct
	compTempRECT.right=scrX+(5*GRID_SIZE);		// setting right field of compTempRECT 
	compTempRECT.bottom=scrY+GRID_SIZE;			// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function
	
	// alogorithm for drawing PneumaticPump 
	// 1 - drawing first line
	MoveToEx(hdc, scrX-(getFuture0()*GRID_SIZE*2), scrY, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE*0.5), scrY);

	// 2 - drawing second line opposite first
	MoveToEx(hdc, scrX+(2.5*(getFuture0()*GRID_SIZE)), scrY, NULL);
	LineTo(hdc, scrX+(5*(getFuture0()*GRID_SIZE)), scrY);

	// 3 - drawing base line of pump
	MoveToEx(hdc, scrX-GRID_SIZE*2, scrY+GRID_SIZE, NULL);
	LineTo(hdc, scrX+(5*GRID_SIZE), scrY+GRID_SIZE);

	// 4 - drawing line perpendicular to first line
	MoveToEx(hdc, scrX+GRID_SIZE*0.5, scrY, NULL);
	LineTo(hdc, scrX+GRID_SIZE*0.5, scrY-(4*GRID_SIZE));

	// 5 - drawing line perpendicular to second line
	MoveToEx(hdc, scrX+(2.5*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(2.5*GRID_SIZE), scrY-(4*GRID_SIZE));

	// 6 - drawing top grey lid
	HBRUSH hbr=CreateSolidBrush(RGB(192,192,192)); //grey brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	Rectangle(hdc, scrX, scrY-(3.8*GRID_SIZE), scrX+(3*GRID_SIZE), scrY-(5*GRID_SIZE));
	SelectObject(hdc,hOld);
	DeleteObject(hbr);

	// 7 - drawing pump block
	HBRUSH hbr2=CreateSolidBrush(RGB(150,150,150)); //grey brush
	HBRUSH hOld2=(HBRUSH)SelectObject(hdc,hbr2);
	Rectangle(hdc, scrX+GRID_SIZE*0.5, scrY-(3.8*GRID_SIZE), scrX+(2.5*GRID_SIZE), scrY-3*GRID_SIZE);
	SelectObject(hdc,hOld2);
	DeleteObject(hbr2);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}
	
void PneumaticPump::animate(HDC hdc, UINT GRID_SIZE)
{
	// 7 - drawing pump block
	HBRUSH hbr=CreateSolidBrush(RGB(255,255,255)); //white brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	Rectangle(hdc, scrX+GRID_SIZE*0.5, scrY-(3.8*GRID_SIZE), scrX+(2.5*GRID_SIZE), scrY-3*GRID_SIZE);
	SelectObject(hdc,hOld);
	DeleteObject(hbr);

	// 7 - drawing pole
	HBRUSH hbr1=CreateSolidBrush(RGB(192,192,192)); //grey brush
	HBRUSH hOld1=(HBRUSH)SelectObject(hdc,hbr1);
	Rectangle(hdc, scrX+GRID_SIZE, scrY-(3.8*GRID_SIZE), scrX+(2*GRID_SIZE), scrY-(3.8*GRID_SIZE)+(3.8*GRID_SIZE)*(*analogPtr/255));
	SelectObject(hdc,hOld1);
	DeleteObject(hbr1);

	// 7 - drawing pump block
	HBRUSH hbr2=CreateSolidBrush(RGB(150,150,150)); //grey brush
	HBRUSH hOld2=(HBRUSH)SelectObject(hdc,hbr2);
	Rectangle(hdc, scrX+GRID_SIZE*0.5, scrY-(3.8*GRID_SIZE)+(2.8*GRID_SIZE)*(*analogPtr/255), scrX+(2.5*GRID_SIZE), scrY-(3*GRID_SIZE)+(3*GRID_SIZE)*(*analogPtr/255));
	SelectObject(hdc,hOld2);
	DeleteObject(hbr2);

	// Creating brush of light blue color
	HBRUSH hBr3 = CreateSolidBrush(RGB(19, 183, 237));

	// Setting animation length
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
	RECT a3;
	// Initializing count and setting to zero
	int count=0;

			//Left water rectangle
			getComponentRECT(a1);
			a1.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			a1.top = a1.top+(5*GRID_SIZE);
			a1.right=a1.left+GRID_SIZE-1;
			a1.bottom=a1.top+GRID_SIZE-1;
			a1.left+=2;
			a1.top+=2;
			FillRect(hdc, &a1, hBr3);
			//Middle water rectangle
			getComponentRECT(a2);
			a2.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE)+(GRID_SIZE*2);
			a2.top = a2.top+(5*GRID_SIZE);
			a2.right=a2.left+GRID_SIZE-1;
			a2.bottom=a2.top+GRID_SIZE-1;
			a2.left+=2;
			a2.top+=2;
			FillRect(hdc, &a2, hBr3);
			//Right water rectangle
			getComponentRECT(a3);
			a3.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE)+(GRID_SIZE*4);
			a3.top = a3.top+(5*GRID_SIZE);
			a3.right=a3.left+GRID_SIZE-1;
			a3.bottom=a3.top+GRID_SIZE-1;
			a3.left+=2;
			a3.top+=2;
			FillRect(hdc, &a3, hBr3);

			//HBRUSH hbr=CreateSolidBrush(RGB(255,255,255)); //white brush
			HBRUSH hOld4=(HBRUSH)SelectObject(hdc,hBr3);
			Rectangle(hdc, scrX+GRID_SIZE*0.5, scrY-(3*GRID_SIZE)+((3*GRID_SIZE))*(*analogPtr/255), scrX+(2.5*GRID_SIZE), scrY);//+3*GRID_SIZE);
			SelectObject(hdc,hOld);
			DeleteObject(hBr3);

			count++;
			setAnimationPosition(getAnimationPosition()+1);
			DeleteObject(hBr3);
}

	