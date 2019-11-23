// T_Junction.cpp
// definition file for T-Junction class
#include "stdafx.h"
#include "T_Junction.h"

void T_Junction::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around T_Junction for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top=scrY;						// setting top field of compTempRECT struct
	compTempRECT.left=scrX;						// setting left field of compTempRECT struct
	compTempRECT.right=scrX+(getFuture0()*GRID_SIZE);		// setting right field of compTempRECT struct
	compTempRECT.bottom=scrY+GRID_SIZE;			// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

												// creating invisible rectangle around T_Junction for mouse arrow selection purposes
	RECT compTempRECT1;							// creating RECT object compTempRECT
	compTempRECT1.top = scrY-(3*GRID_SIZE);						// setting top field of compTempRECT struct
	compTempRECT1.left = scrX+(GRID_SIZE);						// setting left field of compTempRECT struct
	compTempRECT1.right = scrX + (getFuture0()*GRID_SIZE);		// setting right field of compTempRECT struct
	compTempRECT1.bottom = scrY + (GRID_SIZE);			// setting bottom field of compTempRECT struct
	setComponentRECT1(compTempRECT1);				// passing compTempRECT to setCompRECT member function
	

	// 1 - drawing first line
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(3*GRID_SIZE*getFuture0())/3, scrY);

	// 2 - drawing second line on left hand side below first line
	MoveToEx(hdc, scrX, scrY+(getFuture0()*GRID_SIZE)/3, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE)/3, scrY+(getFuture0()*GRID_SIZE)/3);
	
	// 3 - drawing third line on right hand side below second line
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE*2)/3, scrY+(getFuture0()*GRID_SIZE)/3, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE*3)/3, scrY+(getFuture0()*GRID_SIZE)/3);
	
	// 4 - drawing forth line perpenduclar to second line
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE)/3, scrY+(getFuture0()*GRID_SIZE)/3, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE)/3, scrY+(getFuture0()*GRID_SIZE*3)/3);

	// 5 - drawing fifth line perpenduclar to third line
	MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE*2)/3, scrY+(getFuture0()*GRID_SIZE)/3, NULL);
	LineTo(hdc, scrX+(getFuture0()*GRID_SIZE*2)/3, scrY+(getFuture0()*GRID_SIZE*3)/3);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void T_Junction::animate(HDC hdc, UINT GRID_SIZE)
{
	// Creating brush of light blue color
	HBRUSH hBrush = CreateSolidBrush(RGB(19,183,237));

	// Setting aniamtion length
	int animateLength = 3;

	// Checking if animation is out of bounds
	// and if so setting to zero
	if (getAnimationPosition() >= animateLength
		|| getAnimationPosition()>getFuture0()
		|| getAnimationPosition()<0)
		setAnimationPosition(0);

	// drawing the animation
	// Creating RECT
	RECT animationRect;
	// Initializing count and setting to zero
	int count = 0;

	while (getAnimationPosition() + count*animateLength < getFuture0())
	{
		

		{
			// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.left += getAnimationPosition()*GRID_SIZE + count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.right = animationRect.left + GRID_SIZE - 1;
			animationRect.bottom = animationRect.top + GRID_SIZE - 1;
			animationRect.left += 2;
			animationRect.top += 2;
			// Filling rectangle with a light blue brush
			FillRect(hdc, &animationRect, hBrush);
			// Incrementing count
			count++;

		}	
		
		{		
			// Gettign the componenents bounding rectangle
			getComponentRECT1(animationRect);
			// Setting initial animation position
			animationRect.top += getAnimationPosition()*GRID_SIZE + count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.right = animationRect.left + GRID_SIZE - 1;
			animationRect.bottom = animationRect.top + GRID_SIZE - 1;
			animationRect.left += 2;
			animationRect.top += 2;
			// Filling rectangle with a light blue brush
			FillRect(hdc, &animationRect, hBrush);
			// Incrementing count
			count++;
		}
	}

	setAnimationPosition(getAnimationPosition() + 1);
	DeleteObject(hBrush);
}

