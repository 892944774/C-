#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//#include <string>
//#include <fstream>

#if 0
class Base
{
public:
	//���麯��
	//ֻҪ��һ�����麯�����ǳ�����
	//�������ص㣺1 �޷�ʵ�������� 2 ����������������д�����еĴ��麯��������Ҳ�ǳ�����
	virtual void func() = 0;
};

class Son : public Base
{
public:
	virtual void func()
	{
		cout << "����" << endl;
	}
};

int main()
{	
	Son s;
	Base & base = s;
	base.func();
	return 0;
}

class Animal
{
public:
	Animal()
	{
		cout << "���๹��" << endl;
	}

	//���������������Խ�������ָ���ͷŲ��ɾ�����Ķ����ж����п�������������
	/*virtual ~Animal()
	{
		cout << "��������" << endl;
	}*/

	virtual ~Animal() = 0;
	virtual void Speak() = 0;

};

Animal::~Animal()
{
	cout << "��������" << endl;
}

class Cat : public Animal 
{
public:
	Cat(string name)
	{
		cout << "Cat�Ĺ��캯��" << endl;
		_name = new string(name);
	}

	virtual void Speak()
	{
		cout << *_name << ":Сè" << endl;
	}

	~Cat()
	{
		if (_name != NULL)
		{
			cout << "Cat����������" << endl;
			delete _name;
			_name = NULL;
		}
	}
	string * _name;
};

void test()
{
	Animal * ptr = new Cat("����");
	ptr->Speak();
	//�����ָ����������ʱ�򲻻����������������룬��������������ж������ٳ������ڴ�û���ͷ�
	delete ptr;
}

int main()
{
	test();
	return 0;
}

int main()
{
	//�ı��ļ�д
	/*ofstream osf;
	osf.open("text.txt", ios::out);
	osf << "����";
	osf.close();*/

	//������д�ļ�
	ofstream osf;
	osf.open("text.txt", ios::out | ios::binary);
	
	char buf[1024] = {"��ɭ"};
	osf.write((const char*)&buf, sizeof(buf)-1);
	osf.close();
	return 0;
}
#endif