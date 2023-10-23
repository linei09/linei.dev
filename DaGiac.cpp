#include "DaGiac.h"
#include <iostream>
using namespace std;
DaGiac::DaGiac()
{

}
DaGiac :: ~DaGiac()
{

}
void DaGiac::setcanh(float canh)
{
	this->canh = canh;
}
void DaGiac::setSLCanh(int SLCanh)
{
	this->SLCanh = SLCanh;
}
int DaGiac::getSLCanh()
{
	return SLCanh;
}
float DaGiac::getcanh()
{
	return canh;
}
