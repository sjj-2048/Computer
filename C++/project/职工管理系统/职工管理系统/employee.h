#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"


//创建员工类
class Employee : public Worker
{
public:

	//构造函数
	Employee(int id, string name);
	//显示个人信息
	virtual void Showinfo();
	//显示岗位名称
	virtual string Getgangwei();

};