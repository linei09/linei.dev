#include "sophuc.h"
#include <iostream>
sophuc::sophuc()
{

}
sophuc :: ~sophuc()
{

}
sophuc::sophuc(int phanthuc, int phanao)
{
	this->phanthuc = phanthuc;
	this->phanao = phanao;
}
void sophuc::setphanao(int phanao)
{
	this->phanao = phanao;
}
void sophuc::setsophuc(int phanthuc, int phanao)
{
	this->phanthuc = phanthuc;
	this->phanao = phanao;
}
void sophuc::setphanthuc(int phanthuc)
{
	this->phanthuc = phanthuc;
}
int sophuc::getphanao()
{
	return phanao;
}
int sophuc::getphanthuc()
{
	return phanthuc;
}
sophuc sophuc :: operator+ (sophuc b)
{
	int thucmoi = this->phanthuc + b.getphanthuc();
	int aomoi = this->phanao + b.getphanao();
	sophuc c (thucmoi, aomoi);
	return c;
}