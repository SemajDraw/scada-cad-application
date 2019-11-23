// SanitizationDrain.cpp
// definition file for SanitizationDrain class
#include "stdafx.h"
#include "SanitizationDrain.h"

void SanitizationDrain::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around SanitizationDrain for mouse arrow selection purposes
	RECT compTempRECT;								// creating RECT object compTempRECT
	compTempRECT.top= scrY-(2*GRID_SIZE);			// setting top field of compTempRECT struct
	compTempRECT.left = scrX;						// setting left field of compTempRECT struct
	compTempRECT.right = scrX+(8*GRID_SIZE);		// setting right field of compTempRECT 
	compTempRECT.bottom = scrY+(7*GRID_SIZE);						// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);		

	//Back Panel
	Rectangle(hdc, scrX+(1*GRID_SIZE), scrY-(2*GRID_SIZE), scrX+(8*GRID_SIZE), scrY+(5*GRID_SIZE));
	// front panel
	Rectangle(hdc, scrX, scrY, scrX+(7*GRID_SIZE), scrY+(7*GRID_SIZE));
	// top left diagonal
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(GRID_SIZE), scrY-(2*GRID_SIZE));
	//Horizontal pipe top line
	MoveToEx(hdc, scrX, scrY+(1*GRID_SIZE), NULL);
	LineTo(hdc, scrX-(2*GRID_SIZE), scrY+(1*GRID_SIZE));
	//Horizontal pipe bottom line
	MoveToEx(hdc, scrX, scrY+(2*GRID_SIZE), NULL);
	LineTo(hdc, scrX-(3*GRID_SIZE), scrY+(2*GRID_SIZE));
	//Vertical pipe left line
	MoveToEx(hdc, scrX-(3*GRID_SIZE), scrY+(2*GRID_SIZE), NULL);
	LineTo(hdc, scrX-(3*GRID_SIZE), scrY-(GRID_SIZE));
	//Funnel left line
	MoveToEx(hdc, scrX-(3*GRID_SIZE), scrY-(GRID_SIZE), NULL);
	LineTo(hdc, scrX-(4*GRID_SIZE), scrY-(2*GRID_SIZE));
	
	//Vertical pipe right line
	MoveToEx(hdc, scrX-(2*GRID_SIZE), scrY+(1*GRID_SIZE), NULL);
	LineTo(hdc, scrX-(2*GRID_SIZE), scrY-(GRID_SIZE));
	//Funnel right line
	MoveToEx(hdc, scrX-(2*GRID_SIZE), scrY-(GRID_SIZE), NULL);
	LineTo(hdc, scrX-(GRID_SIZE), scrY-(2*GRID_SIZE));
	//Funnel angle
	Ellipse(hdc, scrX-(4*GRID_SIZE), scrY-(2.5*GRID_SIZE),scrX-GRID_SIZE,scrY-(1.5*GRID_SIZE));

	//top right diagonal
	MoveToEx(hdc, scrX+(7*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(8*GRID_SIZE), scrY-(2*GRID_SIZE));
	//bottom right diagonal
	MoveToEx(hdc, scrX+(7*GRID_SIZE), scrY+(7*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(8*GRID_SIZE), scrY+(5*GRID_SIZE));

	RoundRect(hdc, scrX+(1*GRID_SIZE), scrY+(1*GRID_SIZE), scrX+(6*GRID_SIZE), scrY+(6*GRID_SIZE), GRID_SIZE, GRID_SIZE);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void SanitizationDrain::animate(HDC hdc, UINT GRID_SIZE)
{
	HBRUSH hbr=CreateSolidBrush(RGB(80,102,*analogPtr)); //Water gets cleaner as pot turns
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	RoundRect(hdc, scrX+(1*GRID_SIZE), scrY+(1*GRID_SIZE), scrX+(6*GRID_SIZE), scrY+(6*GRID_SIZE), GRID_SIZE, GRID_SIZE);
	SelectObject(hdc,hOld);
	DeleteObject(hbr);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}