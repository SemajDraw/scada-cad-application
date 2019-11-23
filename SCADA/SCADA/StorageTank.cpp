// StorageTank.cpp
// definition file for StorageTank class
#include "stdafx.h"
#include "StorageTank.h"

void StorageTank::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around WaterSource for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.top=scrY-(GRID_SIZE);						// setting top field of compTempRECT struct
	compTempRECT.left=scrX;						// setting left field of compTempRECT struct
	compTempRECT.right=scrX+(21*GRID_SIZE);		// setting right field of compTempRECT 
	compTempRECT.bottom=scrY+(8*GRID_SIZE);		// setting bottom field of compTempRECT struct
	setComponentRECT(compTempRECT);				// passing compTempRECT to setCompRECT member function

	// back panel
	Rectangle(hdc, scrX+(GRID_SIZE), scrY-(GRID_SIZE), scrX+(21*GRID_SIZE), scrY+(7*GRID_SIZE));
	
	// front panel
	Rectangle(hdc, scrX, scrY, scrX+(20*GRID_SIZE), scrY+(8*GRID_SIZE));

	// water pipe
	Ellipse(hdc, scrX+(GRID_SIZE*5.2), scrY-(GRID_SIZE),scrX+(4*GRID_SIZE),scrY);
	MoveToEx(hdc, scrX+(GRID_SIZE*5), scrY-(GRID_SIZE/2.9), NULL);
	LineTo(hdc, scrX+(GRID_SIZE*5), scrY-(3*GRID_SIZE));
	MoveToEx(hdc, scrX+(4*GRID_SIZE),scrY-(GRID_SIZE/2.9), NULL);
	LineTo(hdc, scrX+(4*GRID_SIZE), scrY-(3*GRID_SIZE));

	// top left diagonal
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX+(GRID_SIZE), scrY-(GRID_SIZE));

	//top right diagonal
	MoveToEx(hdc, scrX+(20*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(21*GRID_SIZE), scrY-(GRID_SIZE));

	//bottom right diagonal
	MoveToEx(hdc, scrX+(20*GRID_SIZE), scrY+(8*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(21*GRID_SIZE), scrY+(7*GRID_SIZE));

	//middle rectangle with fill
	HBRUSH hbr=CreateSolidBrush(RGB(255,255,255)); //white brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	RoundRect(hdc, scrX+(2*GRID_SIZE), scrY+(GRID_SIZE), scrX+(18*GRID_SIZE), scrY+(7*GRID_SIZE), GRID_SIZE, GRID_SIZE);
	SelectObject(hdc,hOld);
	DeleteObject(hbr);

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}

void StorageTank::animate(HDC hdc, UINT GRID_SIZE)
{
	HBRUSH hbr=CreateSolidBrush(RGB(19,183,237)); //blue brush
	HBRUSH hOld=(HBRUSH)SelectObject(hdc,hbr);
	RoundRect(hdc, scrX+(2*GRID_SIZE),scrY+(GRID_SIZE*7), scrX+(18*GRID_SIZE),scrY+((GRID_SIZE*7)-(GRID_SIZE*6)*(*analogPtr/255)) , GRID_SIZE, GRID_SIZE);
	SelectObject(hdc,hOld);
	DeleteObject(hbr);

}
