#include<iostream>
using namespace std;
#include<string>
#define MAX 100//最大人数
//联系人结构体
struct Person
{
	string name;//姓名
	int sex;//性别
	int age;//年龄
	string  phone;//电话号
	string address;//地址
};
//通讯录结构体
struct Addressbook
{
	Person personarray[MAX];//通讯录中联系人数组
	int size;//通讯录最大容量
};
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
void addperson(Addressbook *p)
{
	if (p->size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		p->personarray[p->size].name = name;
		cout << "请输入性别：1男 2女" << endl;
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
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄"<< endl;
		int age;
		cin >> age;
		p->personarray[p->size].age=age;
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		 p->personarray[p->size].phone=phone;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		p->personarray[p->size].address=address;
		cout << "添加完成" << endl;
		p->size++;
	}
	system("pause");
	system("cls");
}
void showperson(Addressbook *p)
{
	if (p->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "姓名" << "\t" 
			<< "性别" << "\t" 
			<< "年龄" << "\t" 
			<< "电话" << "\t" 
			<< "地址" << "\t" << endl;
		for (int i = 0; i <= p->size; i++)
		{
			cout << p->personarray[i].name << "\t" 
				<< (p->personarray[i].sex == 1 ? "男" : "女") << "\t"
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
	cout << "请输入联系人的姓名" << endl;
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
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = x; i < p->size; i++)
		{
			p->personarray[i] = p->personarray[i + 1];
		}
		p->size--;
		cout << "删除成功" << endl;
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
				<< (p->personarray[x].sex == 1 ? "男" : "女") << "\t"
				<< p->personarray[x].age << "\t"
				<< p->personarray[x].phone << "\t"
				<< p->personarray[x].address << "\t" << endl;
		}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(Addressbook *p)
{
	int x = isExist(p);
	if (x != -1)
	{
		cout << "开始修改" << endl;
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		p->personarray[x].name = name;
		cout << "请输入性别：1男 2女" << endl;
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
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		p->personarray[x].age = age;
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		p->personarray[x].phone = phone;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		p->personarray[x].address = address;
		cout << "修改完成" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(Addressbook *p)
{
	cout << "确认？" << endl;
	cout << "1--是" << endl;
	cout << "2--否" << endl;
	int x = 0;
	cin >> x;
	if (x == 1)
	{
		p->size = 0;
		cout << "通讯录已清空" << endl;
		
	}
	else
	{
		cout<<"返回主菜单"<<endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	
	//创建通讯录
	Addressbook ad;
	ad.size = 0;
	int select = 0;
	int x = 0;
	while (1)
	{
		//显示菜单界面
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addperson(&ad);
			break;
		case 2://显示联系人
			showperson(&ad);
			break;
		case 3://删除联系人
			deleteperson(&ad);
			break;
		case 4://查找联系人
			searchperson(&ad);
			break;
		case 5://修改联系人
			modifyperson(&ad);
			break;
		case 6://清空联系人
			cleanperson(&ad);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
				break;
		}
	}
	
}