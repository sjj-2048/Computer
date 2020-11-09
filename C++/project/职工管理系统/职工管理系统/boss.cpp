#include"boss.h"

Boss::Boss(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	//this->m_GangweiId = gangweiid;
}
void Boss::Showinfo()
{
	cout << "职工编号：" << this->m_Id
		<< " \t职工姓名：" << this->m_Name
		<< " \t岗位：" << this->Getgangwei()
		<< " \t岗位职责：管理公司所有事务" << endl;
}
string Boss::Getgangwei()
{
	return string("老板");
}