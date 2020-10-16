#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
//Add函数模板
template<class T>  //模板的参数列表，声明函数
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//对函数模板的实例化
	Add(1, 2);//int 
	Add(2.1, 3.2);//double
	Add('1', '2');//char
	return 0;
}
#endif

#if 0
template<class T>
void Swap(T left, T right)
{
	T temp = left;
	left = right;
	right = temp;
}

//各种类型的数组
template<class T>
void PrintArray(T array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << "-";
	}

	cout << endl;
}

int main()
{
	int array[] = {1,2,3,4,5,6};
	PrintArray(array, sizeof(array) / sizeof(int));

	double array[] = {1.1, 2.2, 3.3};
	PrintArray(array, sizeof(array) / sizeof(double));
	return 0;
}
#endif

#if 0
//函数模板不是一个函数，而是一个函数的模具
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//隐式实例化
	//在隐式实例化中，编译器在生成代码时不会进行隐式类型转化
	Add(1, 2);//int
	//在底层中的函数实现
	/*int Add<int>(int left, int right)
	{
		cout << typeid(int).name() << endl;
		return left + right;
	}*/

	Add(1.0, 2.0);
	//在底层中的函数实现
	/*double Add<double>(double left, double right)
	{
		cout << typeid(double).name() << endl;
		return left + right;
	}*/

	//int和double之间可以隐式类型转化
	Add(1, (int)2.0);

	//显示实例化
	//编译器在编译代码期间，看到对函数模板进行显示实例化后
	//会根据显示实例化的T的具体类型直接生成代码
	//再具体调用的时候可能会发生隐式类型转化
	Add<int>(1, 2.0);
	Add<double>(1, 2.0);

	//Add(int)(1, "hello");//error
	return 0;
}
#endif

#if 0
template<class T, class U>
T Add(T left, U right)
{
	return left + right;
}

int main()
{
	Add(1, 2.0);
	//在底层中的实现
	/*int Add<int, double><int left, double right>
	{
		return left + right;
	}*/
	return 0;
}
#endif

#if 0
//函数模板：可以被实例化成类型不同的参数
template<class T1, class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add<int>(1, 2.0);
	return 0;
}
#endif

//模板类型的动态顺序表
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	void PushBack(const T& data);

	void PopBack()
	{
		if (!Empty())
		{
			--_size;
		}
	}

	bool Empty()const
	{
		return _size == 0;
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	T& operator[](size_t index)const
	{
		assert(insex<_size);
		return _array[index];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::PushBack(const T& data)
{
	if (_size = _capacity)
	{
		//扩容
	}

	//尾插
	_array[_size++] = data;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,0};
	cout << array[2] << endl;
	array[2] = 10;

	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	cout << s1[2] << endl;//[]-->下标运算符

	const SeqList<int> s0;//创建了一个顺序表的对象，其中对象中元素都是int型

	SeqList<double> s2;
	SeqList<Date> s3;
	return 0;
}