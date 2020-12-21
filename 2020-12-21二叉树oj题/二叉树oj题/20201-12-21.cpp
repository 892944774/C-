#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

template<class K,class V>
struct BSTNode
{
	BSTNode(const K& k = K(), const V& v = V())
		: left(nullptr)
		, right(nullptr)
		, key(k)
		, value(v)
	{}

	BSTNode<K, V> *left;
	BSTNode<K, V> *right;
	K key;
	V value;
};

template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		: root(nullptr)
	{}

	Node* Find(const K& key)
	{
		Node* cur = root;
		while (cur)
		{
			if (key == cur->key)
				return cur;
			else if (key < cur->key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}

	bool Insert(const K& key, const V& value)
	{
		if (nullptr == root)
		{
			root = new Node(key, value);
			return true;
		}
		
		//找待插入节点在数据中的位置--保存其双亲
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key == cur->key)
				return false;
			else if (ker < cur->key)
				cur = cur->left;
			else
				cur = cur->right;
		}

		//插入新节点
		cur = new Node(key, value);
		if (key < parent->key)
			//要插入的节点比双亲的值小，插入到左边
			parent->left = cur;
		else
			parent->right = cur;
		return true;
	}

private:
	Node* root;
};

int main()
{
	string s[] = {"1111","2222","3333","4444"};
	BSTNode<string, size_t> t;
	BSTNode<string, size_t>* ret = nullptr;
	for (auto e : s)
	{
		if (ret = t.Find(e))
			ret->value++;
		else
			t.Insert(e, 1);
	}
	return 0;
}