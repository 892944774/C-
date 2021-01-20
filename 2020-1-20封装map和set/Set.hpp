#pragma once
namespace bite
{
	template<class K>
	class set
	{
		typedef K ValueType;

		class KOFV
		{
		public:
			const K& operator()(const ValueType& data)const
			{
				return data;
			}
		};

		typedef RBTree<ValueType, KOFV> RBTree;

		// 如果类中有静态成员变量，静态成员变量访问方式：类名::静态成员变量的名字
		// 如果不加typename，RBTree::iterator--->编译器无法知道iterator是RBTree中的类型还是静态成员变量
		// 加上typename之后，明确告诉编译器，iterator是RBTree中的一个类型
		typename typedef RBTree::iterator iterator;
	public:
		set()
			: _t()
		{}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool empty()const
		{
			return _t.empty();
		}

		size_t size()const
		{
			return _t.size();
		}

		pair<iterator, bool> insert(const ValueType& value)
		{
			return _t.Insert(value);
		}

		void swap(set<K>& s)
		{
			_t.swap(s._t);
		}

		void clear()
		{
			_t.clear();
		}

		iterator find(const K& key)
		{
			return _t.find(key);
		}
	private:
		RBTree _t;
	};
}

#include <iostream>
using namespace  std;

#include <string>

void TestSet()
{
	bite::set<string> m;

	m.insert("apple");
	m.insert("orange");
	m.insert("banana");

	cout << m.size() << endl;

	auto it = m.find("orange");
	if (it != m.end())
	{
		cout << *it << endl;
	}

	it = m.begin();
	while (it != m.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}