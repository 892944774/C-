#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class B
{
public:
	int _b;
};

//虚拟继承
class D : virtual public B
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	D d;
	C1 c;
	cout << sizeof(D) << endl;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;

	C1& c1 = c;
	c._c1 = 5;
	c._b = 6;

	C2& c2 = d;
	c2._c2 = 3;
	c2._b = 6;
	return 0;
}
#endif

#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半票" << endl;
	}
protected:
	int _StuId;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免票" << endl;
	}
protected:
	int _StuId;
};

void TestBuyTicket(Person* p)
{
	p->BuyTicket();
}

int main()
{
	Person p;
	Student stu;
	Soldier sol;

	TestBuyTicket(&p);
	TestBuyTicket(&stu);
	TestBuyTicket(&sol);
	return 0;
}
#endif

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	Derived()
	{
		pb = new int[10];
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		if (pb)
		{
			delete[] pb;
			pb = nullptr;
			cout << "~Derived()" << endl;
		}
	}
	int* pb;
};

int main()
{
	Base* pb = new Derived;//基类对象的指针指向子类对象
	delete pb;
	return 0;
}
