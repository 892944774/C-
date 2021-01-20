#pragma once
#include "RBTree.hpp"


namespace bite
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;

		class KOFV
		{
		public:
			const K& operator()(const ValueType& data)const
			{
				return data.first;
			}
		};

		typedef RBTree<ValueType, KOFV> RBTree;

		typename typedef RBTree::iterator iterator;
	public:
		map()
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

		V& operator[](const K& x)
		{
			return (*((this->insert(make_pair(x, V()))).first)).second;
		}

		pair<iterator, bool> insert(const ValueType& value)
		{
			return _t.Insert(value);
		}

		void swap(map<K, V>& m)
		{
			_t.swap(m._t);
		}

		void clear()
		{
			_t.clear();
		}

		iterator find(const K& key)
		{
			return _t.find(make_pair(key, V()));
		}
	private:
		RBTree _t;
	};
}

#include <iostream>
using namespace  std;
#include <string>

void TestMap()
{
	bite::map<string, string> m;
	m.insert(make_pair("apple", "ƻ"));
	m.insert(make_pair("orange", ""));
	m.insert(make_pair("banana", "㽶"));

	cout << m["apple"] << endl;
	cout << m.size() << endl;

	auto it = m.find("orange");
	if (it != m.end())
	{
		cout << it->second << endl;
	}

	it = m.begin();
	while (it != m.end())
	{
		cout << "<" << it->first << "," << it->second << ">" << endl;
		++it;
	}
	cout << endl;
}
