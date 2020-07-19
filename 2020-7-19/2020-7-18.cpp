#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#if 0
//命名空间的定义
//N1是一个命名空间
//命名空间：实际就是一个带有名字的作用域
namespace N1
{
	int a = 10;
	int ADD(int left, int right)
	{
		return left + right;
	}
}

//命名空间之间可以嵌套
namespace N2
{
	int a = 50;
	int Mul(int left, int right)
	{
		return left + right;
	}

	namespace N3
	{
		int a = 30;
		int Sub(int left , int right)
		{
			return left + right;
		}
	}
}

//::作用域运算符
int a = 20;

int main()
{
	int a = 10;
	printf("%d\n", a);//函数体的a
	printf("%d\n", ::a);//访问的是全局作用域中的a
	printf("%d\n", N1::a);//访问N1中命名空间中的a

	N1::ADD(10,90);
	printf("%d\n", N2::N3::a);
	return 0;
}
#endif

#if 0
//在C++中，一个工程中可以出现相同的命名空间,编译器最终将相同命空间的内容合并到一块
namespace N
{
	int a = 10;
	int ADD(int left, int right)
	{
		return left + right;
	}
}

namespace N
{
	int b = 20;
	int Sub(int left, int right)
	{
		return left + right;
	}
}

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::b);
	return 0;
}
#endif 

//命名空间的使用
//1 直接在成员前增加 N::
//2 using N::a ,相当于将a当成全局变量使用
//3 using namespace N;相当于将N命名空间中的所有成员当成当前文件中的全局变量使用
namespace N
{
	int a = 10;
	int ADD(int left, int right)
	{
		return left + right;
	}
}

//相当于将a当成全局变量
//注意当前全局作用域不能有a,否则会产生冲突
//using N::a;
using namespace N;

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	printf("%d\n", a);
	ADD(10, 20);
	return 0;
}
