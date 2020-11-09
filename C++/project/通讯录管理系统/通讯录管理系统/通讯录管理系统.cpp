#include<iostream>
using namespace std;
#include<string>
#define MAX 100//�������
//��ϵ�˽ṹ��
struct Person
{
	string name;//����
	int sex;//�Ա�
	int age;//����
	string  phone;//�绰��
	string address;//��ַ
};
//ͨѶ¼�ṹ��
struct Addressbook
{
	Person personarray[MAX];//ͨѶ¼����ϵ������
	int size;//ͨѶ¼�������
};
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
void addperson(Addressbook *p)
{
	if (p->size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		cout << "����������" << endl;
		string name;
		cin >> name;
		p->personarray[p->size].name = name;
		cout << "�������Ա�1�� 2Ů" << endl;
		while (1)
		{
			int sex;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personarray[p->size].sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		cout << "����������"<< endl;
		int age;
		cin >> age;
		p->personarray[p->size].age=age;
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		 p->personarray[p->size].phone=phone;
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		p->personarray[p->size].address=address;
		cout << "������" << endl;
		p->size++;
	}
	system("pause");
	system("cls");
}
void showperson(Addressbook *p)
{
	if (p->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		cout << "����" << "\t" 
			<< "�Ա�" << "\t" 
			<< "����" << "\t" 
			<< "�绰" << "\t" 
			<< "��ַ" << "\t" << endl;
		for (int i = 0; i <= p->size; i++)
		{
			cout << p->personarray[i].name << "\t" 
				<< (p->personarray[i].sex == 1 ? "��" : "Ů") << "\t"
				<< p->personarray[i].age << "\t" 
				<< p->personarray[i].phone << "\t" 
				<< p->personarray[i].address << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(Addressbook *p)
{
	cout << "��������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < p->size; i++)
	{
		if (p->personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;

}
void deleteperson(Addressbook *p)
{
	int x = isExist(p);
	if (x == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = x; i < p->size; i++)
		{
			p->personarray[i] = p->personarray[i + 1];
		}
		p->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");

}
void searchperson(Addressbook *p)
{
	int x = isExist(p);
	if (x!=-1)
		{
			cout << p->personarray[x].name << "\t"
				<< (p->personarray[x].sex == 1 ? "��" : "Ů") << "\t"
				<< p->personarray[x].age << "\t"
				<< p->personarray[x].phone << "\t"
				<< p->personarray[x].address << "\t" << endl;
		}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(Addressbook *p)
{
	int x = isExist(p);
	if (x != -1)
	{
		cout << "��ʼ�޸�" << endl;
		cout << "����������" << endl;
		string name;
		cin >> name;
		p->personarray[x].name = name;
		cout << "�������Ա�1�� 2Ů" << endl;
		while (1)
		{
			int sex;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personarray[x].sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		cout << "����������" << endl;
		int age;
		cin >> age;
		p->personarray[x].age = age;
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		p->personarray[x].phone = phone;
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		p->personarray[x].address = address;
		cout << "�޸����" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(Addressbook *p)
{
	cout << "ȷ�ϣ�" << endl;
	cout << "1--��" << endl;
	cout << "2--��" << endl;
	int x = 0;
	cin >> x;
	if (x == 1)
	{
		p->size = 0;
		cout << "ͨѶ¼�����" << endl;
		
	}
	else
	{
		cout<<"�������˵�"<<endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	
	//����ͨѶ¼
	Addressbook ad;
	ad.size = 0;
	int select = 0;
	int x = 0;
	while (1)
	{
		//��ʾ�˵�����
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&ad);
			break;
		case 2://��ʾ��ϵ��
			showperson(&ad);
			break;
		case 3://ɾ����ϵ��
			deleteperson(&ad);
			break;
		case 4://������ϵ��
			searchperson(&ad);
			break;
		case 5://�޸���ϵ��
			modifyperson(&ad);
			break;
		case 6://�����ϵ��
			cleanperson(&ad);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
				break;
		}
	}
	
}