#include"employee.h"

Employee::Employee(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	//this->m_GangweiId = gangweiid;
}
void Employee::Showinfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->Getgangwei()
		<<"\t��λְ����ɾ�����������"<< endl;
}
string Employee::Getgangwei()
{
	return string("Ա��");
}

