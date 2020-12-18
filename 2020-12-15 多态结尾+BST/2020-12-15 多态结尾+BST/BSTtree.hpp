#pragma once

<<<<<<< HEAD
#if 0
=======
>>>>>>> d605849ff67a22563680907e8ed16041240f4436
template <class T>

//二叉树节点模拟
struct BSTNode
{
	BSTNode(const T& val = T())
		: left(nullptr)
		, right(nullptr)
		, data(val)
	{}

	BSTNode<T>* left;
	BSTNode<T>* right;
	T data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		: root(nullptr)
	{}

	~BSTNode()
	{
		_Destroy(root);
	}

	bool Insert(const T& data)
	{
		if (nullptr == root)
		{
			root = new Node(data);
			return true;
		}

		//BSTree非空
		//1 找待插入节点在树中的位置，并且要记录其parent的位置
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data == cur->data)
				return false;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		//2 插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* find(const T& data)
	{
		Node* cur = root;
		while (cur)
		{
			if (data == root->data)
				return cur;
			else if (data < root->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}

	//需要中序遍历来验证BSTree的正确性
	void Inorder()
	{
		_Inorder(root);
	}

	bool Erase(const T& data)
	{
		if (root == nullptr)
			return false;

		//BSTree非空
		//1找待删节点在BSTree中的位置，并保存其双亲
		Node* parent = nullptr;
		Node* cur = root;
		while (cur)
		{
			if (cur->data == data)
				break;
			else if (cur->data < data)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				parent = cur;
				cur = cur->left;
			}
		}
		
		//值为data的节点不存在
		if (cur == nullptr)
			return false;

		//2 删除节点
		//cur如果只有右孩子或者叶子节点
		if (nullptr == cur->left)
		{
			if (nullptr == parent)
				root = cur->right;

			else
			{
				if (cur == parent->left)
					parent->left = parent->right;
				else
					parent->right = cur->right;
			}
		}

		else if (nullptr == cur->right)
		{
			//cur只有左孩子
			if (nullptr == parent)
			{
				root = cur->left;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
		}

		else
		{
			//cur左右孩子均存在
			//找替代节点--假设在右子树中替代节点
			Node* del = cur->right;
			parent = cur;
			while (del->left)
			{
				parent = del;
				del = del->left;
			}

			// 将替代节点中的值域交给之前要删除的cur
			cur->data = del->data;

			// 相当于变成要删除del
			if (del == parent->left)
				parent->left = del->right;
			else
				parent->right = del->right;

			cur = del;
		}
		delete cur;
		return true;
	}

private:
	void _Inorder(Node* pRoot)
	{
		if (pRoot)
		{
			_Inorder(pRoot = pRoot->left);
			cout << pRoot->data << " ";
			_Inorder(pRoot = pRoot->right);
		}
	}

	void _Destroy(Node*& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->left);
			_Destroy(pRoot->right);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* root;
};

void Test()
{
	int a[] = {5,4,3,1,7,8,9,0,2};
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.Inorder();
<<<<<<< HEAD
}
#endif 

#if 0
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};

class Student : public Person
{
public:
	int _No; // 学号
};

void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.基类对象不能赋值给派生类对象
	sobj = pobj;
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj
		Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
}
#endif 

#if 0
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
#endif 

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
public:
	int _b;
};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived" << endl;
	}
	int _d;
};

void test()
{
	Base B;
	Derived D;
	Base& B = D;
	//通过基类对象的指针或者引用，指向派生类的对象，只能访问基类的成员变量
	B._b;
=======
>>>>>>> d605849ff67a22563680907e8ed16041240f4436
}