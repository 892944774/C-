#pragma once
#include <iostream>
using namespace std;

//�Զ�ͨ�õ�������
template<class T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		cout << "�вι���" << endl;
		m_Capacity = capacity;
		m_size = 0;
		pAddress = new T[m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
		cout << "��������" << endl;
		m_Capacity = arr.m_Capacity;
		m_size = arr.m_size;

		//���
		pAddress = new T[arr.m_Capacity];

		//��arr�е����ݶ���������
		for (int i = 0; i < m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
	}

	//β�巨
	void Push_back(const T &val)
	{
		if (m_Capacity == m_size)
			return;
		pAddress[m_size] = val;
		m_size++;
	}

	//βɾ��
	void Pop_back()
	{
		if (m_size == 0)
			return;
		m_size--;
	}

	//ͨ���±���������е�Ԫ��
	T& operator[](int index)
	{
		return pAddress[index];
	}

	//������������
	int GetCapacity()
	{
		return m_Capacity;
	}

	//���������С
	int GetSize()
	{
		return m_size;
	}

	//operator= ��ֹǳ��������
	MyArray& operator=(const MyArray &arr)
	{
		cout << "operator=" << endl;
		//���ж�ԭ�������Ƿ������ݣ�����о����
		if (pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_Capacity = 0;
			m_size = 0;
		}

		//���
		m_Capacity = arr.m_Capacity;
		m_size = arr.m_size;
		pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//����
	~MyArray()
	{
		if (pAddress != NULL)
		{
			cout << "����" << endl;
			delete[] pAddress;
			pAddress = NULL;
		}
	}
private:
	T * pAddress;//ָ��ָ��������ٵ���ʵ����
	int m_Capacity; //��������
	int m_size;//�����С
};
