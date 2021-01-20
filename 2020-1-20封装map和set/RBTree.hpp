#pragma once
#pragma once


#include <iostream>
using namespace std;



enum Color { RED, BLACK };


template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T(), Color c = RED)
		: left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, data(x)
		, color(c)
	{}

	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};

#if 0
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
	}

	~RBTree()
	{
		_Destroy(head->parent);
	}

	bool Insert(const T& data)
	{
		// 红黑树也是二叉搜索树
		// 1. 按照二叉搜索树的规则插入新节点
		Node*& root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			head->left = root;
			head->right = root;
			root->parent = head;
			return true;
		}

		// 找待插入节点在二叉搜索树的中位置，并且保存其双亲
		Node* cur = root;
		Node* parent = head;
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

		// 插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;


		// 新节点插入成功后，红黑树的性质3可能会遭到破坏
		// 因为cur新节点的默认颜色是红色的
		// 如果parent节点的颜色是黑色的，没有违反任何性质
		// 如果parent节点的颜色是红色的，违反了性质三,必须进行调整
		while (parent != head && RED == parent->color)
		{
			// parent != head : 该条件可以确定parent一定是树中有效的节点
			// parent->color == RED: 该条件可以保证parent一定不是根节点
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// 课件中给的情况一二三
				Node* uncle = grandFather->right;
				if (uncle && uncle->color == RED)
				{
					// 情况一
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// 如果原来grandFather有双亲，需要继续往上更新
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// 情况二和情况三
					if (cur == parent->right)
					{
						// 情况三
						RotateLeft(parent);
						swap(parent, cur);
					}

					// 情况二
					parent->color = BLACK;
					grandFather->color = RED;
					RotateRight(grandFather);
				}
			}
			else
			{
				// 课件中给的情况一二三的反情况
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// 情况一反情况
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// 需要继续往上更新
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// 情况二和情况三的反情况
					if (cur == parent->left)
					{
						//情况三的反情况
						RotateRight(parent);
						swap(parent, cur);
					}

					// 情况二的反情况
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFather);
				}
			}
		}

		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();
		return true;
	}

	void InOrder()
	{
		_InOrder(head->parent);
		cout << endl;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		// 1. 空树
		if (nullptr == root)
			return true;

		// 2. 非空----按照红黑树的性质来进行检测
		if (BLACK != root->color)
		{
			cout << "违反红黑树性质二：根节点不是黑色的!!!" << endl;
			return false;
		}

		// 验证性质三和性质四
		// 优先验证性质四：每条路径中黑色节点个数相同---遍历找到每条路径中黑色节点个数然后对比
		// 找到一条路径中黑色节点的个数---统计最左侧路径中黑色节点个数
		size_t blockCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blockCount++;

			cur = cur->left;
		}

		// 检测其他路径中黑色节点的格式与最左侧路径中黑色节点个数是否相同
		size_t pathCount = 0;
		return _IsValidRBTree(root, blockCount, pathCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t blockCount, size_t pathCount)
	{
		if (nullptr == root)
		{
			return true;
		}

		if (BLACK == root->color)
		{
			pathCount++;
		}

		Node* parent = root->parent;
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "违反性质3：有连在一起的红色节点!!!" << endl;
			return false;
		}

		// 如果root现在是叶子节点---说明一条路径走到底
		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathCount != blockCount)
			{
				cout << "违反性质4：路径中黑色节点的个数不一样!!!" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->left, blockCount, pathCount) &&
			_IsValidRBTree(root->right, blockCount, pathCount);
	}

	Node* LeftMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->right)
			cur = cur->right;

		return cur;
	}

	// 左单旋
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		Node* pparent = parent->parent;

		// 更新subR以及parent的双亲
		parent->parent = subR;
		subR->parent = pparent;

		// 处理旋转之前parent双亲的左孩孩子指针域
		if (pparent == head)
		{
			// 说明旋转之前parent就是根节点，旋转完成之后新的跟节点应该为subR
			head->parent = subR;
		}
		else
		{
			// 旋转之前parent的根节点是存在的
			if (parent == pparent->left)
			{
				pparent->left = subR;
			}
			else
			{
				pparent->right = subR;
			}
		}
	}

	// 右单旋
	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// 更新parent和subL的双亲
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// 需要处理pparent的指针情况
		if (pparent == head)
		{
			head->parent = subL;
		}
		else
		{
			if (parent == pparent->left)
			{
				pparent->left = subL;
			}
			else
			{
				pparent->right = subL;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data << " ";
			_InOrder(root->right);
		}
	}

	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->left);
			_Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

private:
	Node* head;
};
#endif

// 给红黑树增加迭代器：
template<class T>
struct RBtreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBtreeIterator<T> Self;

	RBtreeIterator(Node* node = nullptr)
		: pNode(node)
	{}

	// 具有指针类似的方法
	T& operator*()
	{
		return pNode->data;
	}

	T* operator->()
	{
		// return &(pNode->data);
		return &(operator*());
	}

	// 可以移动
	Self& operator++()
	{
		Increament();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	Self& operator--()
	{
		Decreament();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decreament();
		return temp;
	}

	// 能够进行比较
	bool operator==(const Self& s)const
	{
		return pNode == s.pNode;
	}

	bool operator!=(const Self& s)const
	{
		return pNode != s.pNode;
	}

private:
	void Increament()
	{
		// 前置++和后置++需要用来--->找比当前节点大的节点中值域最小的
		if (pNode->right)
		{
			// 到pNode的右子树中找最左侧节点(最小的节点)
			pNode = pNode->right;
			while (pNode->left)
				pNode = pNode->left;
		}
		else
		{
			// pNode没有右子树，只能往pNode的双亲中进行查找
			Node* parent = pNode->parent;
			while (parent->right == pNode)
			{
				pNode = parent;
				parent = pNode->parent;
			}

			// 特殊情况：根节点没有右孩子场景
			if (pNode->right != parent)
				pNode = parent;
		}
	}

	void Decreament()
	{
		// 找比当前节点小的所有节点中值最大的节点
		// 左子树中找最大节点  也可以再其双亲中找
		if (pNode->parent->parent == pNode && RED == pNode->color)
		{
			// pNode已经在end的位置
			pNode = pNode->right;
		}
		else if (pNode->left)
		{
			// 左子树存在
			pNode = pNode->left;
			while (pNode->right)
				pNode = pNode->right;
		}
		else
		{
			// 左子树不存在，只能在其双亲中进行查找
			Node* parent = pNode->parent;
			while (pNode == parent->left)
			{
				pNode = parent;
				parent = pNode->parent;
			}

			pNode = parent;
		}
	}

	Node* pNode;
};

// T 表示红黑树中存放元素的类型
// KOFV: 表示获取元素中key的方式
template<class T, class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBtreeIterator<T> iterator;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
		_size = 0;
	}

	~RBTree()
	{
		_Destroy(head->parent);
	}

	///////////////////////////////////
	// iterator
	iterator begin()
	{
		return iterator(head->left);
	}

	iterator end()
	{
		return iterator(head);
	}

	///////////////////////////////////
	// capacity
	bool empty()const
	{
		return nullptr == head->parent;
	}

	size_t size()const
	{
		return _size;
	}

	/////////////////////////////////////////
	// acess


	pair<iterator, bool> Insert(const T& data)
	{
		// 红黑树也是二叉搜索树
		// 1. 按照二叉搜索树的规则插入新节点
		Node*& root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			head->left = root;
			head->right = root;
			root->parent = head;
			_size = 1;
			return make_pair(iterator(root), true);
		}

		// 找待插入节点在二叉搜索树的中位置，并且保存其双亲
		Node* cur = root;
		Node* parent = head;
		KOFV kofv;   // 从data中获取key的仿函数对象
		while (cur)
		{
			parent = cur;
			if (kofv(data) < kofv(cur->data))
				cur = cur->left;
			else if (kofv(data) > kofv(cur->data))
				cur = cur->right;
			else
				return make_pair(iterator(cur), false);
		}

		// 插入新节点
		cur = new Node(data);
		Node* pNewNode = cur;
		if (kofv(data) < kofv(parent->data))
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;


		// 新节点插入成功后，红黑树的性质3可能会遭到破坏
		// 因为cur新节点的默认颜色是红色的
		// 如果parent节点的颜色是黑色的，没有违反任何性质
		// 如果parent节点的颜色是红色的，违反了性质三,必须进行调整
		while (parent != head && RED == parent->color)
		{
			// parent != head : 该条件可以确定parent一定是树中有效的节点
			// parent->color == RED: 该条件可以保证parent一定不是根节点
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// 课件中给的情况一二三
				Node* uncle = grandFather->right;
				if (uncle && uncle->color == RED)
				{
					// 情况一
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// 如果原来grandFather有双亲，需要继续往上更新
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// 情况二和情况三
					if (cur == parent->right)
					{
						// 情况三
						RotateLeft(parent);
						std::swap(parent, cur);
					}

					// 情况二
					parent->color = BLACK;
					grandFather->color = RED;
					RotateRight(grandFather);
				}
			}
			else
			{
				// 课件中给的情况一二三的反情况
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// 情况一反情况
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// 需要继续往上更新
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// 情况二和情况三的反情况
					if (cur == parent->left)
					{
						//情况三的反情况
						RotateRight(parent);
						std::swap(parent, cur);
					}

					// 情况二的反情况
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFather);
				}
			}
		}

		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();
		_size++;
		return make_pair(iterator(pNewNode), true);
	}

	void swap(RBTree<T, KOFV>& t)
	{
		std::swap(head, t.head);
	}

	void clear()
	{
		_Destroy(head->parent);
		_size = 0;
		head->left = head;
		head->right = head;
	}

	iterator find(const T& data)
	{
		KOFV kofv;
		Node* cur = GetRoot();
		while (cur)
		{
			if (kofv(data) == kofv(cur->data))
				return iterator(cur);
			else if (kofv(data) < kofv(cur->data))
				cur = cur->left;
			else
				cur = cur->right;
		}

		return iterator(head);
	}

	void InOrder()
	{
		_InOrder(head->parent);
		cout << endl;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		// 1. 空树
		if (nullptr == root)
			return true;

		// 2. 非空----按照红黑树的性质来进行检测
		if (BLACK != root->color)
		{
			cout << "违反红黑树性质二：根节点不是黑色的!!!" << endl;
			return false;
		}

		// 验证性质三和性质四
		// 优先验证性质四：每条路径中黑色节点个数相同---遍历找到每条路径中黑色节点个数然后对比
		// 找到一条路径中黑色节点的个数---统计最左侧路径中黑色节点个数
		size_t blockCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blockCount++;

			cur = cur->left;
		}

		// 检测其他路径中黑色节点的格式与最左侧路径中黑色节点个数是否相同
		size_t pathCount = 0;
		return _IsValidRBTree(root, blockCount, pathCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t blockCount, size_t pathCount)
	{
		if (nullptr == root)
		{
			return true;
		}

		if (BLACK == root->color)
		{
			pathCount++;
		}

		Node* parent = root->parent;
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "违反性质3：有连在一起的红色节点!!!" << endl;
			return false;
		}

		// 如果root现在是叶子节点---说明一条路径走到底
		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathCount != blockCount)
			{
				cout << "违反性质4：路径中黑色节点的个数不一样!!!" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->left, blockCount, pathCount) &&
			_IsValidRBTree(root->right, blockCount, pathCount);
	}

	Node* LeftMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->right)
			cur = cur->right;

		return cur;
	}

	// 左单旋
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		Node* pparent = parent->parent;

		// 更新subR以及parent的双亲
		parent->parent = subR;
		subR->parent = pparent;

		// 处理旋转之前parent双亲的左孩孩子指针域
		if (pparent == head)
		{
			// 说明旋转之前parent就是根节点，旋转完成之后新的跟节点应该为subR
			head->parent = subR;
		}
		else
		{
			// 旋转之前parent的根节点是存在的
			if (parent == pparent->left)
			{
				pparent->left = subR;
			}
			else
			{
				pparent->right = subR;
			}
		}
	}

	// 右单旋
	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// 更新parent和subL的双亲
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// 需要处理pparent的指针情况
		if (pparent == head)
		{
			head->parent = subL;
		}
		else
		{
			if (parent == pparent->left)
			{
				pparent->left = subL;
			}
			else
			{
				pparent->right = subL;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data << " ";
			_InOrder(root->right);
		}
	}

	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->left);
			_Destroy(root->right);
			delete root;
			root = nullptr;
			_size = 0;
		}
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

private:
	Node* head;
	size_t _size;   // 表示树中有效元素的个数
};



class KOFV
{
public:
	int operator()(int key)
	{
		return key;
	}
};

void TestRBTree()
{
	// 0. 创建红黑树
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int, KOFV> t;

	for (auto e : a)
	{
		t.Insert(e);
	}

	// 1. 验证是否为二叉搜索树
	t.InOrder();

	// 2. 验证是否满则红黑树的性质
	if (t.IsValidRBTree())
	{
		cout << "红黑树ok" << endl;
	}
	else
	{
		cout << "红黑树error!!!" << endl;
	}

	RBTree<int, KOFV>::iterator it = t.begin();
	while (it != t.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 对于自定义结构，如果定义begin和end的方法之后 就可以使用for来进行遍历了
	for (auto e : t)
	{
		cout << e << " ";
	}
	cout << endl;
}