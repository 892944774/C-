#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

//构造
#if 0
void TestStrings1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(10, 'a');

	string s5(100, 'b');

	string s6("hello", 10);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cin >> s1;
	cout << s1 << endl;
}
#endif 

//容量
#if 0
void TestStirng2()
{
	string s1("hello");
	cout << s1.size() << endl;//5
	cout << s1.length() << endl;//5
	cout << s1.capacity() << endl;//15

	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}

	else
	{
		cout << "非空字符串" << endl;
	}

	s1.clear();
	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}

	else
	{
		cout << "非空字符串" << endl;
	}
}
#endif

//void resize(size_t n, char c)
//void resize(size_t n)
/*
s1.resize(20, '!');
假设s1中有效字符为size 容量为capacity
size > 20 将有效字符个数减少到20个，第二个参数不起作用
size < 20 将s1中有效字符个数增多到20个，多出的20-size个字符使用!(第二个参数)进行填充
如果第二个参数没有提供，则使用0进行填充----很少使用
capacity > 20  底层不需要扩容
capacity < 20 再将字符个数增多时，需要进行扩容

当使用resize将字符有效个数减少时，resize方法不会缩小底层容量的大小
*/
#if 0
void TestString3()
{
	string s1("hello");

	//将s1中的字符增加到10个，多出来的用！来填充
	s1.resize(10);

	//将s1的有效字符增加到32个，多出来的22个字符用$来添加，在增加期间字符会扩容
	s1.resize(32, '$');

	//resize减少有效字符的个数，但是底层中不会缩小底层空间的大小
	s1.resize(28, '&');
	s1 += "world";
	s1.resize(20);
	s1.resize(16);

	s1.resize(8);
}
#endif

//  void reserve(size_t newcapacity)
/*
假设：string类型对象原来的容量为oldcapacity

newcapacity <= oldcapacity 将string类型对象底层的容量缩小
当newcapacity > 15时，底层容量不会发生改变
当newcapacity <= 15时，string类会将底层动态开辟的空间释放掉，使用内部的静态数组

newcapacity > oldcapacity：将string类型对象底层的容量增大
实际增加到多大，newcapacity只是一个参考
*/
#if 0
void TestString4()
{
	string s1("hello");
	cout << sizeof(s1) << endl;

	//扩容
	s1.resize(10);
	s1.resize(12);
	s1.resize(20);
	s1.resize(42);

	//缩容
	s1.resize(32);
	s1.resize(28);
	s1.resize(20);
	s1.resize(13);
}
#endif

#if 0
void TestString5()
{
	string s1("hello");
	cout << s1[0] << endl;
	s1[0] = 'H';

	cout << s1.at(0) << endl;
}
#endif

#if 0
void TestString6()
{
	string s1("hello");
	cout << s1 << endl;

	s1.push_back(',');
	cout << s1 << endl;//hello,

	s1.append(1, '%');
	cout << s1 << endl;//hello,%

	s1.append(s1, 2, 3);
	cout << s1 << endl;//hello,%llo
}
#endif

#if 0
void TestString7()
{
	string s1("hello world !!!");
	s1.insert(s1.find(' ', 7), "$$$");//hello world$$$ !!!
	cout << s1 << endl;
}
#endif

void TestString8()
{
	string s;
	//cin >> s;  hello  world
	getline(cin, s);
	cout << s << endl;
	cout << s.substr(s.rfind(' ') + 1) << endl;//从后向前找空格，加1找到空格后的第一个字符，然后读取字符, world
	cout << s.substr(s.rfind(' ') + 1).size() << endl;//从后向前找空格，加1找到空格后的第一个字符，然后读取字符长度,5
}

int main()
{
	//TestStrings1();
	//TestStirng2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	TestString8();
	return 0;
}