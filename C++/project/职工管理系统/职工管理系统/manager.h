#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//����������
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name);
	//��д��ʾ������Ϣ
	virtual void Showinfo();
	//��д��ʾ��λ����
	virtual string Getgangwei();
};
