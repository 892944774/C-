#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

void TestFunc()
{
	//需要在堆上开辟一块内存空间,创建Test类型的对象
	Test* pt = (Test*)malloc(sizeof(Test));

	free(pt);
}
int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
int main()
{
	//空间申请
	//申请单个空间
	int* p1 = new int;

	//申请单个类型空间并对其初始化
	int* p2 = new int(10);

	//申请一段连续的空间
	int* p3 = new int[10];

	//申请一段连续的空间进行初始化
	int* p4 = new int[10]{1,2,3,4,5,6,7,8,9,0}; 

	//释放空间
	//释放单个类型的空间
	delete p1;
	delete p2;

	//释放连续类型的空间
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt1 = new Test;
	Test* pt2 = new Test[10];

	delete pt1;
	delete[] pt2;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t)
		:_t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt1 = new Test(10);
	Test* pt2 = new Test(20);

	delete pt1;
	delete pt2;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 10)
		:_t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	//注意：申请连续对象的空间时，类必须是具有无参的或者是全缺省的构造函数
	Test* pt1 = new Test[10];

	delete pt1;
	return 0;
}
#endif

class Test
{
public:
	Test(int t = 10)
		:_t(t)
	{
		p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete p;
		cout << "~test():" << this << endl;
	}

private:
	int _t;
	int* p;
};

void TestFunc()
{
	//用malloc申请出来的对象，不能用delete来释放
	//因为在malloc申请出来的不是一个Test类型的对象，而是与Test类型大小相同的一段空间
	//因此在释放该空间时，不能使用delete来进行释放，因为在此类中会调用析构函数
	//而析构函数中需要对对象中p指针指向空间中的内容进行释放，而malloc申请的空间没有调用析构函数
	//对p1进行初始化，p1指向的空间中的内容是随机值
	//Test* p1 = (Test*)malloc(sizeof(Test));
	//delete p1;//程序崩溃
}

int main()
{
	TestFunc();
	return 0;
}