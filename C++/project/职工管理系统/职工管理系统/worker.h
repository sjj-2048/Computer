#pragma once
#include<iostream>
using namespace std;
#include<string>

//����ְ����
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void Showinfo() = 0;
	//��ʾ��λ����
	virtual string Getgangwei() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_GangweiId;//���ڲ��ű��
};