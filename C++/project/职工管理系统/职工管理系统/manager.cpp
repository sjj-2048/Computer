#include"manager.h"

Manager::Manager(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	//this->m_GangweiId = gangweiid;
}
void Manager::Showinfo()
{
	cout << "ְ����ţ�" << this->m_Id
		 << "\tְ��������" << this->m_Name 
		 <<"\t��λ��"<<this->Getgangwei()
		 <<"\t��λְ������ϰ彻��������"<< endl;
}
string Manager::Getgangwei()
{
	return string("����");
}