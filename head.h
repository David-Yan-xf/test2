#pragma once
#include<iostream>
#include<fstream>
using namespace std;

/********************全局函数声明*********************/
int chgLocBanned(int, int, int);//针对第datap项banned，在第i行第j列填k，改变该改变的占领情况。
int chgNumBanned(int, int, int);//针对第datap项banned，在第order码线的首（0）尾（1）设定num=k，改变该改变的禁止情况。
int chgBannedZero();//针对第datap项banned，刷新填的数字为0时显示出的这一个格子的可能性个数（耗时不会多于回溯）
int outputData();//压栈时顺便输出
int upData();//压栈
int upBanned();//压栈
int recover();//弹栈
int publiclib();//初始化全局变量


class commander
{
public:
	commander(int);
protected:
	int orderPath[90];//指令栈，十位表示unit的类别，个位表示unit编号(1行2列3九宫)，指调用这个对象的fill
	int orderp;//栈顶
	int upOrderPath();//压栈
	int recoverOrderPath();//弹栈
	int seekBanned();//找一个状态数最少的unit，返回其order码。
	int findSolution();//主要操作
};

class units
{
public:
	units();
protected:
	int choicePath[10];//选择栈，坐标为第几个元素，值为该元素的值
	int banned[10];//用过的数，1为用过，0为没用过
	int choicep;//栈顶
	int upChoicePath();//压栈
	int recoverChoicePath();//弹栈

};

class lines : public units
{
public:
	lines(int);//order码
	int fill();//填充，递归调用
private:
	int headNum, endNum;//从线的首部和尾部看的楼数
};

class squares : public units
{
public:
	squares(int);//第几个九宫格
	int fill();//填充，递归调用
};
