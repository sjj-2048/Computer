#include"manager.h"

Manager::Manager(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	//this->m_GangweiId = gangweiid;
}
void Manager::Showinfo()
{
	cout << "职工编号：" << this->m_Id
		 << "\t职工姓名：" << this->m_Name 
		 <<"\t岗位："<<this->Getgangwei()
		 <<"\t岗位职责：完成老板交给的任务"<< endl;
}
string Manager::Getgangwei()
{
	return string("经理");
}