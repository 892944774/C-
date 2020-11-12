#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

//find 函数的实现
//iterator find(iterator first, iterator last, const& data)
//{
//	while (first != last)
//	{
//		if (*first == data)
//			return first;
//
//		++first;
//	}
//	return last;
//}

#if 0
//https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;

		for (size_t i = 0; i<tokens.size(); ++i)
		{
			string& str = tokens[i];

			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				//str为操作符
				//s.top只是把值赋值给了right，没有取出元素
				int right = s.top();
				s.pop();

				int left = s.top();
				s.pop();

				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;

				case '-':
					s.push(right - left);
					break;

				case '*':
					s.push(right * left);
					break;

				case '/':
					s.push(right / left);
					break;
				}
			}
		}
		return s.top();
	}
};
#endif

#if 0 
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//入栈和出栈元素个数必须相同
		if (pushV.size() != popV.size())
			return false;

		//用s来模拟入栈和出栈的过程
		stack<int> s;
		int outidx = 0;
		int inidx = 0;

		while (outidx < popV.size())
		{
			//栈顶元素和popV中的元素比较，不相等入栈，相等出栈
			while (s.empty() || s.top() != popV[outidx])
			{
				if (inidx < pushV.size())
					s.push(pushV[inidx++]);
				else
					return false;
			}

			//栈顶元素和出栈元素相等，出栈
			s.pop();
			outidx++;
		}
		return true;
	}
};
#endif