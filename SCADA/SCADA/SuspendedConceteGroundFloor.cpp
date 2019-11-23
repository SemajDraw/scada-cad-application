// SuspendedConcreteGroundFloor.cpp
// definition file for SuspendedConcreteGroundFloor class
#include "stdafx.h"
#include "SuspendedConcreteGroundFloor.h"

void SuspendedConcreteGroundFloor::draw(HDC hdc, UINT GRID_SIZE)
{
	// calling createPens function to create pens
	createPens(hdc, GRID_SIZE);

	// creating invisible rectangle around SuspendedConcreteGroundFloor for mouse arrow selection purposes
	RECT compTempRECT;							// creating RECT object compTempRECT
	compTempRECT.left=scrX;						// setting left field of compTempRECT struct
	compTempRECT.top=scrY;						// setting top field of compTempRECT struct	
	compTempRECT.right=scrX+(140*GRID_SIZE);		// setting right field of compTempRECT struct
	compTempRECT.bottom=scrY+(3*GRID_SIZE);		// setting bottom field of compTempRECT 
	setComponentRECT(compTempRECT);				// passing compTempRECT to setComponentRECT member function
	

	// alogorithm for drawing SuspendedConcreteGroundFloor 
	// 1 - drawing top line
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc,  scrX+(130*GRID_SIZE), scrY);

	// 2 - drawing bottom line
	MoveToEx(hdc, scrX, scrY+(3*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(130*GRID_SIZE), scrY+(3*GRID_SIZE));

	// 3 - drawing left vertical line
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc, scrX, scrY+(3*GRID_SIZE));

	// 4 - drawing right vertical line
	MoveToEx(hdc, scrX+(130*GRID_SIZE), scrY, NULL);
	LineTo(hdc, scrX+(130*GRID_SIZE), scrY+(3*GRID_SIZE));

	// 5 - drawing backline
	MoveToEx(hdc, scrX+(20*GRID_SIZE), scrY-(40*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(145*GRID_SIZE), scrY-(40*GRID_SIZE));

	// top left diagonal
	MoveToEx(hdc, scrX, scrY, NULL);
	LineTo(hdc,  scrX+(20*GRID_SIZE), scrY-(40*GRID_SIZE));

	// top right diagonal
	MoveToEx(hdc, scrX+(130*GRID_SIZE), scrY, NULL);
	LineTo(hdc,  scrX+(145*GRID_SIZE), scrY-(40*GRID_SIZE));

	// bottom right diagonal
	MoveToEx(hdc, scrX+(130*GRID_SIZE), scrY+(3*GRID_SIZE), NULL);
	LineTo(hdc,  scrX+(145*GRID_SIZE), scrY-(37*GRID_SIZE));

	//back right connecting line
	MoveToEx(hdc, scrX+(145*GRID_SIZE), scrY-(40*GRID_SIZE), NULL);
	LineTo(hdc,  scrX+(145*GRID_SIZE), scrY-(37*GRID_SIZE));

	// 2 - drawing left leg
	MoveToEx(hdc, scrX+(17*GRID_SIZE), scrY+(3*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(17*GRID_SIZE), scrY+(10*GRID_SIZE));

	MoveToEx(hdc, scrX+(22*GRID_SIZE), scrY+(3*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(22*GRID_SIZE), scrY+(10*GRID_SIZE));

	MoveToEx(hdc, scrX+(17*GRID_SIZE), scrY+(10*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(22*GRID_SIZE), scrY+(10*GRID_SIZE));

	// 2 - drawing right leg
	MoveToEx(hdc, scrX+(115*GRID_SIZE), scrY+(3*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(115*GRID_SIZE), scrY+(10*GRID_SIZE));

	MoveToEx(hdc, scrX+(110*GRID_SIZE), scrY+(3*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(110*GRID_SIZE), scrY+(10*GRID_SIZE));

	MoveToEx(hdc, scrX+(110*GRID_SIZE), scrY+(10*GRID_SIZE), NULL);
	LineTo(hdc, scrX+(115*GRID_SIZE), scrY+(10*GRID_SIZE));

	// calling deletePens function to delete pens and release memory
	deletePens(hdc);
}
