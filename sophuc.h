#pragma once
class sophuc
{
private:
	int phanao;
	int phanthuc;
public:
	sophuc();
	~sophuc();
	sophuc(int phanthuc, int phanao);
	void setphanao(int phanao);
	void setphanthuc(int phanthuc);
	void setsophuc(int phanthuc, int phanao);
	int getphanao();
	int getphanthuc();
	sophuc operator+ (sophuc b);
};

