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

	void visit(); //让visit函数可以访问Building中私有成员
	void visit2();//让visit2函数不可以访问Building中私有成员

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

//类外实现成员函数
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
	SittingRoom = "客厅";
	BedRoom = "卧室";
}

int main()
{
	GoodGay gg;
	gg.visit();
	return 0;
}
#endif

#if 0
//加号运算符重载
class Person
{
public:
	//1.成员函数实现+重载
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

	//成员函数重载的本质调用
	//Person p3 = p1.operator+(p2);

	//全局函数重载的本质
	//Person p3 = operator(p1, p2);
	Person p3 = p1 + p2;
	cout << p3._a << " " << p3._b << endl;
	return 0;
}

class Person
{
	friend ostream& operator<<(ostream &cout, Person &p);
private:
	//利用成员函数实现左移运算符，
	//不会利用成员函数实现左移运算符，因为无法实现，cout在左侧
	/*void operator<<(cout) == = > 本质就是p.operator<<(cout)简化为p << cout; 与实际想要的cout << p;不同
	{}*/

	int _a;
	int _b;
};

//只能用全局函数重载左移运算符
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

	//前置++重载
	Person& operator++()
	{
		//先进行++运算
		m_Num++;
		//再将自身做一个返回
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
		//先判断堆区是否释放完毕
		if (_age != NULL)
		{
			delete _age;
			_age = NULL;
		}

		//深拷贝
		_age = p._age;
		_age = new int(*p._age);

		//返回对象本身
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
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	return 0;
}
#endif

#if 0
class Person
{
public:
	//重载函数调用运算符
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
	//父类中所有的非静态的成员函数都会被子类继承下去
	//父类中私有成员属性是被编译器给隐蔽了，因此是访问不到的，但确实是被继承了
	Derived D;
	cout << sizeof(D) << endl;//16
	return 0;
}

//继承中同名成员和同名成员函数的处理方式
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
	//如果通过子类对象 需要访问父类成员需要添加同名作用域
	cout << s.Base::a << endl;
	 
	s.func();
	s.Base::func();
	return 0;
}

//继承中静态的同名成员变量和同名成员函数的处理方式
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
		cout << "动物" << endl;
	}
};

class Cat : public Animal
{
	void speak()
	{
		cout << "小猫" << endl;
	}
};

//地址早绑定，在编译阶段就确定了函数地址
//如果想要打印小猫，那么这个地址就要晚绑定，需要在运行的阶段进行绑定

//动态多态满足的条件
//1.有继承关系  2.子类重写父类的虚函数

//动态多态的使用
//父类的指针或者引用指向子类的对象
void DoSpeak(Animal &animal)//父类的引用指向了子类的对象
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
