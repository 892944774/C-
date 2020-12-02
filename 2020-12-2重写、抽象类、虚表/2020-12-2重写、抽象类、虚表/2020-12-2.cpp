#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void Buyticket()
	{
		cout << "全价票" << endl;
	}
};

class Derived : public Person
{
public:
	virtual void Buyticket()
	{
		cout << "半价票" << endl;
	}
};

//在编译器编译阶段，编译器无法知道调用那个类的对象
//只有在程序运行阶段才会知道pb指向的是哪个类的对象
void TestVirtual(Person * pb)
{
	pb->Buyticket();//call Base::BuyTicket()
}

int main()
{
	Person p;
	Derived d;
	TestVirtual(&p);
	TestVirtual(&d);
	return 0;
}
#endif

#if 0
class A
{
public:
	A(int a)
		: _a(a)
	{}

	virtual ~A()
	{
		cout << "~A()" << endl;
	}
protected:
	int _a;
};

class B : public A
{
public:
	B(int a,int b)
		: A(a)
		, _b(b)
	{
		_p = new int[10];
	}

private:
	~B()
	{
		delete[] _p;
	}
protected:
	int _b;
	int* _p;
};

int main()
{
	A* pa = new B(1, 2);

	delete pa;
	pa = nullptr;
	return 0;
}
#endif

#if 0
//override :C++11 中新增加的关键字，让编译器编译阶段检测用户是否将基类虚函数重写成功
class A
{
public:
	virtual void Test1()
	{
		cout << "A::Test()" << endl;
	}

	virtual void Test2()
	{
		cout << "A::Test()" << endl;
	}
};

class B : public A
{
public:
	virtual void Test1()
	{
		cout << "B::Test1()" << endl;
	}

	virtual void Test2()
	{
		cout << "B::Test2()" << endl;
	}

	/*virtual void Test3() override
	{
		cout << "B::Test()" << endl;
	}*/
};

void Test(A& pb)
{
	pb.Test1();
	pb.Test2();
}

int main()
{
	A a;
	B b;
	Test(a);
	Test(b);
	return 0;
}
#endif 

//static用法

//static修饰的类对象必须在类外进行初始化
#if 0
class Test
{
public:
	static int count;
};

int Test::count = 1;

int main()
{
	Test t;
	cout << t.count << endl;
	return 0;
}
#endif

//所有对象共享一个static类成员
#if 0
class Test
{
public:
	static int count;
};

int Test::count = 1;

int main()
{
	Test t1;
	Test t2;

	t1.count = 10;
	//t1对象将count的值修改后
	//t2再去访问的时候，值也就改变了，也就是说static修饰的成员变量是公用一块内存空间的
	cout << t2.count << endl;
	return 0;
}
#endif

//不能访问非static的类成员，只能访问 static修饰的类成员。
#if 0
class Test
{
public:
	static int fun()
	{
		return num;
	}

	static int count;
	int num = 1;
};

int Test::count = 1;

int main()
{
	Test t1;
	t1.fun();//error，fun函数return的是非static类成员 如果return count就正确
	return 0;
}
#endif 

#if 0
class A
{
public:
	static A* GetIntrance(int a)
	{
		return new A(a);
	}

	static void Destroy(A* pa)
	{
		delete pa;
	}

private:
	A(int a)
		: _a(a)
	{}
protected:
	int _a;
};

int main()
{
	A* pa = A::GetIntrance(1);
	A::Destroy(pa);
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual Base* f2()
	{
		cout << "Base::f2()" << endl;
		return this;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}

	void f4()
	{
		cout << "Base::f4()" << endl;
	}

	void f5()
	{
		cout << "Base::f5()" << endl;
	}

	virtual int f6()
	{
		cout << "Base::f6()" << endl;
		return 0;
	}

	int f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}
};

class Derived : public Base
{
public:
	///////////////////////////////
	// 重写
	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	//协变
	//基类虚函数返回基类的指针或者是引用，子类虚函数返回子类的指针或者引用
	virtual Derived* f2()
	{
		cout << "Derived::f2()" << endl;
		return this;
	}

	//////////////////////////////////////////////
	// 同名隐藏
	virtual void f3(int)
	{
		cout << "Derived::f3(int)" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	char f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}

	///////////////////////////////////////
	// 编译失败：因为没有构成协变
	//virtual char f6()
	//{
	//	cout << "Derived::f6()" << endl;
	//	return 0;
	//}
};
#endif

#include <windows.h>
#if 0
class WashRoom
{
public:
	void ManWC()
	{
		cout << "男厕" << endl;
	}

	void WomanWC()
	{
		cout << "女厕" << endl;
	}
};

//抽象类---包含纯虚函数的类就是抽象类
class Person
{
public:
	//纯虚函数
	virtual void GoTOWC(Person& wc) = 0;
};

// 抽象类是一定要被继承的
// 子类继承一个抽象类之后，如果没有重写基类的纯虚函数，则子类也是抽象类
class Man : public Person
{
public:
	virtual void GoTOWC(WashRoom& wc)
	{
		wc.ManWC();
	}
};

class Woman : public Person
{
public:
	virtual void GoTOWC(WashRoom& wc)
	{
		wc.WomanWC();
	}
};

void TestWC()
{
	Person* p = nullptr;
	WashRoom wr;
	for (size_t i = 0; i < 10; i++)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}
		
		p->GoTOWC(wr);
		delete p;

		Sleep(2000);
	}
}

int main()
{
	TestWC();
	return 0;
}
#endif

class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}
	int _b;
};


class Derived :public Base
{
public:
	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}
	int _d;
};

#include <string>
typedef void(*PVF)();//函数指针

void PrintfPVF(Base& b, const string& info)
{
	PVF* pVFT = (PVF*)(*(int*)(&b));
	//pVFT[0]();//调用第一个
	while (*pVFT)
	{
		*pVFT = nullptr;
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;//8
	Base b;
	
	//PrintfPVF(b);
	PrintfPVF(b, "base virtual function table:");
	return 0;
}