#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#include <map>
#include <string>

#if 0
int main()
{
	map<string, string> m1;

	m1.insert(pair<string, string>("orange", "橘子"));
	m1.insert(pair<string, string>("apple", "苹果"));
	m1.insert(pair<string, string>("banana", "香蕉"));
	m1.insert(make_pair("peach","桃子"));
	m1.insert(make_pair("watermelon", "西瓜"));

	//遍历：范围for
	for(auto& e : m1)
	{
		cout << e.first << "-" << e.second << endl;
	}

	//通过key获得与key对应的value值，
	//下标运算符既是查找，也是插入
	cout << m1["apple"] << endl;//苹果
	cout << m1["banana"] << endl;//香蕉

	m1["apple"] = "梨";
	cout << m1["apple"] << endl;//将Apple对应的value值改为梨

	//删除元素
	m1.erase("orange");

	//删除指定元素
	auto pos = m1.find("orange");
	while (pos != m1.end())
	{
		m1.erase(pos);
	}

	m1.erase(m1.begin(), m1.end());//删除全部元素

	//迭代器
	//map<string, string>::iterator it = m1.begin();
	cout << m1.size() << endl;
	auto it = m1.begin();
	while (it != m1.end())
	{
		cout << "<" << it->first << "," << it->second << ">"<< endl;
		++it;
	}

	//c++11
 	map<string, string> m2{ {"orange","橘子"},{"apple","苹果"},{"banana","香蕉"} };
	return 0;
}
#endif 

#if 0
#include <queue>
class Compare
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

int main()
{
	// 在以下水果中挑出员工最喜欢吃的三种水果---CVTE笔试题
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };

	//1.统计每个水果出现的次数
	map<string, size_t> m;
	for (auto& e : fruits)
	{
		m[e]++;
	}

	//2. 找出员工最喜欢吃的K种水果，TOP-K,priority_queue问题
	// 使用map中的元素构造一个大堆---->按照键值对中的次数进行比较
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());
	
	// 取到员工最喜欢吃的三种水果
	vector<string> favourite;
	for (size_t i = 0; i < 3; i++)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}
	return 0;
}
#endif

#if 0
#include <set>
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	multiset<string> s;
	for (auto& e : fruits)
	{
		cout << e << " ";
	}
	cout << endl;
	s.insert(fruits, fruits+sizeof(fruits)/sizeof(fruits[0]));
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#include "AVLTree.hpp"
int main()
{
	TestAVLTree1();
	TestAVLTree2();
	return 0;
}