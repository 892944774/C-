#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>

#if 0
int main()
{
	string s1;
	s1 = "hello world";
	cout << s1 << endl;

	string s2;
	s2 = s1;
	cout << s2 << endl;
	
	string s3;
	s3 = 'a';
	cout << s3 << endl;

	string s4;
	s4.assign("hello world");
	cout << s4 << endl;

	string s5;
	s5.assign("zhangsen", 3);
	cout << s5 << endl;
	
	string s6;
	s6.assign(s5);
	cout << s6 << endl;

	string s7;
	s7.assign(5, 'x');
	cout << s7 << endl;
	return 0;
}

int main()
{
	string s1 = "adbasdfas";
	int pos = s1.find("ba");
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	cout << pos << endl;

	pos = s1.rfind("fa");
	cout << pos << endl;

	string s2 = "asasdfsdf";
	s2.replace(2,2,"11111");
	cout << s2 << endl;//as11111dfsdf

	//循环打印
	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << endl;
	}

	s2[1] = '3';
	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}

	string s3 = "892944774@qq.com";
	int ps = s3.find("@");

	string name = s3.substr(0, ps);//892944774
	cout << name << endl;
	return 0;
}

void PrintVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
}

int main()
{
	vector<int>v1;//默认无参构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	cout << endl;

	vector<int>v2(v1.begin(), v1.end());
	PrintVector(v2);
	cout << endl;

	vector<int>v3(10,2);
	PrintVector(v3);
	cout << endl;

	vector<int>v4(v3);
	PrintVector(v4);
	cout << endl;

	cout << v4.capacity() << endl;
	cout << v4.size() << endl;
	v4.resize(14);
	PrintVector(v4);//2 2 2 2 2 2 2 2 2 2 0 0 0 0
	cout << endl;
	v4.resize(4);
	PrintVector(v4);
	cout << endl;

	v4.resize(13, 9);
	PrintVector(v4);
	return 0;
}

void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	vector<int> v2;
	for (int j = 10; j > 0; j--)
	{
		v2.push_back(j);
	}
	PrintVector(v2);

	v1.swap(v2);
	PrintVector(v1);
	PrintVector(v2);
	return 0;
}

//deque容器赋值操作
void PrintDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	d1.push_back(12);
	d1.push_back(22);

	d1.push_front(12);
	d1.push_front(22);
	d1.pop_front();
	d1.pop_back();

	d1.insert(d1.begin(), 2, 99);
	PrintDeque(d1);
	return 0;
}

//选手类
class Person
{
public:
	Person(string name, int score)
	{
		_name = name;
		_score = score;
	}

	int _score;
	string _name;
};

void CreatePerson(vector<Person> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);

		//将创建的Person对象放入到容器中
		v.push_back(p);
	}
}

void SetScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		/*cout << "选手：" << it->_name << " ";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/

		//排序
		sort(d.begin(), d.end());

		//删除最高最低值
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		int avg = sum / d.size();
		it->_score = avg;
	}
}

void ShowScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->_name << " " << it->_score;
		cout << endl;
	}
	cout << endl;
}

int main()
{ 
	//1.创建5名选手
	vector<Person>v;//存放选手容器
	CreatePerson(v);

	//2.给选手打分
	SetScore(v);

	//3.显示平均分
	ShowScore(v);
	return 0;
}

class Person
{
public:
	Person(string name, int age)
	{
		_name = name;
		_age = age;
	}

	string _name;
	int _age;
};

int main()
{
	//创建队列
	queue<Person>q;
	
	//准备数据
	Person p1("zzasdf", 11);
	Person p2("zzasdff", 12);
	Person p3("zzavvvvsdf", 14);
	Person p4("zzqqqqasdf", 13);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty())
	{
		//查看对头
		cout << q.front()._age << " " << q.front()._name << endl;

		//查看队尾
		cout << q.back()._age << " " << q.back()._name << endl;

		//出队操作
		q.pop();
	}
	return 0;
}

//pair对组的创建
int main()
{
	//第一种方式
	pair<string, int>p("张森", 25);
	cout << p.first << " " << p.second << endl;

	//第二种方法
	pair<string, int>p2 = make_pair("在",12);
	cout << p2.first << " " << p2.second << endl;
	return 0;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

int main()
{
	set<int> s1;
	s1.insert(12);
	s1.insert(13);
	s1.insert(14);
	s1.insert(15);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
	set<int, MyCompare> s2;
	s2.insert(12);
	s2.insert(13);
	s2.insert(14);
	s2.insert(15);
	for (set<int, MyCompare>::iterator ivt = s2.begin(); ivt != s2.end(); ivt++)
	{
		cout << *ivt << " ";
	}
	cout << endl;
	return 0;
}

void PrintMap(map<int, int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key " << it->first << " value" << it->second << endl;
	}
	cout << endl;
}

int main()
{
	map<int,int>m;//默认构造
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	PrintMap(m);

	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << pos->second << endl;
	}

	int num = m.count(3);
	cout << num << endl;
	//map<int, int>m2(m);
	//PrintMap(m);

	//map<int, int>m3;
	//m3 = m2;
	//PrintMap(m);
	return 0;
}
#endif 

class Mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

int main()
{
	map<int, int,Mycompare>m;
	m.insert(make_pair(1,10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(1, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int,Mycompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}