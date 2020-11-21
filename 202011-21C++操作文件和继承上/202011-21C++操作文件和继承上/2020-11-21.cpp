#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0 
int main()
{
	FILE* pf = fopen("1.txt", "wb");
	if (NULL == pf)
	{
		exit(0);
	}

	//二进制格式来写文件
	int a = 12345678;
	fwrite(&a, sizeof(a), 1, pf);
	char ch = -1;
	fwrite(&ch, 1, 1, pf);

	char sz[32] = {0};
	_itoa(a, sz, 10);//将数字转化为字符,10进制
	fwrite(sz, 1, strlen(sz), pf);
	fclose(pf);

	return 0;
}
#endif

#if 0 
int main()
{
	int a = 12345678;
	char sz[32] = {0};
	_itoa(a, sz, 10);

	memset(sz, 0, 32);//将设置后的空间全都设置为0
	sprintf(sz, "%d", a);
	return 0;
}
#endif

#include <sstream>
#if 0
int main()
{
	int a = 12345678;
	stringstream ss;
	ss << a;

	string str;
	ss >> str;
	string ret = ss.str();

	ss.clear();
	ss.str("");
	double d = 12.34;
	ss << d;
	//ss >> str;

	ret = ss.str();
	cout << ret << endl;
	return 0;
}
#endif

#if 0
int main()
{
	stringstream ss;
	ss << "hello";
	ss << "     ";
	ss << "world!!!";

	string s;
	s = ss.str();
	cout << s << endl;
	return 0;
}
#endif

#include <string>

//  基类/父类
#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Eat" << endl;
	}

	void Sleep()
	{
		cout << "Sleep" << endl;
	}
private:
	string _name;
	string _gender;
	int _age;
};

//派生类/子类
class Student : public Person
{
public:
	void Study()
	{
		cout << "study" << endl;
	}
private:
	int _stuid;
};

int main()
{
	Student s;
	s.Eat();//可以
	s.Sleep();//可以

	cout << sizeof(Student) << endl;//64
	return 0;
}
#endif

#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Eat" << endl;
	}

	void Sleep()
	{
		cout << "Sleep" << endl;
	}
private:
	//既不能在类外直接使用，也不能在子类中直接使用
	string _name;
	string _gender;

protected:
	//不能再类外直接使用，可以在子类中直接使用
	int _age;
};

//派生类/子类
class Student : public Person
{
public:
	void Study()
	{
		//基类中protected成员在子类中可以直接使用
		//权限：protected
		_age = 19;

		//基类中private修饰的成员在子类中不可见（不能直接使用）
		//_name = "zhangsen";//err
		cout << "study" << endl;
	}
private:
	int _stuid;
};

//创建一个子类的子类，验证基类中protected可以在子类中直接使用
class A : public Student
{
public:
	int Test()
	{
		_age = 10;
		return _age;
	}
};

int main()
{
	A a;
	a.Test();
	a.Eat();
	int ret = a.Test();
	cout << ret << endl;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : protected Base
{
public:
	void test()
	{
		//基类中public修饰的子类中的权限变成protected
		_pub = 10;

		//基类中protected修饰的子类中的权限没变
		_pro = 10;

		//基类中private修饰的子类中的权限不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 2;
		_pro = 3;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}
#endif

//赋值兼容规则：前提必须是public继承方式
//1. 子类对象可以给基类对象进行赋值，反过来不行
//2. 基类对象指着或者引用可以直接指向子类的对象
//3. 子类的指针不能直接指向基类的对象

//如果是public的继承方式。
//子类和基类的关系：is-a(是一个)可以将子类对象看成是一个基类对象
//对象模型：对象中成员在内存中的分布形式
#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Eat" << endl;
	}

	void Sleep()
	{
		cout << "Sleep" << endl;
	}

	string _name;
	string _gender;
private:
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "study" << endl;
	}

	int _stuid;
};

int main()
{
	//1. 子类对象可以给基类对象进行赋值，反过来不行
	Person p;
	Student s;

	p = s;
	//s = p;//err

	//2. 基类指针或者引用可以直接指向子类的对象
	Person* pp = &s;
	Person& rp = s;

	//3. 子类的指针不能直接指向基类的对象，但是强转可以--不安全
	Student* ps = (Student*)&p;
	ps->_name = "zhangsen";
	ps->_gender = "男";
	ps->_stuid = 100;//因为基类中没有这个成员变量，所以解引用后赋值不安全
	return 0;
<<<<<<< HEAD


=======
>>>>>>> 366348505fad10581a9f7775379c94dd164be008
}
#endif
