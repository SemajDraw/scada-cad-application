// CCTVCamera.cpp
// definition file for CCTVCamera class
#include "stdafx.h"
#include "CCTVCamera.h"

void CCTVCamera::draw(HDC hdc, UINT GRID_SIZE)
{
	
	// calling createPens function to create pens
	BaseComponent::createPens(hdc, GRID_SIZE);
	
	// creating invisible rectangle around CCTVCamera for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top = scrY-(3*GRID_SIZE);		// setting top field of compTempRECT struct
	compTempRECT.left = scrX; 					// setting left field of compTempRECT struct
	compTempRECT.right = scrX+(5*GRID_SIZE); 	// setting right field of compTempRECT 
	compTempRECT.bottom = scrY+(2*GRID_SIZE);	// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function
	
	// alogorithm for drawing CCTVCamera 
	// 1 - drawing top line of camera
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(3*GRID_SIZE), scrY);

	// 2 - drawing top back line of camera ADDED CODE
	MoveToEx(hdc, scrX+(5*GRID_SIZE), scrY-(GRID_SIZE*2), NULL);
	LineTo(hdc, scrX+(2*GRID_SIZE), scrY-(GRID_SIZE*2));

	// 3 - drawing top right diagonal line of camera ADDED CODE
	MoveToEx(hdc, scrX+(3*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(5*GRID_SIZE), scrY-(GRID_SIZE*2));

	// 4 - drawing top left diagonal line of camera ADDED CODE
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(2*GRID_SIZE), scrY-(GRID_SIZE*2));

	// 5 - drawing bottom line of camera
	MoveToEx(hdc, scrX, scrY+GRID_SIZE*2, NULL);
	LineTo(hdc, scrX+(3*GRID_SIZE), scrY+(GRID_SIZE*2));

	// 6 - drawing bottom diagonal line of camera ADDED CODE
	MoveToEx(hdc, scrX+(3*GRID_SIZE), scrY+(GRID_SIZE*2), NULL);
	LineTo(hdc, scrX+(5*GRID_SIZE), scrY);

	// 7 - drawing back right vertical line of camera ADDED CODE
	MoveToEx(hdc, scrX+(5*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(5*GRID_SIZE), scrY-(GRID_SIZE*2));

	// 8 - drawing left vertical line of camera
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX, scrY+GRID_SIZE*2);

	// 9 - drawing right vertical line of camera
	MoveToEx(hdc, scrX+(3*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(3*GRID_SIZE), scrY+(GRID_SIZE*2));

	// 10  drawing lens ADDED CODE
	MoveToEx(hdc, scrX+(GRID_SIZE*2.5), scrY+5, NULL);
	AngleArc(hdc, scrX+(GRID_SIZE*1.5), scrY+(GRID_SIZE), GRID_SIZE, 360, 360);
	AngleArc(hdc, scrX+(GRID_SIZE*1.5), scrY+(GRID_SIZE), GRID_SIZE-2, 360, 360);

	// 11 drawing stand for camera
	MoveToEx(hdc, scrX+(3.5*GRID_SIZE), scrY+(6*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(3.5*GRID_SIZE), scrY+(1.5*GRID_SIZE));

	// 12 drawing stand for camera ADDED CODE
	MoveToEx(hdc, scrX+(1.5*GRID_SIZE), scrY+(6*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(1.5*GRID_SIZE), scrY+(2*GRID_SIZE));

	// 13 Draw light on camera ADDED CODE
	HBRUSH hbr=CreateSolidBrush(RGB(0,0,0)); //red brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	Ellipse(hdc, scrX+(GRID_SIZE*2.5), scrY+(GRID_SIZE-6),scrX+(3*GRID_SIZE),scrY+(GRID_SIZE-2));
	SelectObject(hdc,hOld);
	DeleteObject(hbr);
		
	// calling deletePens function to delete pens and release memory
	BaseComponent::deletePens(hdc);
}

void CCTVCamera::animate(HDC hdc, UINT GRID_SIZE)
{

	// Light turnnig on ADDED CODE
	HBRUSH hbr=CreateSolidBrush(RGB(255,0,0)); //red brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	Ellipse(hdc, scrX+(GRID_SIZE*2.5), scrY+(GRID_SIZE-6),scrX+(3*GRID_SIZE),scrY+(GRID_SIZE-2));
	SelectObject(hdc,hOld);
	DeleteObject(hbr);

}