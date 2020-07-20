#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//旧版本中， 输入输出头文件是这个 #include <iostream.h>
//新版本中是 <iostream> + std(标准的命名空间)
//标准库中的基本内容都是在std中定义的
#include <iostream>
using namespace std;

#if 0
int main()
{
	/*cout << 10 << endl;
	cout << " " << endl;
	cout << 20 << "" << endl;*/
	int a, b;
	float c;
	char d;

	cin >> a >> b;
	cout << a << b << endl;
	cin >> c;
	cout << c << endl;
	cin >> d;  
	cout << d << endl;
	return 0;
}
#endif

//缺省参数
#if 0
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc(100);//100
	TestFunc();//10
	return 0;
}
#endif

//缺省参数分类
//1.全缺省参数：所有参数都带有默认值
//2.半缺省参数：部分参数带有默认值
//全缺省参数
#if 0 
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << a <<" "<< b << " " << c << endl;
}

//半缺省参数
void TestFunc2(int a, int b = 20, int c = 10)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc1(100);//100, 20, 30
	TestFunc1();//10, 20, 30
	TestFunc2(10);//10 20 10
	TestFunc2(10, 30);//10 30 10
	return 0;
}
#endif 
//缺省参数不能再声明和定义同时给出，因为给的默认值不一样的话，编译器不知道使用哪个
//函数声明
//void TestFunc(int a = 10)
//
//函数定义
//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}

//函数重载
#if 0 
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(10,20);
	Add(10.0, 20.0);
	Add('1', '2');
	return 0;
}

int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

//在编译器编译阶段，会对传递函数实参的类型进行推演，然后根据推演的结果选择对应类型的函数进行转化
//注意：
// 推演完成后，如果有合适的类型重载的函数则调用，否则会发生隐式类型转化--转化后有合适的类型进行调用，否则报错
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add('1', '2');//char char -->找Add(char, char)函数，没有，但是有Add(int, int),char和int类型之间可以发生隐式类型转化
	return 0;
}
#endif

//c++如何支持函数重载？

//为什么C语言不支持函数重载？
//因为c语言对函数的名字修饰规则非常简单，仅仅只是在函数名后面加了"_",假设两个函数Add(int a, int b)和Add(char a, char b),在C语言编译后函数名都是_Add()类型函数，编译自然会失败。
int main()
{

	return 0;
}