#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//工程是C++工程，但是想要按照C语言的方式编译代码
#if 0
extern "C" int Add(int left, int right);

int main()
{
	Add(1, 2);
	return 0;
}
#endif

//类型& 引用的别名 = 引用实体;
#if 0
void TestRef()
{
	int a = 10;
	//ra就是a的别名,ra和a在底层就是公用一个实体，即公用一块内存空间
	int& ra = a;
	cout << &a << " " << &ra << endl;//0058F6A4 0058F6A4
}

void SetNULLPtr(int*& p)
{
	p = NULL;
}

void SetNULLPtr(int** p)
{
	//*p就是实参本身 
	*p = NULL;
}

int main()
{
	int a = 10;
	int* pa = &a;
	*pa = 20;

	SetNULLPtr(pa);
	SetNULLPtr(&pa);
	TestRef();
	return 0;
}
#endif

//常引用-->const类型的引用
#if 0
int main()
{
	const int a = 10;//a是不能被修改的
	const int& ra = a;//正确

	//int& ra = a;//错误
	             //如果普通类型的引用变量ra去引用a，可以修改a，否则修改ra则就会把a修改掉
	
	double d = 12.34;
	//double& rd = d;//正确
	// rd = 23.34;

	const int& rd = d;//编译器就创建了一个临时int型变量，
	               //rd就不能直接引用，而int和double类型之间可以发生隐式类型转化
	             //临时空间具有常性---不能被修改，因此必须是使用const int&来引用
	return 0;
}
#endif

#if 0 
int main()
{
	int a = 10;//在a定义之后，编译器给a开辟了一块内存空间
	int& ra = a;//ra是引用类型的变量，在定义时，编译器不会给ra开辟一块内存空间，而是和a公用一块内存空间

	cout << typeid(a).name() << endl;
	cout << typeid(ra).name() << endl;
	return 0;
}
#endif

#include <ctime>

struct A
{
	int array[10000];
};

void TestValue(A a)
{}

void TestRef(A& a)
{}

void TestPtr(A* a)
{}

void TestFunc()
{
	A a;

	//传值，在传参期间需要进行实参的一份拷贝
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
		TestValue(a);
	size_t end1 = clock();

	//引用是别名，在传参期间不需要进行拷贝
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end2 = clock();

	//传指针，在传参期间不需要进行对象的拷贝--拷贝的是对象的地址--32位平台四个字节
	size_t begin3 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end3 = clock();

	cout << "传值性能：" << end1 - begin1 << endl;//100
	cout << "传引用性能：" << end2 - begin2 << endl;//1
	cout << "传指针性能：" << end3 - begin3 << endl;//1
}

int main()
{
	TestFunc();
	return 0;
}