#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class A
{
public:
	virtual void func(int val = 1)
	{
		cout << "A->" << val << endl;
	}
	virtual void test()
	{
		func();
	}
};
//A的虚表
//A::func(int val = 1)
//A::test()

class B : public A
{
public:
	void func(int val = 0)
	{
		cout << "B->" << val << endl;
	}
};
//B的虚表
//B::func(int val = 0)
//A::test()

int main()
{
	B*p = new B;
	p->test();
	delete p;
	return 0;
}
#endif

#include "BSTtree.hpp"
int main()
{
	Test();
	return 0;
}

