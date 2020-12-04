#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class B1
{
public:
	virtual void f1()
	{
		cout << "B1::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "B1::f2()" << endl;
	}

	int _b1;
};

class B2
{
public:
	virtual void f3()
	{
		cout << "B2::f3()" << endl;
	}

	virtual void f4()
	{
		cout << "B2::f4()" << endl;
	}

	int _b2;
};

class D : public B1, public B2
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "D::f2()" << endl;
	}

	virtual void f5()
	{
		cout << "D::f5()" << endl;
	}
	int _d;
};

int main()
{
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}

class A {
public:
	A(char *s)
	{
		cout << s << endl;
	}

	~A() {}
};


class B :virtual public A
{
public:
	B(char *s1, char*s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};

class C :virtual public A
{
public:
	C(char *s1, char*s2)
		:A(s1)
	{
		cout << s2 << endl;
	}
};

class D :public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4)
		:B(s1, s2)
		, C(s1, s3)
		, A(s1)
	{
		cout << s4 << endl;
	}
};

int main() {
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
#endif

#if 0
class Base1 { public: int _b1; };

class Base2 { public: int _b2; };

class Derive : public Base1, public Base2
{
public: int _d;
};

int main() {
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}
#endif

class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}

	virtual void test()
	{
		func();
	}
};

class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};

int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();

	delete p;
	return 0;
}