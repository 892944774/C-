#include <iostream>
using namespace std;
#include <string.h>

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

public:
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
