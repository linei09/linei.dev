#include "TamGiac.h"
#include "DaGiac.h"
#include <iostream>

using namespace std;
TamGiac::TamGiac()
{
	setSLCanh(3);
}
TamGiac :: ~TamGiac()
{

}
void TamGiac::nhap()
{
		cout << "Nhap lan luot do dai cac canh\n";
		float x, y, z;
		cin >> x >> y >> z;
		setcanh1(x);
		setcanh2(y);
		setcanh3(z);
}
float TamGiac::CV()
{
	return (getcanh1() + getcanh2() + getcanh3());

}
float TamGiac::DT()
{
	return 
}