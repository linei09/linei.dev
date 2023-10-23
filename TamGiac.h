#pragma once
#include "DaGiac.h"
class TamGiac : public DaGiac
{
private:
	float canh1;
	float canh2;
	float canh3;
public:
	friend class Diem;
	TamGiac();
	~TamGiac();
	void setcanh1(float canh1);
	void setcanh2(float canh2);
	void setcanh3(float canh3);
	float getcanh1();
	float getcanh2();
	float getcanh3();
	void nhap();
	void xuat();
	float CV();
	float DT();
};

