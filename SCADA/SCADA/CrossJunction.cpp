// CrossJunction.cpp
// definition file for CrossJunction class
#include "stdafx.h"
#include "CrossJunction.h"

void CrossJunction::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around CrossJunction for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top=scrY;						// setting top field of compTempRECT struct
	compTempRECT.left=scrX;						// setting left field of compTempRECT struct
	compTempRECT.right=scrX+(3*GRID_SIZE);		// setting right field of compTempRECT 
	compTempRECT.bottom=scrY+(2*GRID_SIZE);		// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

	RECT compTempRECT1;							// creating RECT object compTempRECT
	compTempRECT1.top=scrY-(4*GRID_SIZE);		// setting top field of compTempRECT struct
	compTempRECT1.left=scrX+(GRID_SIZE);		// setting left field of compTempRECT struct
	compTempRECT1.right=scrX+(3*GRID_SIZE);		// setting right field of compTempRECT 
	compTempRECT1.bottom=scrY+(GRID_SIZE);		// setting bottom field of compTempRECT struct
	setComponentRECT1(compTempRECT1);			// passing compTempRECT to setCompRECT member function

		
	// alogorithm for drawing CrossJunction 
	// 1 - drawing first line
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(GRID_SIZE*getFuture0())/3, scrY);

	// 2 - drawing second line parrallel to first line
	MoveToEx(hdc, scrX, scrY+(GRID_SIZE*getFuture0())/3, NULL);
	LineTo(hdc, scrX+(GRID_SIZE*getFuture0())/3, scrY+(GRID_SIZE*getFuture0())/3);

	// 3 - drawing third line perpendicular to first
	MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0())/3, scrY, NULL);
	LineTo(hdc, scrX+(GRID_SIZE*getFuture0())/3, scrY-(GRID_SIZE*getFuture0())/3);

	// 4 - drawing forth line inverse perpendicular to second
	MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0())/3, scrY+(GRID_SIZE*getFuture0())/3, NULL);
	LineTo(hdc, scrX+(GRID_SIZE*getFuture0())/3, scrY+(2*GRID_SIZE*getFuture0())/3);

	// 5 - drawing fifth line in parallel with first line on other side
	MoveToEx(hdc, scrX+(2*GRID_SIZE*getFuture0())/3, scrY, NULL);
	LineTo(hdc, scrX+(3*GRID_SIZE*getFuture0())/3, scrY);

	// 6 - drawing sixth line in parallel second line on other side
	MoveToEx(hdc, scrX+(2*GRID_SIZE*getFuture0())/3, scrY+(GRID_SIZE*getFuture0())/3, NULL);
	LineTo(hdc, scrX+(3*GRID_SIZE*getFuture0())/3, scrY+(GRID_SIZE*getFuture0())/3);

	// 7 - drawing seventh line perpendicular to fifth line on other side
	MoveToEx(hdc, scrX+(2*GRID_SIZE*getFuture0())/3, scrY, NULL);
	LineTo(hdc, scrX+(2*GRID_SIZE*getFuture0())/3, scrY-(GRID_SIZE*getFuture0())/3);

	// 8 drawing eight line inverse perpendicular to sixth line on other side 
	MoveToEx(hdc, scrX+(2*GRID_SIZE*getFuture0())/3, scrY+(GRID_SIZE*getFuture0())/3, NULL);
	LineTo(hdc, scrX+(2*GRID_SIZE*getFuture0())/3, scrY+(2*GRID_SIZE*getFuture0())/3);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}
		
void CrossJunction::animate(HDC hdc, UINT GRID_SIZE)
{
	// Creating brush of light blue color
	HBRUSH hBrush=CreateSolidBrush(RGB(19,183,237));	

	// Setting animation length
	int animateLength = 3;

	// Checking if animation is out of bounds
	// and if so setting to zero
	if(getAnimationPosition()>=animateLength 
		|| getAnimationPosition()>getFuture0()
		|| getAnimationPosition()<0)
		setAnimationPosition(0);

	// drawing the animation
	// Creating RECT
	RECT animationRect;
	// Initializing count and setting to zero
	int count=0;

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
	