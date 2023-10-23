//Làm lại bài số phức với một phương thức thiết lập duy nhất cho phép quan điểm một số thực như một số phức đặc biệt
//(phần ảo bằng 0). Định nghĩa các phép toán +, -, *, /, = =, !=, >, >=, <, <= trên số phức. 
//Định nghĩa phép toán << và >> để xuất và nhập dữ liệu vào số phức.
#include <iostream>
using namespace std;
#include "sophuc.h"
int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	sophuc e(a, b);
	sophuc f(c, d);
	sophuc g = e + f;
	return 0;
}