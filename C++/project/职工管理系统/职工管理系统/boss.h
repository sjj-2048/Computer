#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//创建老板类
class Boss :public Worker
{
public:
	Boss(int id, string name);
	//重写显示个人信息
	virtual void Showinfo();
	//重写显示岗位名称
	virtual string Getgangwei();
};