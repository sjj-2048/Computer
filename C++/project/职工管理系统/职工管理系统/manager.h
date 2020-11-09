#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//创建经理类
class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, string name);
	//重写显示个人信息
	virtual void Showinfo();
	//重写显示岗位名称
	virtual string Getgangwei();
};
