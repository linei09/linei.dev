#include "DaGiac.h"
#include "Diem.h"
#include "TamGiac.h"
#include "TuGiac.h"
#include <iostream>
using namespace std;
int main()
{
	TamGiac a;
	TuGiac b;
	cout << "Nhap tam giac" << endl;
	a.nhap();
	if (a.DK())
	{
		a.xuat();
	}
	else {
		cout << "Khong phai la tam giac" << endl;
	}
	cout << "Nhap tu giac" << endl;
	b.nhap();
	if (b.DK())
	{
		b.xuat();
	}
	else
	{
		cout << "Khong phai la tu giac" << endl;
	}

}