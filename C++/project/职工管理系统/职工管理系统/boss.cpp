#include"boss.h"

Boss::Boss(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	//this->m_GangweiId = gangweiid;
}
void Boss::Showinfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< " \tְ��������" << this->m_Name
		<< " \t��λ��" << this->Getgangwei()
		<< " \t��λְ�𣺹���˾��������" << endl;
}
string Boss::Getgangwei()
{
	return string("�ϰ�");
}