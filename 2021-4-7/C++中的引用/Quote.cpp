#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

#if 0
int* func1()
{
	//在堆上开启，返回的是该数据类型的指针
	int * p = new int(10);
	return p;
}

void func2()
{
	int * arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	delete[] arr;
}

int main()
{
	int * p = func1();
	cout << *p << endl;
	delete p;

	func2();
	return 0;
}
#endif

#if 0 
void test(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	test(a, b);
	cout << " a =" << a << endl;
	cout << " b =" << b << endl;
	return 0;
}
#endif

#if 0
//1.不要返回局部变量的引用
int& func()
{
	//a在栈区，程序结束后本次调用结束，返回的值为随机数
	int a = 10;
	return a;
}

//2.函数的调用可以作为左值
int& func2()
{
	//static修饰后变成了全局变量，保存在全局区，全局区的变量由系统释放
	static int a = 20;
	return a;
}

int main()
{
	int &a = func();
	cout << a << endl;
	cout << a << endl;

	int &b = func2();
	cout << b << endl;
	return 0;
}
#endif 

#if 0
int& func1(int &a)
{
	a = 20;
	return a;
}

//const修饰引用不能修改
int& func2(const int &a)
{
	a = 20;
	return a;
}

int main()
{
	int a = 10;
	//int & ref = 10;//err
	//const int &ref = 10;//假如const之后，编译器将此句话修改为int temp =10; 和 int &ref = temp; 

	int &ret = func1(a);
	cout << ret << endl;

	int &ret = func2(a);//error
	cout << ret << endl;
	return 0;
}
#endif

#if 0 
//函数重载，1.函数作用域相同 2.函数名相同  3.函数的参数列表不同，参数顺序或参数类型或参数个数不同
//注意：函数重载的返回值不能作为函数重载的条件
void func()
{
	cout << "func()" << endl;
}

void func(int a)
{
	cout << "func()?" << endl;
}

//1.引用作为重载的条件
void func1(int &a)
{
	cout << "func1(int &a)" << endl;
}

void func1(const int &a)
{
	cout << "func1(const int &a)" << endl;
}

//2.函数重载碰到默认参数
void func2(int a, int b = 1)
{
	cout << "func2(int a, int b = 1)" << endl;
}

void func2(int a)
{
	cout << "func2(int a)" << endl;
}

int main()
{
	//func();
	int a = 10;
	func1(a);
	func1(10);//func1(const int &a)

	func2(10,10);//"func2(int a, int b = 1)"
	func2(10);//err
	return 0;
}
#endif

#if 0
class Circule
{
public:

	double calculate(int r)
	{
		return 2 * 3.14*r;
	}

	int r;
};
int main()
{
	//实例化，通过一个类，具体创建一个对象的过程
	Circule C;
	double ret = C.calculate(10);
	cout << ret << endl;
	return 0;
}
#endif

//访问权限
//公共权限--类内可以访问，类外也可以访问
//保护权限--类内可以访问，类外不可以访问   子类可以访问父类的内容
//私有权限--类内可以访问，类外不可以访问   子类不能访问父类的内容
#if 0
class Person
{
public:
	string _name;
	void func()
	{
		car = "车";
		password = "1234";
	}

protected:
	string car;
private:
	string password;
};

int main()
{
	Person p1;
	p1.func();
	return 0;
}
#endif

#if 0
//struct默认的访问权限是共有的
struct S
{
	int a;
};

//class默认的访问权限是私有的
class C
{
	int b;
};

int main()
{
	S s;
	C c;
	s.a = 1;
	c.b = 1;//err
	return 0;
}
#endif 

#if 0
class Person
{
public:
	int Getage(int a)
	{
		age = a;
		return age;
	}

	string Getname(string name)
	{
		_name = name;
		return _name;
	}

	string GetLover(string lover)
	{
		_lover = lover;
		return _lover;
	}

private:
	int age;
	string _name;
	string _lover;
};

int main()
{
	Person people;

	cout << people.Getage(10) << endl;
	cout << people.GetLover("zhang") << endl;
	cout << people.Getname("zzzz") << endl;
	return 0;
}
#endif

#if 0
class Person
{
public:
	//构造函数完成对象的初始化
	//构造函数无返回值，不需要写void
	//构造函数的函数名与类名相同
	//构造函数可以有参数，可以发生重载
	//创建对象的时候，系统会自动调用构造函数
	Person()
	{
		cout << "Person类的构造函数" << endl;
	}

	//析构函数完成对象的清理
	//析构函数无返回值，不需要写void
	//函数名和类名相同
	//析构函数不可以有参数，对象在销毁前， 会自动调用析构函数
	~Person()
	{
		cout << "Person类的析构函数" << endl;
	}
};

int main()
{
	Person p;
	return 0;
}
#endif

#if 0
//构造函数按照：分为有参构造和无参构造
//按照类型分为：普通构造函数和拷贝构造函数
class Person
{
public:
	//无参构造
	Person()
	{
		cout << "Person()构造函数" << endl;
	}

	//有参构造
	Person(int a)
	{
		age = a;
		cout << "Person()有参构造" << endl;
	}

	//拷贝构造
	Person(const Person &p)
	{
		age = p.age;
		cout << "Person()拷贝" << endl;
	}

	~Person()
	{
		cout << "析构" << endl;
	}

	int age;
};

//值传递的方式给函数传参
void DoWork(Person p)
{
	int age = 0;
	age = p.age;
}

void test()
{
	Person p;
	DoWork(p);
}

int main()
{
	//不要写成	Person p();此时编译器会将这条语句当成是函数的声明

	//Person p;//调用默认构造函数
	//Person p1(10);//有参构造函数
	//Person p2(p1);//拷贝构造函数
	//cout << p1.age << endl;

	test();
	return 0;
}
#endif

#if 0
class Person
{
public:
	Person()
	{
		cout << "Person的构造函数" << endl;
	}

	Person(int age, int height)
	{
		_age = age;
		_height = new int(height);//堆上开辟，程序员手动开辟，也需要程序员手动释放
		cout << "Person的有参构造函数" << endl;
	}

	Person(const Person &p)
	{
		_age = p._age;
		//_height = p._height;//浅拷贝的操作

		//深拷贝
		_height = new int(*p._height);
	}

	~Person()
	{
		//将堆区开辟的程序释放
		if (_height != NULL)
		{
			delete _height;
			_height = NULL;
		}
		cout << "Person的析构函数" << endl;
	}
	
	int _age;
	int *_height;
};

void test1()
{
	Person p1(12, 160);
	cout << p1._age <<  *p1._height << endl;

	Person p2(p1);
	cout << p2._age <<  *p2._height << endl;
}

int main()
{
	test1();
	return 0;
}
#endif

#if 0
class Phone
{
public:
	Phone(string pName)
	{
		cout << "Phone的构造函数" << endl;
		_pName = pName;
	}

	~Phone()
	{
		cout << "Phone的析构函数" << endl;
	}
	string _pName;
};

class Person
{
public:
	//Phone _Phone = phone; 隐式转化法
	Person(string name, string phone)
		: _Name(name)
		, _Phone(phone)
	{
		cout << "Person的构造函数" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数" << endl;
	}
	string _Name;
	Phone _Phone;
};

//构造的时候，先构造类中其他的对象，再构造自己本身，析构先析构自己，再析构其他对象
int main()
{
	Person p("张森", "华为");
	return 0;
}
#endif

#if 0
//静态成员变量
class Person
{
public:
	//1. 所有的对象共享一份数据
	//2. 编译阶段就分配内存
	//3. 类内声明，类外初始化操作
	static int a;
private:
	int b;
};

int Person::a = 100;
//int Person::b = 200;

int main()
{
	//1.通过对象进行访问
	Person p;
	cout << p.a << endl;

	//2. 通过类名进行访问
	cout << Person::a << endl;
	return 0;
}
#endif

#if 0
class Person
{
public:
	//静态成员函数
	static void func()
	{
		_a = 100;//静态成员函数  可以访问静态成员变量
		_b = 200;//静态成员函数  不可以访问静态成员变量
		cout << "static void func()调用" << endl;
	}

	static int _a;
	int _b;
};

int Person::_a = 0;

int main()
{
	//静态成员函数两种访问方式
	//1 通过对象直接访问
	Person p;
    p.func();

	//2 类作用域直接访问
	Person::func();
	return 0;
}
#endif

#if 0
//成员变量和成员函数是分开存储的
class Person
{
	int _a;//非静态的成员变量，属于类的对象

	static int _b;//静态的成员变量，不属于类的对象

	void func()//非静态的成员函数，不属于类的对象
	{};
};

int Person::_b = 0;

int main()
{
	Person p;
	cout << sizeof(p) << endl;//4
	return 0;
}
#endif

#if 0
class Person
{
public:
	Person(int age)
	{
		//this指针指向 被调用成员函数 所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person &p)
	{
		this->age += p.age;

		//this指向p2的指针，而*this指向的就是p2
		return *this;
	}
	int age;
};

int main()
{
	Person p1(10);//p1调用了Person类的构造函数，this指针就指向对象p1
	//cout << "p1的年龄：" << p1.age << endl;

	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄：" << p2.age << endl;

	return 0;
}
#endif

#if 0
class Person
{
public:
	void showClassname()
	{
		cout << "showClassname" << endl;
	}

	void showPersonAge()
	{
		cout << "showPersonAge" << _age << endl;
	}

	//正解
	/*void showPersonAge()
	{
		if (this->NLL)
			return NULL;
		cout << "showPersonAge" << _age << endl;
	}*/
	int _age;
};

int main()
{
	Person * p1 = NULL;
	//p1->showClassname();//ok
	p1->showPersonAge();//err 因为this指针指向为空，_age在编译时编译器会写成this->_age;
	return 0;
}
#endif

#if 0
//常函数
class Person
{
public:
	//this指针的本质  是指针常量 指针的指向不能被修改
	//const Person * const this;
	//在成员函数后面加上const，修饰的this指针的指向不能被修改，前面的const修饰的是this指向的值不能被修改
	void showPerson()const
	{
		//this->_age = 10;//不能修改
		//this = NULL;//不能修改
		this->_a = 122;
	}

	int _age;
	mutable int _a;//特殊变量，即使在常函数中，也可以修改其值，加入关键字mutable
};

int main()
{
	Person p;
	p.showPerson();

	//常对象
	const Person p1;
	//p1._age = 1;//常对象不能修改非静态成员变量
	p1._a = 100;//常对象可以修改mutable修饰的成员变量

	//常对象只能调用常函数，不能调用普通的成员函数，因为普通的成员函数会修改属性
	return 0;
}
#endif

class Building
{
	//goodboy是Building的好朋友，可以访问Building的私有成员
	friend void goodboy(Building &ba);
public:
	Building()
	{
		SittingRoom = "客厅";
		BedRoom = "卧室";
	}

	string SittingRoom;

private:
	string BedRoom; 
	
};

//全局函数
void goodboy(Building &ba)
{
	cout << ba.SittingRoom << endl;
	cout << ba.BedRoom << endl;
}

int main()
{
	Building building;
	goodboy(building);
	return 0;
}