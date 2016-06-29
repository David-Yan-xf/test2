#include "head.h"
#include<string.h>

int mapdata[90][10][10] = { 0 };//栈深，行，列。
int banned[90][10][10][10] = { 0 };//栈深，行，列，填的数字，值为0或1（已经用过）。填的数字若为0，可显示出这一个格子的可能性个数
int datap = 0;//栈顶
int publiclib()
{
	datap = 0;
	mapdata[0][1][5] = 3;
	chgLocBanned(1, 5, 3);
	mapdata[0][8][7] = 3;
	fstream file("a.txt");
	int top,i,j,k;
	file >> top;
	for (int subi = 1; subi <= top; subi++)
	{
		file >> i >> j >> k;
		chgLocBanned(i, j, k);
	}
	file >> top;
	for (int subi = 1; subi <= top; subi++)
	{
		file >> i >> j >> k;
		chgNumBanned(i, j, k);
	}
	chgBannedZero();
	return 0;
}


int chgLocBanned(int i, int j, int k)
{
	for (int tmp = 1; tmp <= 9; tmp++)
		banned[datap][i][j][tmp] = 1;
	for (int subj = 1; subj <= 9; subj++)
		banned[datap][i][subj][k] = 1;
	for (int subi = 1; subi <= 9; subi++)
		banned[datap][subi][j][k] = 1;
	//处理九宫格
	for (int subi = (i - 1) / 3 * 3 + 1; subi <= (i - 1) / 3 * 3 + 3; subi++)
		for (int subj = (j - 1) / 3 * 3 + 1; subj <= (j - 1) / 3 * 3 + 3; subj++)
			banned[datap][subi][subj][k] = 1;
	return 0;
}

int chgNumBanned(int orderID, int headOrEnd, int num)
{
	//行
	if (orderID / 10 == 1)
	{
		int i = orderID % 10;
		if (headOrEnd == 0)
		{
			for (int subj = 1; subj <= num - 1; subj++)
				for (int tmp = 10 - num + subj; tmp <= 9; tmp++)
					banned[datap][i][subj][tmp] = 1;
			if (num == 1)
			{
				for (int tmp = 1; tmp <= 8; tmp++)
					banned[datap][i][1][tmp] = 1;
			}
		}
		else
		{
			for (int subj = 9; subj >= 11 - num; subj--)
				for (int tmp = 20 - num - subj; tmp <= 9; tmp++)
					banned[datap][i][subj][tmp] = 1;
			if (num == 1)
			{
				for (int tmp = 1; tmp <= 8; tmp++)
					banned[datap][i][9][tmp] = 1;
			}
		}
	}
	//列
	else
	{
		int j = orderID % 10;
		if (headOrEnd == 0)
		{
			for (int subi = 1; subi <= num - 1; subi++)
				for (int tmp = 10 - num + subi; tmp <= 9; tmp++)
					banned[datap][subi][j][tmp] = 1;
			if (num == 1)
			{
				for (int tmp = 1; tmp <= 8; tmp++)
					banned[datap][1][j][tmp] = 1;
			}
		}
		else
		{
			for (int subi = 9; subi >= 11 - num; subi--)
				for (int tmp = 20 - num - subi; tmp <= 9; tmp++)
					banned[datap][subi][j][tmp] = 1;
			if (num == 1)
			{
				for (int tmp = 1; tmp <= 8; tmp++)
					banned[datap][9][j][tmp] = 1;
			}
		}
	}
	return 0;
}
int chgBannedZero()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			banned[datap][i][j][0] = 9;
			for (int k = 1; k <= 9; k++)
				banned[datap][i][j][0] -= banned[datap][i][j][k];
			if (banned[datap][i][j][0] == 0)
				banned[datap][i][j][0] = 1;//为了不影响乘积体现的状态数
		}
	return 0;
}
int outputData()
{
	return 0;
}

int upData()
{
	return 0;
}

int upBanned()
{
	return 0;
}

int recover()
{
	return 0;
}

commander::commander(int tmp)
{
	memset(orderPath, 0, (90 * sizeof(int)));
	orderp = 0;
}

int commander::upOrderPath()
{
	return 0;
}

int commander::recoverOrderPath()
{
	return 0;
}

int commander::seekBanned()
{
	int min = 1000000000;
	for (int ID1 = 1; ID1 <= 3; ID1++)
		for (int ID2 = 1; ID2 <= 9; ID2++)
		{
			
		}
	return 0;
}

int commander::findSolution()
{
	return 0;
}

units::units()
{
}

int units::upChoicePath()
{
	return 0;
}

int units::recoverChoicePath()
{
	return 0;
}

lines::lines(int)
{
}

int lines::fill()
{
	return 0;
}

squares::squares(int)
{
}

int squares::fill()
{
	return 0;
}
