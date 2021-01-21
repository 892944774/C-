#pragma once
#pragma once

#include <vector>

#include "Common.h"

template<class T>
struct HashNode
{
	// T()---> 默认值：
	// 如果T是内置类型，比如：T是int   int()  默认值都是0
	// 如果T是自定义类型，比如：T是Date  Date() : 调用默认的构造函数创建一个无名的对象
	//                       Date必须要提供一个无参的构造函数，否则当使用Date来实例化HashNode类模板时，
	//                       则会编译失败
	HashNode(const T& x = T())
		:next(nullptr)
		, data(x)
	{}

	HashNode<T>* next;
	T data;
};


// T 如果是int家族系列
template<class T>
class DToIntDef
{
public:
	const T& operator()(const T& data)const
	{
		return data;
	}
};

// 怎么将字符串转换为整形类型的数据？
// 1. atoi：可以---缺陷：只能转数字类型的字符串  “1234"--->1234   “hello”不能转
// 2. 将字符串中每个字符的ASCII码相加---可以："1234"还是"hello"都可以转---"abcd"  "adcb"  "abdc"...
// 3. 之前同学："1234"--->string---> 可以应用字符串在string中保存的时候底层空间的首地址  (int)c_str()--->不可用
//         已经在哈希表中保存："hello"   现在要找"hello"

// 4. 如果字符串中只包含小写字母：可以将这些小写字母看成是26进制的数据---->转化为：10进制   缺陷：容易溢出
// 5. 找度娘--
class StrToInt
{
public:
	size_t operator()(const string& data)const
	{
		return BKDRHash(data.c_str());
	}

	size_t BKDRHash(const char *str)const
	{
		size_t seed = 131; // 31 131 1313 13131 131313 etc..
		size_t hash = 0;

		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return (hash & 0x7FFFFFFF);
	}
};


// 前置声明
template<class T, class KOFV, class DToInt = StrToInt>//DToIntDef<T>>
class HashBucket;


template<class T, class KOFV, class DToInt>
struct HashBucketItertor
{
	typedef HashNode<T> Node;
	typedef HashBucketItertor<T, KOFV, DToInt> Self;

	HashBucketItertor(Node* pNode = nullptr, HashBucket<T, KOFV, DToInt>* ht = nullptr)
		: _pNode(pNode)
		, _ht(ht)
	{}

	// 具有指针类似的操作
	T& operator*()
	{
		return _pNode->data;
	}

	T* operator->()
	{
		return &(operator*());
	}

	// 迭代器能够移动
	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// 注意：哈希桶的迭代器没有--操作，因为其底层使用的是单链表
	bool operator!=(const Self& s)
	{
		return !(*this == s);
	}

	bool operator==(const Self& s)
	{
		return _pNode == s._pNode && _ht == s._ht;
	}

	// 找当前迭代器的下一个位置
	void Next()
	{
		// 1. pNode之后有节点
		if (_pNode->next)
		{
			_pNode = _pNode->next;
		}
		else
		{
			// 2. pNode是当前桶中的最后一个节点---需要找下一个非空桶
			// a. 需要知道当前迭代器所在的桶号--哈希函数 b. 需要拿到所有的桶   table
			size_t bucketCount = _ht->BucketCount();
			size_t bucketNo = _ht->HashFunc(_pNode->data, bucketCount) + 1;
			for (; bucketNo < bucketCount; ++bucketNo)
			{
				if (_ht->table[bucketNo])
				{
					_pNode = _ht->table[bucketNo];
					return;
				}
			}

			_pNode = nullptr;
		}
	}

	Node* _pNode;
	HashBucket<T, KOFV, DToInt>* _ht;
};

// 哈希桶---->
// T：存储元素的类型
// DToInt: 将T转换为整形数据--->哈希函数服务：除留余数法
template<class T, class KOFV, class DToInt>
class HashBucket
{
	friend HashBucketItertor<T, KOFV, DToInt>;

	typedef HashNode<T> Node;

public:
	typedef HashBucketItertor<T, KOFV, DToInt> iterator;

public:
	HashBucket(size_t capacity = 10)
		: table(10/*GetNextPrime(capacity)*/)
		, _size(0)
	{}

	~HashBucket()
	{
		clear();
	}

	iterator begin()
	{
		// 找非空桶
		for (size_t bucket = 0; bucket < table.capacity(); ++bucket)
		{
			if (table[bucket])
			{
				return iterator(table[bucket], this);
			}
		}

		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	// 向哈希桶中插入元素---保证元素是唯一的
	pair<iterator, bool> InsertUnique(const T& data)
	{
		_CheckCapacity();
		// 1. 通过哈希函数计算桶号
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. 检测data是否在bucketNo桶中存在
		Node* cur = table[bucketNo];
		while (cur)
		{
			if (KOFV()(data) == KOFV()(cur->data))
			{
				return make_pair(iterator(cur, this), false);
			}

			cur = cur->next;
		}

		// 3. 插入元素---头插法
		cur = new Node(data);
		cur->next = table[bucketNo];
		table[bucketNo] = cur;
		_size++;

		return make_pair(iterator(cur, this), true);
	}

	// 向哈希桶中插入元素---元素可以重复---自己处理
	bool InsertEqual(const T& data)
	{
		// 1. 通过哈希函数计算桶号
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. 插入元素
		Node* cur = new Node(data);
		cur->next = table[bucketNo];
		table[bucketNo] = cur;
		_size++;
		return true;
	}

	// 元素是唯一，找到一个删除即可
	size_t EraseUnique(const T& data)
	{
		// 1. 通过哈希函数计算元素所在的桶号
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. 在该桶中找值为data的节点并将其删除掉
		Node* cur = table[bucketNo];
		Node* prev = nullptr;
		while (cur)
		{
			if (KOFV()(cur->data) == KOFV()(data))
			{
				// 删除该节点
				// 注意：该节点可能是链表中的第一个节点 也可能是非第一个节点
				if (nullptr == prev)
				{
					table[bucketNo] = cur->next;
				}
				else
				{
					prev->next = cur->next;
				}
				delete cur;
				_size--;
				return 1;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}

		return 0;
	}

	// 将哈希桶中值为data的所有节点全部删除掉
	size_t EraseEquel(const T& data)
	{
		return 0;
	}

	iterator Find(const T& data)
	{
		// 1. 通过哈希函数计算对应的桶号
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. 在bucketNo对应的链表中找值为data的节点
		Node* cur = table[bucketNo];
		while (cur)
		{
			if (KOFV()(data) == KOFV(cur->data))
				return iterator(cur, this);

			cur = cur->next;
		}

		return end();
	}

	size_t size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	// 按照桶的编号从小到大逐个链表来进行打印
	void PrintHashBucket()
	{
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			cout << "[" << i << "]:";

			// 打印该桶中的所有节点
			Node* cur = table[i];
			while (cur)
			{
				cout << cur->data << "--->";
				cur = cur->next;
			}

			cout << "NULL" << endl;
		}

		cout << "================================================" << endl;
	}

	void Swap(HashBucket<T, KOFV, DToInt>& ht)
	{
		table.swap(ht.table);
		std::swap(_size, ht._size);
	}

	void clear()
	{
		// 将所有桶中的节点全部删除掉
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			// 采用头删法来删除链表中的所有节点
			Node* cur = table[i];
			while (cur)
			{
				table[i] = cur->next;
				delete cur;
				cur = table[i];
			}
		}

		_size = 0;
	}

	/////////////////////////////////////////////////
	// 桶相关的操作
	// 获取桶的总个数
	size_t BucketCount()const
	{
		return table.capacity();
	}

	// 获取bucketNo桶中节点的个数
	size_t BucketSize(size_t bucketNo)const
	{
		if (bucketNo >= BucketCount())
			return 0;

		Node* cur = table[bucketNo];
		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		return count;
	}

	// 返回data所在的桶号
	size_t Bucket(const T& data)
	{
		return HashFunc(data, BucketCount());
	}

private:
	// 除留余数法
	size_t HashFunc(const T& data, size_t capacity)
	{
		//DToInt dtoi;
		//return dtoi(data) % capacity;
		return DToInt()(KOFV()(data)) % capacity;
	}

	void _CheckCapacity()
	{
		if (_size == table.capacity())
		{
			vector<Node*> bucket(GetNextPrime(table.capacity()));

			// 将旧桶中每条链表中的节点逐个移动到新桶中
			for (size_t i = 0; i < table.capacity(); ++i)
			{
				Node* cur = table[i];
				while (cur)
				{
					// 1. 需要将该节点从旧链表中拆下来---头删法
					table[i] = cur->next;


					// 2. 将cur插入到新桶中
					// a. 计算该节点在新哈希桶的那个桶中
					//HashFunc(cur->data);  旧哈希桶对应的哈希函数
					size_t bucketNo = HashFunc(cur->data, bucket.capacity());

					// b. 将该节点插入到新桶中---头插
					cur->next = bucket[bucketNo];
					bucket[bucketNo] = cur;

					// 3. 取旧桶中的下一个节点
					cur = table[i];
				}
			}

			// 旧哈希桶中的元素已经全部移动到新桶中的
			table.swap(bucket);
		}
#if 0
		if (_size == table.capacity())
		{
			HashBucket<T> newHt(table.capacity() * 2);

			// 将旧哈希桶中的元素逐个的插入到新哈希桶中
			for (size_t i = 0; i < table.capacity(); ++i)
			{
				// 将一个桶中的元素插入到新哈希桶中
				Node* cur = table[i];
				while (cur)
				{
					newHt.InsertUnique(cur->data);
					cur = cur->next;
				}
			}

			this->Swap(newHt);
		}
#endif
	}
private:
	std::vector<Node*> table;
	size_t _size;   // 表示哈希桶中有效元素的个数
};

#include <iostream>
using namespace std;

class KOFV
{
public:
	int operator()(int data)const
	{
		return data;
	}
};

void TestHashBucket1()
{
	HashBucket<int, KOFV, DToIntDef<int>> ht;

	int array[] = { 1,4,5,6,7,9,3,2,8,0 };

	for (auto e : array)
	{
		ht.InsertUnique(e);
	}



	cout << ht.size() << endl;
	ht.PrintHashBucket();


	ht.InsertUnique(44);
	ht.PrintHashBucket();

	auto it = ht.begin();
	while (it != ht.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


//#include <string>
//
//void TestHashBucket2()
//{
//	HashBucket<string, StrToInt> ht;
//	ht.InsertUnique("apple");
//}