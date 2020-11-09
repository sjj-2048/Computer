#pragma once
#include<iostream>
using namespace std;
#include<string>

//创建职工类
class Worker
{
public:
	//显示个人信息
	virtual void Showinfo() = 0;
	//显示岗位名称
	virtual string Getgangwei() = 0;

	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_GangweiId;//所在部门编号
};