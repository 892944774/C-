#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//#include <string>
//#include <fstream>

#if 0
class Base
{
public:
	//纯虚函数
	//只要有一个纯虚函数就是抽象类
	//抽象类特点：1 无法实例化对象 2 抽象类的子类必须重写父类中的纯虚函数，否则也是抽象类
	virtual void func() = 0;
};

class Son : public Base
{
public:
	virtual void func()
	{
		cout << "子类" << endl;
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
		cout << "父类构造" << endl;
	}

	//利用虚析构，可以解决父类的指针释放不干净子类的对象中堆区中开启出来的问题
	/*virtual ~Animal()
	{
		cout << "父类析构" << endl;
	}*/

	virtual ~Animal() = 0;
	virtual void Speak() = 0;

};

Animal::~Animal()
{
	cout << "纯虚析构" << endl;
}

class Cat : public Animal 
{
public:
	Cat(string name)
	{
		cout << "Cat的构造函数" << endl;
		_name = new string(name);
	}

	virtual void Speak()
	{
		cout << *_name << ":小猫" << endl;
	}

	~Cat()
	{
		if (_name != NULL)
		{
			cout << "Cat的析构函数" << endl;
			delete _name;
			_name = NULL;
		}
	}
	string * _name;
};

void test()
{
	Animal * ptr = new Cat("阿花");
	ptr->Speak();
	//父类的指针在析构的时候不会调用子类的析构代码，导致子类中如果有堆区开辟出来的内存没被释放
	delete ptr;
}

int main()
{
	test();
	return 0;
}

int main()
{
	//文本文件写
	/*ofstream osf;
	osf.open("text.txt", ios::out);
	osf << "周内";
	osf.close();*/

	//二进制写文件
	ofstream osf;
	osf.open("text.txt", ios::out | ios::binary);
	
	char buf[1024] = {"张森"};
	osf.write((const char*)&buf, sizeof(buf)-1);
	osf.close();
	return 0;
}
#endif