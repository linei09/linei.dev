#pragma once
class DaGiac
{
protected:
	int SLCanh;
	float canh;
public:
	DaGiac();
	~DaGiac();
	void setSLCanh(int SLCanh);
	int getSLCanh();
	void setcanh(float canh);
	float getcanh();
	virtual float CV() = 0;
	virtual float DT() = 0;
	virtual void nhap() = 0;
	virtual void xuat() = 0;
};

