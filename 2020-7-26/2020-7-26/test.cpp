#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std; 

#if 0
void  Swap(int& left, int& right)
{
	int temp = left;
	left = right;//这里代码崩溃
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int* pb = NULL;
	*pb = 100;//对空指针解引用，代码执行期间崩溃
	//在传参时，看起来是按照值的方式传递，
	//但在编译器在编译代码时，检测到Swap的两个引用类型的参数转换为指针
	//因此：Swap(a,*pb)-->编译成：Swap(&a, pb)
	Swap(a, *pb);//但是该位置的空指针，代码在执行期间没有崩溃
	return 0;
}
#endif

//在C++中被const修饰的变量具有宏替换的功能
//宏：在预处理阶段发生替换--代码还没有编译--编译器直接替换，不会进行类型检测，所以安全性不高
//const修饰：是在编译阶段进行替换，会进行参数类型检测，安全性高
#if 0
int main()
{
	const int a = 10;
	int* pa = (int*)&a;
	*pa = 100;

	cout << *pa << endl;//100
	cout << a << endl;//10  const修饰的a在编译前已经被替换成10了
	return 0;
}
#endif

//在C++中，被inline修饰的关键字称为内联函数
//内联函数特性：在编译器编译期间，编译器会对内联函数进行展开，少了函数调用的开销，可以提高程序的运行效率
#if 0
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int sum = Add(2,3);

	//检测内联函数到底有什么展开？
	//如果没有展开，sum = Add(a,b);在该语句中调用Add函数，有call Add指令
	//如果进行了展开，编译器已经用Add函数的函数体替换了函数调用
	//Debug模式下。默认是不会展开的。因为Debug为调试模式，如果进行展开，就不能进行调试
	//想要知道展开就要进行设置
	cout << sum << endl;
	return 0;
}
#endif

int main()
{
	//在用auto定影变量时，必须对变量进行初始化
	//因为编译器在编译期间要根据变量的初始化表达式来推演该变量的实际表达式
	//将该实际类型推演出来之后替换auto
	auto a = 10;
	auto b = "1234";
	auto c = 12.34;
	auto d = a + 10;

	cout << typeid(a).name() << endl;//int
	cout << typeid(b).name() << endl;//char const *
	cout << typeid(c).name() << endl;//double
	cout << typeid(d).name() << endl;//int
	return 0;
}