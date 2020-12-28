#pragma once

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x)
		: left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, data(x)
		, bf(0)
	{}

	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T data;
	int bf;//平衡因子
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}
	}

	//非空
	//1. 按照二叉搜索树的规则插入新节点
	//找新节点在树中的插入位置，并记录其双亲
	Node* cur = _root;
	Node* parent = nullptr;
	while (cur)
	{
		parent = cur;
		if (data < cur->data)
			cur = cur->left;
		else if (data > cur->data)
			cur = cur->right;
		else
			return false;
	}

	//新节点插入的位置已经找到--找到新节点
	cur = new Node(data);
	if (data < parent->data)
		parent->left = cur;
	else
		parent->right = cur;

	cur->parent = parent;

	while (parent)
	{
		//新节点插入之后，AVL树的平衡性可能会遭到破坏，必须更新平衡因子
		if (cur == parent->left)
			parent->bf--;
		else
			parent->bf++;

		if (0 == parent->bf)
			return true;
		else if (1 == parent->bf || -1 == parent->bf)
		{
			cur = parent;
			parent = cur->parent;
		}
	}

private:
	Node* _root;
};