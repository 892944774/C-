#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

#if 0
class Building;
class GoodGay
{
public:
	GoodGay();

	void visit(); //��visit�������Է���Building��˽�г�Ա
	void visit2();//��visit2���������Է���Building��˽�г�Ա

	Building * building;
};

class Building
{
	friend void GoodGay::visit();
public:
	Building();

public:
	string SittingRoom;

private:
	string BedRoom;
};

//����ʵ�ֳ�Ա����
GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << building->SittingRoom << endl;
	cout << building->BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << building->SittingRoom << endl;
}

Building::Building()
{
	SittingRoom = "����";
	BedRoom = "����";
}

int main()
{
	GoodGay gg;
	gg.visit();
	return 0;
}
#endif

#if 0
//�Ӻ����������
class Person
{
public:
	//1.��Ա����ʵ��+����
	/*Person operator+(Person &p)
	{
		Person temp;
		temp._a = this->_a + p._a;
		temp._b = this->_b + p._b;
		return temp;
	}*/

	int _a;
	int _b;
};

Person operator+(Person &p1, Person &p2)
{
	Person temp;
	temp._a = p1._a + p2._a;
	temp._b = p1._b + p2._b;
	return temp;
}

int main()
{
	Person p1;
	p1._a = 1;
	p1._b = 2;

	Person p2;
	p2._a = 2;
	p2._b = 3;

	//��Ա�������صı��ʵ���
	//Person p3 = p1.operator+(p2);

	//ȫ�ֺ������صı���
	//Person p3 = operator(p1, p2);
	Person p3 = p1 + p2;
	cout << p3._a << " " << p3._b << endl;
	return 0;
}

class Person
{
	friend ostream& operator<<(ostream &cout, Person &p);
private:
	//���ó�Ա����ʵ�������������
	//�������ó�Ա����ʵ���������������Ϊ�޷�ʵ�֣�cout�����
	/*void operator<<(cout) == = > ���ʾ���p.operator<<(cout)��Ϊp << cout; ��ʵ����Ҫ��cout << p;��ͬ
	{}*/

	int _a;
	int _b;
};

//ֻ����ȫ�ֺ����������������
ostream& operator<<(ostream &cout, Person &p)
{
	return cout;
}

class Person
{
	friend ostream& operator<<(ostream &cout, Person p);
public:
	Person()
	{
		m_Num = 0;
	}

	//ǰ��++����
	Person& operator++()
	{
		//�Ƚ���++����
		m_Num++;
		//�ٽ�������һ������
		return *this;
	}

private:
	int m_Num;
};

ostream& operator<<(ostream &cout, Person p)
{
	cout << p.m_Num;
	return cout;
}

void test()
{
	Person p;
	cout << ++p << endl;
}

int main()
{
	test();
	return 0;
}

class Person
{
public:
	Person(int age)
	{
		_age = new int(age);
	}

	~Person()
	{
		if (_age != NULL)
		{
			delete _age;
			_age = NULL;
		}
	}

	Person& operator=(Person &p)
	{
		//���ж϶����Ƿ��ͷ����
		if (_age != NULL)
		{
			delete _age;
			_age = NULL;
		}

		//���
		_age = p._age;
		_age = new int(*p._age);

		//���ض�����
		return *this;
	}

	int * _age;
};

int main()
{
	Person p1(12);
	Person p2(22);
	Person p3(11);

	p3 = p2 = p1;
	cout << *p1._age << *p2._age << *p3._age << endl;
	return 0;
}

class Person
{
public:
	Person(int age, string name)
	{
		_age = age;
		_name = name;
	}

	bool operator==(Person &p)
	{
		if (this->_age == p._age && this->_name == p._name)
		{
			return true;
		}
		return false;
	}


	bool operator!=(Person &p)
	{
		if (this->_age == p._age && this->_name == p._name)
		{
			return false;
		}
		return true;
	}
	int _age;
	string _name;
};

int main()
{
	Person p1(12, "z");
	Person p2(12, "z");

	if (p1 != p2)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
	return 0;
}
#endif

#if 0
class Person
{
public:
	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};

int main()
{
	Person p;
	p("hello world");
	return 0;
}

class Base
{
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Derived : public Base
{
public:
	int d;
};

int main()
{
	//���������еķǾ�̬�ĳ�Ա�������ᱻ����̳���ȥ
	//������˽�г�Ա�����Ǳ��������������ˣ�����Ƿ��ʲ����ģ���ȷʵ�Ǳ��̳���
	Derived D;
	cout << sizeof(D) << endl;//16
	return 0;
}

//�̳���ͬ����Ա��ͬ����Ա�����Ĵ���ʽ
class Base
{
public:
	Base()
	{
		a = 100;
	}

	void func()
	{
		cout << "Base()" << endl;
	}
	int a;
};

class Son :public Base
{
public:
	Son()
	{
		int a = 200;
	}

	void func()
	{
		cout << "Son()" << endl;
	}
	int a;
};

int main()
{
	Son s;
	cout << s.a << endl;
	//���ͨ��������� ��Ҫ���ʸ����Ա��Ҫ���ͬ��������
	cout << s.Base::a << endl;
	 
	s.func();
	s.Base::func();
	return 0;
}

//�̳��о�̬��ͬ����Ա������ͬ����Ա�����Ĵ���ʽ
class Base
{
public:
	static int a;
};

int Base::a = 100;

class Son :public Base
{
public:
	static int a;
};

int Son::a = 200;

class Animal
{
public:
	virtual void speak()
	{
		cout << "����" << endl;
	}
};

class Cat : public Animal
{
	void speak()
	{
		cout << "Сè" << endl;
	}
};

//��ַ��󶨣��ڱ���׶ξ�ȷ���˺�����ַ
//�����Ҫ��ӡСè����ô�����ַ��Ҫ��󶨣���Ҫ�����еĽ׶ν��а�

//��̬��̬���������
//1.�м̳й�ϵ  2.������д������麯��

//��̬��̬��ʹ��
//�����ָ���������ָ������Ķ���
void DoSpeak(Animal &animal)//���������ָ��������Ķ���
{
	animal.speak();
}

int main()
{
	Cat cat;
	DoSpeak(cat);
	return 0;
}
#endif

class AbstructCalculate
{
public:
	virtual int GetResault()
	{
		return 0;
	}

	int a;
	int b;
};

class ADDCalculate : public AbstructCalculate
{
public:
	virtual int GetResault()
	{
		return a + b;
	}
};

void test()
{
	ADDCalculate AD;
	AbstructCalculate &ADD = AD;
	ADD.a = 1;
	ADD.b = 2;
	cout << ADD.GetResault() << endl;
}

int main()
{
	test();
	return 0;
}
