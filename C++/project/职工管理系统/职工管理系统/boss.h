#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//�����ϰ���
class Boss :public Worker
{
public:
	Boss(int id, string name);
	//��д��ʾ������Ϣ
	virtual void Showinfo();
	//��д��ʾ��λ����
	virtual string Getgangwei();
};