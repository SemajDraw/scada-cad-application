// 2WayJunction.cpp
// definition file for 2WayJunction class
#include "stdafx.h"
#include "TwoWayJunction.h"

void TwoWayJunction::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around TwoWayJunction for mouse arrow selection purposes
	RECT compTempRECT;								// creating RECT object compTempRECT
	compTempRECT.top = scrY-GRID_SIZE;				// setting top field of compTempRECT struct
	compTempRECT.left = scrX;						// setting left field of compTempRECT struct
	compTempRECT.right = scrX+(3*GRID_SIZE);		// setting right field of compTempRECT 
	compTempRECT.bottom = scrY+(2*GRID_SIZE);		// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);					// passing compTempRECT to setCompRECT member function
	
	// alogorithm for drawing TwoWayJunction 
	// 1 - drawing first line 
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE), scrY);

	// 2 - drawing second line parallel
	MoveToEx(hdc, scrX, scrY+(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(getFuture0()*GRID_SIZE));

	// 3 - drawing third line opposite
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY, NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY);

	// 4 - drawing forth line perpendicular to third
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY, NULL);
	LineTo(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE));

	// 5 - drawing fifth line parallel to third
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE));

	// 6 - drawing sixth line above third line parallel to it
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE));

	// 7 - drawing seventh line below forth line parallel to it
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(2*(getFuture0()*GRID_SIZE)), NULL);
	LineTo(hdc, scrX+(3*(getFuture0()*GRID_SIZE)), scrY+(2*(getFuture0()*GRID_SIZE)));

	// 8 - drawing arc on top portion of 2-way split
	MoveToEx(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY-(getFuture0()*GRID_SIZE), NULL);
	AngleArc(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY, (getFuture0()*GRID_SIZE), 90, 90);

	// 9 - drawing arc on bottom portion of 2-way split
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(getFuture0()*GRID_SIZE), NULL);
	AngleArc(hdc, scrX+(2*(getFuture0()*GRID_SIZE)), scrY+(getFuture0()*GRID_SIZE), (getFuture0()*GRID_SIZE), 180, 90);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void TwoWayJunction::animate(HDC hdc, UINT GRID_SIZE)
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
	// Initializing count and setting to zero
	int count=0;

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
			a2.top = a2.top+(2*GRID_SIZE);
			a2.right=a2.left+GRID_SIZE-1;
			a2.bottom=a2.top+GRID_SIZE-1;
			a2.left+=2;
			a2.top+=2;
			FillRect(hdc, &a2, hBrush);

			//Middle
			getComponentRECT(a3);
			a3.left+=(getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE);
			a3.top = a3.top+(GRID_SIZE);
			a3.right=a3.left+GRID_SIZE-1;
			a3.bottom=a3.top+GRID_SIZE-1;
			a3.left+=2;
			a3.top+=2;
			FillRect(hdc, &a3, hBrush);

			count++;

	setAnimationPosition(getAnimationPosition()+1);
	DeleteObject(hBrush);
}