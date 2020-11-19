#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0 
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data <T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _T2;
};

//全特化，对于所有类型的模板都具体化
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data <int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};

//偏特化
//1 部分特化
template<class T>
class Data<T, int>
{
public:
	Data()
	{
		cout << "Data <T, int>" << endl;
	}
private:
	T _d1;
	int _d2;
};

//2 让参数限制更加严格
//再对Data模板进行实例化期间，如果两个参数都是指针类型
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data <T1*, T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};

#include <string>

int main()
{
	//使用的是模板
	Data<int, int> d1;
	Data<char, char> d2;
	
	//使用的是特化版本
	Data<int, char> d3;

	Data<string, int> d4;

	Data<string*, int*> d5;
	Data<char*, char*> d6;
	return 0;
}
#endif

//假设实现一个通用的拷贝函数
//template <class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	//O[1]
//	memcpy(dst, src, sizeof(T)*size);
//
//	//O[N]
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		dst[i] = src[i];
//	}
//}

#if 0 
//萃取类型--类模板的特例化应用
//表示内置类型
struct True
{
	static bool Get()
	{
		return true;
	}
};

//表示自定义类型
struct False
{
	static bool Get()
	{
		return false;
	}
};

//用模板来检测T到底是什么类型的--自定义类型
template<class T>
struct TypeTraits
{
	typedef False PODTYPE;
};

//所有内置类型全部都进行特化
template<>
struct TypeTraits<double>
{
	typedef True PODTYPE;
};

template<>
struct TypeTraits<int>
{
	typedef True PODTYPE;
};

template<>
struct TypeTraits<char>
{
	typedef True PODTYPE;
};

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::PODTYPE::Get())
	{
		//如果是内置类型元素之间的拷贝
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		//如果是自定义类型元素之间的拷贝
		for (int i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}
}

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
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
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

void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5 };
	int array2[5];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));

	String s1[] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);

	char* p1 = new char[5];
	char* p2 = new char[5];
	Copy(p1, p2, 5);
	delete[] p1;
	delete[] p2;
}

int main()
{
	TestCopy();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

