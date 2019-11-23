// CornerPipe.cpp
// definition file for CornerPipe class
#include "stdafx.h"
#include "CornerPipe.h"

void CornerPipe::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around CornerPipe for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top = scrY;					// setting top field of compTempRECT struct
	compTempRECT.left = scrX;					// setting left field of compTempRECT struct
	compTempRECT.right = scrX+2*GRID_SIZE;		// setting right field of compTempRECT 
	compTempRECT.bottom = scrY+2*GRID_SIZE;		// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

	// alogorithm for drawing CornerPipe
	orientation2 orient = (orientation2)getOrientation();
	switch (orientation2(getOrientation()))
	{
	case orientation2::left:
		MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY+(getFuture0()*GRID_SIZE)*2, NULL);
		AngleArc(hdc, scrX, scrY+(getFuture0()*GRID_SIZE)*2, (getFuture0()*GRID_SIZE)*2, 0, 90);
		MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE), scrY+(getFuture0()*GRID_SIZE)*2, NULL);
		AngleArc(hdc, scrX, scrY+(getFuture0()*GRID_SIZE)*2, (getFuture0()*GRID_SIZE), 0, 90);
		break;
	case orientation2::top:
		MoveToEx(hdc, scrX, scrY+(getFuture0()*GRID_SIZE)*2, NULL);
		AngleArc(hdc, scrX, scrY, (getFuture0()*GRID_SIZE)*2, 270, 90);
		MoveToEx(hdc, scrX, scrY+(getFuture0()*GRID_SIZE), NULL);
		AngleArc(hdc, scrX, scrY, (getFuture0()*GRID_SIZE), 270, 90);
		break;
	case orientation2::right:
		MoveToEx(hdc, scrX, scrY, NULL);
		AngleArc(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY, (getFuture0()*GRID_SIZE)*2, 180, 90);
		MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE), scrY, NULL);
		AngleArc(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY, (getFuture0()*GRID_SIZE), 180, 90);
		break;
	case orientation2::bottom:
		MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY, NULL);
		AngleArc(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY+(getFuture0()*GRID_SIZE)*2, (getFuture0()*GRID_SIZE)*2, 90, 90);
		MoveToEx(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY+(getFuture0()*GRID_SIZE), NULL);
		AngleArc(hdc, scrX+(getFuture0()*GRID_SIZE)*2, scrY+(getFuture0()*GRID_SIZE)*2, (getFuture0()*GRID_SIZE), 90, 90);
		break;
	default:	//A message box to warn of an error //only during debug
		break;
	}

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void CornerPipe::animate(HDC hdc, UINT GRID_SIZE)
{
		HBRUSH hBrush = CreateSolidBrush(RGB(19, 183, 237));
		int animateLength = 2;

		if(getAnimationPosition()>=animateLength 
		|| getAnimationPosition()>getFuture0()
		|| getAnimationPosition()<0)
		setAnimationPosition(0);

		RECT animationRect;
		RECT a2;
		int count = 0;
	//draw the animation
	if(getOrientation()==orientation2::top)
	{
		while(getAnimationPosition()+count*animateLength<getFuture0())
		{
			// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.top = scrY+(1*GRID_SIZE);			// setting top field of compTempRECT struct
			animationRect.left = scrX+(.1*GRID_SIZE);		// setting left field of compTempRECT struct
			animationRect.right = scrX+(.9*GRID_SIZE);		// setting right field of compTempRECT 
			animationRect.bottom = scrY+(1.9*GRID_SIZE);	// setting bottom field of compTempRECT struct

			animationRect.left+=2;
			animationRect.top+=2;

			FillRect(hdc, &animationRect, hBrush);

			getComponentRECT(a2);
			// Setting initial animation position
			a2.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			a2.top = scrY;//-(1*GRID_SIZE);			// setting top field of compTempRECT struct
			a2.left = scrX+(1.1*GRID_SIZE);			// setting left field of compTempRECT struct
			a2.right = scrX+(1.9*GRID_SIZE);		// setting right field of compTempRECT 
			a2.bottom = scrY+(.9*GRID_SIZE);		// setting bottom field of compTempRECT struct

			a2.left+=2;
			a2.top+=2;

			FillRect(hdc, &a2, hBrush);

			count++;
		}
	}
	else if(getOrientation()==orientation2::bottom)
	{
		while(getAnimationPosition()+count*animateLength<getFuture0())
		{
			// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.top = scrY+(1*GRID_SIZE);			// setting top field of compTempRECT struct
			animationRect.left = scrX+(.1*GRID_SIZE);		// setting left field of compTempRECT struct
			animationRect.right = scrX+(.9*GRID_SIZE);		// setting right field of compTempRECT 
			animationRect.bottom = scrY+(1.9*GRID_SIZE);	// setting bottom field of compTempRECT struct

			animationRect.left+=2;
			animationRect.top+=2;

			FillRect(hdc, &animationRect, hBrush);

			getComponentRECT(a2);
			// Setting initial animation position
			a2.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			a2.top = scrY;//-(1*GRID_SIZE);			// setting top field of compTempRECT struct
			a2.left = scrX+(1.1*GRID_SIZE);			// setting left field of compTempRECT struct
			a2.right = scrX+(1.9*GRID_SIZE);		// setting right field of compTempRECT 
			a2.bottom = scrY+(.9*GRID_SIZE);		// setting bottom field of compTempRECT struct

			a2.left+=2;
			a2.top+=2;

			FillRect(hdc, &a2, hBrush);

			count++;
		}
	}
	else if(getOrientation()==orientation2::right)
	{
		while(getAnimationPosition()+count*animateLength<getFuture0())
		{
		// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.top = scrY+(1*GRID_SIZE);			// setting top field of compTempRECT struct
			animationRect.left = scrX+(1.1*GRID_SIZE);		// setting left field of compTempRECT struct
			animationRect.right = scrX+(1.9*GRID_SIZE);		// setting right field of compTempRECT 
			animationRect.bottom = scrY+(1.9*GRID_SIZE);	// setting bottom field of compTempRECT struct

			animationRect.left+=2;
			animationRect.top+=2;

			FillRect(hdc, &animationRect, hBrush);

			getComponentRECT(a2);
			// Setting initial animation position
			a2.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			a2.top = scrY;						// setting top field of compTempRECT struct
			a2.left = scrX+(.1*GRID_SIZE);		// setting left field of compTempRECT struct
			a2.right = scrX+(.9*GRID_SIZE);		// setting right field of compTempRECT 
			a2.bottom = scrY+(.9*GRID_SIZE);	// setting bottom field of compTempRECT struct

			a2.left+=2;
			a2.top+=2;

			FillRect(hdc, &a2, hBrush);

			count++;
		}
	}
	else if(getOrientation()==orientation2::left)
	{
		while(getAnimationPosition()+count*animateLength<getFuture0())
		{
		// Gettign the componenents bounding rectangle
			getComponentRECT(animationRect);
			// Setting initial animation position
			animationRect.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			animationRect.top = scrY+(1*GRID_SIZE);			// setting top field of compTempRECT struct
			animationRect.left = scrX+(1.1*GRID_SIZE);		// setting left field of compTempRECT struct
			animationRect.right = scrX+(1.9*GRID_SIZE);		// setting right field of compTempRECT 
			animationRect.bottom = scrY+(1.9*GRID_SIZE);	// setting bottom field of compTempRECT struct

			animationRect.left+=2;
			animationRect.top+=2;

			FillRect(hdc, &animationRect, hBrush);

			getComponentRECT(a2);
			// Setting initial animation position
			a2.left+=getAnimationPosition()*GRID_SIZE+count*animateLength*GRID_SIZE;
			// Setting bounds for the animation rectangle
			a2.top = scrY;						// setting top field of compTempRECT struct
			a2.left = scrX+(.1*GRID_SIZE);		// setting left field of compTempRECT struct
			a2.right = scrX+(.9*GRID_SIZE);		// setting right field of compTempRECT 
			a2.bottom = scrY+(.9*GRID_SIZE);	// setting bottom field of compTempRECT struct

			a2.left+=2;
			a2.top+=2;

			FillRect(hdc, &a2, hBrush);

			count++;
		}
	}

	setAnimationPosition(getAnimationPosition()+1);
	DeleteObject(hBrush);
	
}
