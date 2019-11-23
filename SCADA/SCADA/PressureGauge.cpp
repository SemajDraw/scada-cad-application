// PressureGauge.cpp
// definition file for WaterSource class
#include "stdafx.h"
#include "PressureGauge.h"

void PressureGauge::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around Pressure Gauge for mouse arrow selection purposes
	RECT compTempRECT;					// creating RECT object compTempRECT
	compTempRECT.top = scrY;			// setting top field of compTempRECT struct
	compTempRECT.left = scrX;			// setting left field of compTempRECT struct

	// alogorithm for drawing Pressure Gauge
	if(getOrientation() == 0 || getOrientation() == 2)		// if the component is horizontal
	{
		// creating invisible rectangle around IronPipe for mouse arrow selection purposes
		compTempRECT.right=scrX+(getFuture0()*GRID_SIZE);		// setting right field of compTempRECT struct
		compTempRECT.bottom=scrY+GRID_SIZE;			// setting bottom field of compTempRECT struct
		setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

		// draw component
		
		// 1 - drawing first horizontal line
		MoveToEx(hdc, scrX, scrY, NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()), scrY);
		
		// 2 - drawing second horizontal parallel line
		MoveToEx(hdc, scrX, scrY+GRID_SIZE, NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()), scrY+GRID_SIZE);

		// 3 - drawing pole
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4), scrY, NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4), scrY-(GRID_SIZE*getFuture0()/3)); 

		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3), scrY, NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3), scrY-(GRID_SIZE*getFuture0()/3));

		// 4 -drawing gauge
		HBRUSH hbr=CreateSolidBrush(RGB(120,120,120)); //grey brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), scrY-(GRID_SIZE*getFuture0()/2),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25), scrY-(GRID_SIZE*getFuture0()/6));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 4 -drawing gauge
		HBRUSH hbr1=CreateSolidBrush(RGB(192,192,192)); //grey brush
	    HBRUSH hOld1=(HBRUSH)SelectObject(hdc,hbr1);
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25), scrY-(GRID_SIZE*getFuture0()/2),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75), scrY-(GRID_SIZE*getFuture0()/6));
		SelectObject(hdc,hOld1);
	    DeleteObject(hbr1);

		// 5 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.5),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5));

	    // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.05), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*5), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5.25));
	}

	else if(getOrientation() == 1 || getOrientation() == 3)	// if the component is vertical
	{
		// creating invisible rectangle around IronPipe for mouse arrow selection purposes
		compTempRECT.right=scrX+GRID_SIZE;				// setting right field of compTempRECT 
		compTempRECT.bottom=scrY+(getFuture0()*GRID_SIZE);   // setting bottom field of compTempRECT struct
		setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

		//draw component
		// 1 - drawing first vertical line 
		MoveToEx(hdc, scrX, scrY, NULL);
		LineTo(hdc, scrX, scrY+(getFuture0()*GRID_SIZE));

		// 2 -drawing second parallel vertical line
		MoveToEx(hdc, scrX+GRID_SIZE, scrY, NULL);
		LineTo(hdc, scrX+GRID_SIZE, scrY+(getFuture0()*GRID_SIZE));

		// 3 -drawing pole
		MoveToEx(hdc, scrX+GRID_SIZE, scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()/2), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4)); 

		MoveToEx(hdc, scrX+GRID_SIZE, scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()/2), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3)); 

		// 4 -drawing gauge
		HBRUSH hbr=CreateSolidBrush(RGB(120,120,120)); //grey brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25),scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 5 -drawing gauge
		HBRUSH hbr1=CreateSolidBrush(RGB(192,192,192)); //grey brush
	    HBRUSH hOld1=(HBRUSH)SelectObject(hdc,hbr1);
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25),scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75));
		SelectObject(hdc,hOld1);
	    DeleteObject(hbr1);

		// 6 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25));

		 // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.5), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*5));
	}

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}


void PressureGauge::animate(HDC hdc, UINT GRID_SIZE)
{
	// Creating brush of light blue color
	HBRUSH hBrush=CreateSolidBrush(RGB(19,183,237));	

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
	RECT animationRect;
	// Initializing count and setting to zero
	int count=0;

	// Checking if orientation is left or right
	if(getOrientation()==orientation2::left || getOrientation()==orientation2::right)
	{
		while(getAnimationPosition()+count*animateLength<getFuture0())
		{
			// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.right=animationRect.left+GRID_SIZE-1;
			animationRect.bottom=animationRect.top+GRID_SIZE-1;
			animationRect.left+=2;
			animationRect.top+=2;
			// Filling rectangle with a light blue brush
			FillRect(hdc, &animationRect, hBrush);
			// Incrementing count
			count++;
		}
	}
	// otherwise executing this code for pipe in vertical position
	else
	{
		while(getAnimationPosition()+count*animateLength<getFuture0())
		{
			// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.top+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.right=animationRect.left+GRID_SIZE-1;
			animationRect.bottom=animationRect.top+GRID_SIZE-1;
			animationRect.left+=2;
			animationRect.top+=2;
			// Filling rectangle with a light blue brush
			FillRect(hdc, &animationRect, hBrush);
			// Incrementing count
			count++;
		}
	}

	setAnimationPosition(getAnimationPosition()+1);
	DeleteObject(hBrush);

	if(getOrientation()==orientation2::left || getOrientation()==orientation2::right)
	{

		if(*analogPtr < 125)
	{
		HBRUSH hbr=CreateSolidBrush(RGB(0,255,0)); //green brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		// 4 -drawing gauge
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25), scrY-(GRID_SIZE*getFuture0()/2),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75), scrY-(GRID_SIZE*getFuture0()/6));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 5 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.5),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5));

	    // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.05), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*5), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5.25));
	}
	else if(*analogPtr >= 125 && *analogPtr <= 200)
	{
		HBRUSH hbr=CreateSolidBrush(RGB(255,255,50)); //yellow brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		// 4 -drawing gauge
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25), scrY-(GRID_SIZE*getFuture0()/2),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75), scrY-(GRID_SIZE*getFuture0()/6));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 5 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.5),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5));

	    // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.05), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.05), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*3.5));
	
	}
	else if(*analogPtr > 200)
		{
		HBRUSH hbr=CreateSolidBrush(RGB(255,0,0)); //red brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		// 4 -drawing gauge
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25), scrY-(GRID_SIZE*getFuture0()/2),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75), scrY-(GRID_SIZE*getFuture0()/6));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 5 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.5),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5));

	    // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.05), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.8), scrY-(GRID_SIZE*getFuture0()-GRID_SIZE*5.25));
	}

	}

else
	{

	
	if(*analogPtr < 125)
	{
		HBRUSH hbr=CreateSolidBrush(RGB(0,255,0)); //green brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		// 5 -drawing gauge
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25),scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 6 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25));

		 // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.5), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*5));
	}
	else if(*analogPtr >= 125 && *analogPtr <= 200)
	{
		HBRUSH hbr=CreateSolidBrush(RGB(255,255,50)); //yellow brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		// 5 -drawing gauge
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25),scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 6 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25));

		 // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.5), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.5), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4));
	
	}
	else if(*analogPtr > 200)
		{
		HBRUSH hbr=CreateSolidBrush(RGB(255,0,0)); //red brush
	    HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
		// 5 -drawing gauge
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*5.25),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*2.25),scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*2.75));
		SelectObject(hdc,hOld);
	    DeleteObject(hbr);

		// 6 -drawing needle pole
		Ellipse(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75),
					 scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.75), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25));

		 // 6 -drawing needle 
		MoveToEx(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*3.5), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*4), NULL);
		LineTo(hdc, scrX+(GRID_SIZE*getFuture0()-GRID_SIZE*4.25), scrY+(GRID_SIZE*getFuture0()-GRID_SIZE*3));
	
	}
 }

}
