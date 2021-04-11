#pragma once
#include <iostream>
using namespace std;

//自动通用的数组类
template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		cout << "有参构造" << endl;
		m_Capacity = capacity;
		m_size = 0;
		pAddress = new T[m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "拷贝构造" << endl;
		m_Capacity = arr.m_Capacity;
		m_size = arr.m_size;

		//深拷贝
		pAddress = new T[arr.m_Capacity];

		//将arr中的数据都拷贝过来
		for (int i = 0; i < m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
	}

	//尾插法
	void Push_back(const T &val)
	{
		if (m_Capacity == m_size)
			return;
		pAddress[m_size] = val;
		m_size++;
	}

	//尾删法
	void Pop_back()
	{
		if (m_size == 0)
			return;
		m_size--;
	}

	//通过下标访问数组中的元素
	T& operator[](int index)
	{
		return pAddress[index];
	}

	//返回数组容量
	int GetCapacity()
	{
		return m_Capacity;
	}

	//返回数组大小
	int GetSize()
	{
		return m_size;
	}

	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray &arr)
	{
		cout << "operator=" << endl;
		//先判断原来堆区是否有数据，如果有就清空
		if (pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_Capacity = 0;
			m_size = 0;
		}

		//深拷贝
		m_Capacity = arr.m_Capacity;
		m_size = arr.m_size;
		pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//析构
	~MyArray()
	{
		if (pAddress != NULL)
		{
			cout << "析构" << endl;
			delete[] pAddress;
			pAddress = NULL;
		}
	}
private:
	T * pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity; //数组容量
	int m_size;//数组大小
};
