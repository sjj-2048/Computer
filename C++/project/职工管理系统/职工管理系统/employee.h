#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"


//����Ա����
class Employee : public Worker
{
public:

	//���캯��
	Employee(int id, string name);
	//��ʾ������Ϣ
	virtual void Showinfo();
	//��ʾ��λ����
	virtual string Getgangwei();

};