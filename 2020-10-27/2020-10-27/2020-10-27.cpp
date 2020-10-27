#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
int main()
{
	string s("12345");
	int value = atoi(s.c_str());

	string s1("hello");
	char* p = (char*)s1.c_str();
	*p = 'H';

	cout << sizeof(string) << endl; 
	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello");
	string s2("world");

	if (s1 < s2)
	{
		cout << "s1 < s2" << endl;
	}
	else
	{
		cout << "s1 >= s2";
	}
	return 0;
}
#endif

#include <string>
#if 0
int main()
{
	string s;
	//cin >> s;
	//cout << s << endl;

	//getline(cin, s);
	//cout << s << endl;

	//循环输入
	while (getline(cin, s))
	{
		cout << s << endl;
	}
	return 0;
}
#endif

#include <algorithm>
#if 0
int main()
{
	string s("hello");

	reverse(s.begin(), s.end());//逆置
	sort(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main()
{ 
	string s("hello");
	//遍历方式1，使用非常频繁
	for (size_t i=0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}

	//遍历方式2
	for (auto e : s)
		cout << e << "";
	cout << endl;

	//遍历方式3--正向迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
//反例
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//编译器默认的是拷贝构造函数--浅拷贝
	String(const String& s)
		: _str(s._str)
	{}

	//编译器生成的默认赋值运算符重载--浅拷贝
	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};

int main()
{
	String s1("hello");
	String S1(nullptr);
	return 0;
}
#endif

// 注意： 当类中涉及到资源(堆内存空间、文件指针等)管理时
//用户必须要显式实现拷贝构造函数、赋值运算符重载、析构函数---three big
//解决浅拷贝
//方式一：深拷贝--传统版
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str)+1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	String S1(nullptr);
	return 0;
}