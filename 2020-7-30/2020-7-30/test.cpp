#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>

#if 0
void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int* pa)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	int a = 0;
	int* pa = &a;

	int* pb = NULL;

	TestFunc(0);//传值为0，应该调用的是第一个函数
	TestFunc(NULL);//传递的是一个指针类型，应该调用的是第二个函数,但该位置实际调用的是整形类型的func函数
				   //实际上空指针的定义是一个宏#define NULL 0
				   //因此实际的调用过程是TestFunc(NULL)-->预处理阶段 ——>TestFunc(0);
				   //因此使用nullptr表示指针为空
	return 0;
}
#endif

#if 0
//Studet可以看成是一个学生群体类型，因此可以用该类型定义变量
struct Student
{
	char _name[20];
	char _gender[3];
	char _school[20];
	int  _age;

	void SetStudentInfo(char name[], char gender[], char school[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_school, school);
		_age = age;
	}

	void PrintfStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _school << "-" << _age << endl;
	}
};

int main()
{
	Student s1, s2, s3;//由类定义出来s1, s2, s3是学生对象
	s1.SetStudentInfo("张三", "男", "邮电", 22);
	s2.SetStudentInfo("李四", "男", "北大", 32);
	s3.SetStudentInfo("王五", "女", "清华", 23);

	s1.PrintfStudentInfo();
	s2.PrintfStudentInfo();
	s3.PrintfStudentInfo();
	return 0;
}
#endif

#if 0
class Student
{
private:
	//属性：用来描述学生的基本信息，一般不会让外人知道
	char _name[20];
	char _gender[3];
	char _school[20];
	int  _age;

public:
	void SetStudentInfo(char name[], char gender[], char school[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_school, school);
		_age = age;
	}

	void PrintfStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _school << "-" << _age << endl;
	}
};

int main()
{
	Student s1, s2, s3;//由类定义出来s1, s2, s3是学生对象
	s1.SetStudentInfo("张三", "男", "邮电", 22);
	s2.SetStudentInfo("李四", "男", "北大", 32);
	s3.SetStudentInfo("王五", "女", "清华", 23);

	s1.PrintfStudentInfo();
	s2.PrintfStudentInfo();
	s3.PrintfStudentInfo();
	return 0;
}
#endif

#if 0
//类中的成员变量，只能在成员函数中使用，类中的成员变量也是在类中的全局变量
class Test
{
public:
	void SetTest(int a)
	{
		_a = a;
	}

	void Printtest()
	{
		cout << _a << endl;
	}

private:
	int _a;//该成员变量可以在两个函数中都能是使用，
	//因此成员变量就可以当成该类成员函数中的全局变量
};

int main()
{
	Test s;//s就是类实例化的结果
	return 0;
}
#endif

#if 0
class Student
{
public:
	void SetStudentInfo(char name[], char gender[], char school[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_school, school);
		_age = age;
	}

	void PrintfStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _school << "-" << _age << endl;
	}

private:
	//属性：用来描述学生的基本信息，一般不会让外人知道
	char _name[20];
	char _gender[3];
	char _school[20];
	int  _age;
};

int main()
{
	Student s;//由类定义出来s是学生对象
	
	//要检测Student类对象有多大，至少知道对象中包含了哪些成员
	//s. 的方式
	return 0;
}
#endif

#if 0
class A1 {
public:
	void f1() {}
public:
	int _a;
	char _b;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};

// 类中什么都没有---空类
class A3
{};

int main()
{
	cout << sizeof(A1) << endl;//8
	cout << sizeof(A2) << endl;//1
	cout << sizeof(A3) << endl;//1,因为没有成员变量，理论上类的大小结果是0，但实际是1

	cout << offsetof(A1, _b) << endl;//求_相对于起始位置的偏移量
	return 0;
}
#endif

//每个类成员函数都有一个默认的参数，该参数时时刻刻指向调用该成员函数的对象，将该参数成为this指针
//this指针是编译器在编译期间自动加上的，用户不需要添加，也不需要传递
class Student
{
public:
	void SetStudentInfo(/*Student* const this, */char name[], char gender[], int age)
	{
		cout << this << endl;
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintfStudentInfo(/*Student* const this*/)
	{
		cout << /*this->*/_name << "-" << /*this->*/_gender << "-" << /*this->*/_age << endl;
	}

	void TestFunc(...) //表示不定参数
	{}
private:
	//属性：用来描述学生的基本信息，一般不会让外人知道
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;//由类定义出来s1, s2, s3是学生对象

	//三个学生对象调用成员函数
	cout << &s1 << endl;
	s1.SetStudentInfo("张三", "男", 22);

	cout << &s2 << endl;
	s2.SetStudentInfo("李四", "男", 32);

	cout << &s3 << endl;
	s3.SetStudentInfo("王五", "女", 23);

	//this指针的传递方式
	// 1 该参数是有编译器传递的
	// 2 一般情况该参数是通过ecx寄存器来传递的
	// 3 二班情况下是通过参数压栈的方式传递
	// 注意：一般情况下成员函数都是被this_call调用约定修饰的，即被this_call调用约定修饰的成员函数
	//      this指针是通过exc寄存器传递，被_cdecl调用约定修饰的函数。this是通过参数压栈的方式传递的
	s1.PrintfStudentInfo();
	s2.PrintfStudentInfo();
	s3.PrintfStudentInfo();
	return 0;
}

#if 0
//用c语言的方式实现上述代码
struct Student
{
	char name[20];
	char gender[3];
	int age;
};

void SetStudentInfo(Student* ps, char name[], char gender[], int age)
{
	strcpy(ps->name, name);
	strcpy(ps->gender, gender);
	ps->age = age;
}

void PrintfStudentInfo(Student* ps)
{
	printf("%s %s %d\n", ps->name, ps->gender, ps->age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "张三", "男", 23);
	SetStudentInfo(&s2, "张四", "男", 24);
	SetStudentInfo(&s3, "张五", "男", 25);

	PrintfStudentInfo(&s1);
	PrintfStudentInfo(&s2);
	PrintfStudentInfo(&s3);
	return 0;
}
#endif