#pragma once
#pragma once

#include "HashBucket.hpp"

namespace bite
{
	// 底层数据结构是哈希桶
	template<class K>
	class unordered_set
	{
		typedef K ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef HashBucket<ValueType, KOFV>  HTB;

	public:
		// typename作用：告诉编译器，iterator是HTB中的内部类型，不是静态成员变量
		typename typedef HTB::iterator iterator;

	public:
		unordered_set()
			: _ht()
		{}

		//////////////////////////////////////////////////
		// iterator
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		/////////////////////////////////////////////////
		// capacity
		bool empty()const
		{
			return _ht.Empty();
		}

		size_t size()const
		{
			return _ht.size();
		}

		//////////////////////////////////////////////////
		// find
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		//////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.EraseUnique(key);
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(unordered_set<K>& m)
		{
			_ht.Swap(m._ht);
		}

		/////////////////////////////////////////////////////
		// 桶相关相关联的操作
		size_t bucket_count()const
		{
			return _ht.BucketCount();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.BucketSize(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.Bucket(key);
		}
	private:
		HTB _ht;
	};
}
