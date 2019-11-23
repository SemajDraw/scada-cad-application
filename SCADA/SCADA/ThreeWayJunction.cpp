// ThreeWayJunction.cpp
// definition file for ThreeWayJunction class
#include "stdafx.h"
#include "ThreeWayJunction.h"

void ThreeWayJunction::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around ThreeWayJunction for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.left=scrX;						// setting left field of compTempRECT struct
	compTempRECT.top=scrY-(2*GRID_SIZE);		// setting top field of compTempRECT struct	
	compTempRECT.right=scrX+(3*GRID_SIZE);		// setting right field of compTempRECT struct
	compTempRECT.bottom=scrY+(3*GRID_SIZE);		// setting bottom field of compTempRECT 
	setComponentRECT(compTempRECT);				// passing compTempRECT to setComponentRECT member function
	
	// alogorithm for drawing ThreeWayJunction 
	// 1 - drawing first line
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE), scrY);

	// 2 - drawing second line parrallel to first line
	MoveToEx(hdc, scrX, scrY+(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(getFuture0()*GRID_SIZE));

	// 3 - drawing third line perpendicular to first
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE), scrY-(getFuture0()*GRID_SIZE));

	// 4 - drawing forth line inverse perpendicular to second
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(2*(getFuture0()*GRID_SIZE)));

	// 5 - drawing fifth line in parallel with first line on other side
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY, NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY);

	// 6 - drawing sixth line in parallel second line on other side
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE));

	// 7 - drawing seventh line perpendicular to fifth line on other side
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY, NULL);
	LineTo(hdc, scrX+((getFuture0()*2*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE));

	// 8 - drawing eight line inverse perpendicular to sixth line on other side 
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(2*(getFuture0()*GRID_SIZE)));

	// 9 - drawing ninth line parallel to fifth line 
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE));

	// 10 - drawing tenth line parallel to sixth line
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(2*(getFuture0()*GRID_SIZE)), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY+(2*(getFuture0()*GRID_SIZE)));

	// 11 - drawing eleventh line parallel to ninth line
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY-(2*(getFuture0()*GRID_SIZE)), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY-(2*(getFuture0()*GRID_SIZE)));

	// 12 - drawing twelveth line parallel to tenth line
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(3*(getFuture0()*GRID_SIZE)), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY+(3*(getFuture0()*GRID_SIZE)));

	// 13 - drawing arc on upper portion of 3-Way Split
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY-(2*(getFuture0()*GRID_SIZE)), NULL);
	AngleArc(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE), (getFuture0()*GRID_SIZE), 90, 90);

	// 14 -drawing arc on lower portion of 3-Way split
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(2*(getFuture0()*GRID_SIZE)), NULL);
	AngleArc(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(2*(getFuture0()*GRID_SIZE)), (getFuture0()*GRID_SIZE), 180, 90);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void ThreeWayJunction::animate(HDC hdc, UINT GRID_SIZE)
{
	// Creating brush of light blue color
	HBRUSH hBrush = CreateSolidBrush(RGB(19, 183, 237));
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
	RECT a3;
	RECT a4;
	RECT a5;
	// Initializing count and setting to zero
	int count=0;

	// Checking if orientation is left or right
			//Top
			getComponentRECT(a1);
			a1.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE)+(1*GRID_SIZE);
			a1.right=a1.left+GRID_SIZE-1;
			a1.bottom=a1.top+GRID_SIZE-1;
			a1.left+=2;
			a1.top+=2;
			FillRect(hdc, &a1, hBrush);

			//Bottom
			getComponentRECT(a2);
			a2.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE)+(1*GRID_SIZE);
			a2.top = a2.top+(4*GRID_SIZE);
			a2.right=a2.left+GRID_SIZE-1;
			a2.bottom=a2.top+GRID_SIZE-1;
			a2.left+=2;
			a2.top+=2;
			FillRect(hdc, &a2, hBrush);

			//Middle left
			getComponentRECT(a3);
			a3.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE);
			a3.top = a3.top+(2*GRID_SIZE);
			a3.right=a3.left+GRID_SIZE-1;
			a3.bottom=a3.top+GRID_SIZE-1;
			a3.left+=2;
			a3.top+=2;
			FillRect(hdc, &a3, hBrush);

			//Middle centre
			getComponentRECT(a4);
			a4.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE)+(1*GRID_SIZE);
			a4.top = a4.top+(2*GRID_SIZE);
			a4.right=a4.left+GRID_SIZE-1;
			a4.bottom=a4.top+GRID_SIZE-1;
			a4.left+=2;
			a4.top+=2;
			FillRect(hdc, &a4, hBrush);

			count++;
	
	setAnimationPosition(getAnimationPosition()+1);
	DeleteObject(hBrush);
}