// PressureGauge.h
// header file for PressureGauge class
#include "BaseComponent.h"

#ifndef PRESSUREGAUGE_H
#define PRESSUREGAUGE_H
class PressureGauge: public BaseComponent
{
public:
	PressureGauge():BaseComponent(){}
	PressureGauge(int ID, int iX, int iY, int ival0, int ival1, int ival2, int ival3):
		BaseComponent(ID, iX, iY, ival0, ival1, ival2, ival3){}
	~PressureGauge(){}
	
	void draw(HDC hdc, UINT GRID_SIZE);
	void animate(HDC hdc, UINT GRID_SIZE);
};
#endif