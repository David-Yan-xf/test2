#pragma once
#include<iostream>
#include<fstream>
using namespace std;

/********************ȫ�ֺ�������*********************/
int chgLocBanned(int, int, int);//��Ե�datap��banned���ڵ�i�е�j����k���ı�øı��ռ�������
int chgNumBanned(int, int, int);//��Ե�datap��banned���ڵ�order���ߵ��ף�0��β��1���趨num=k���ı�øı�Ľ�ֹ�����
int chgBannedZero();//��Ե�datap��banned��ˢ���������Ϊ0ʱ��ʾ������һ�����ӵĿ����Ը�������ʱ������ڻ��ݣ�
int outputData();//ѹջʱ˳�����
int upData();//ѹջ
int upBanned();//ѹջ
int recover();//��ջ
int publiclib();//��ʼ��ȫ�ֱ���


class commander
{
public:
	commander(int);
protected:
	int orderPath[90];//ָ��ջ��ʮλ��ʾunit����𣬸�λ��ʾunit���(1��2��3�Ź�)��ָ������������fill
	int orderp;//ջ��
	int upOrderPath();//ѹջ
	int recoverOrderPath();//��ջ
	int seekBanned();//��һ��״̬�����ٵ�unit��������order�롣
	int findSolution();//��Ҫ����
};

class units
{
public:
	units();
protected:
	int choicePath[10];//ѡ��ջ������Ϊ�ڼ���Ԫ�أ�ֵΪ��Ԫ�ص�ֵ
	int banned[10];//�ù�������1Ϊ�ù���0Ϊû�ù�
	int choicep;//ջ��
	int upChoicePath();//ѹջ
	int recoverChoicePath();//��ջ

};

class lines : public units
{
public:
	lines(int);//order��
	int fill();//��䣬�ݹ����
private:
	int headNum, endNum;//���ߵ��ײ���β������¥��
};

class squares : public units
{
public:
	squares(int);//�ڼ����Ź���
	int fill();//��䣬�ݹ����
};
