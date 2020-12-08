#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

//将一个2*3维数组的行和列进行交换
#if 0
int main()
{
	int a[2][3] = { {1,2,3},{3,4,6}};
	int b[3][2] = {0};
	int i = 0, j = 0;
	for (i = 0; i <= 1; i++)
	{
		for(j=0;j<=2;j++)
		{
			b[j][i] = a[i][j];
		 }
	}

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif

#if 0
//有一个3*4的矩阵，求里面数的最大值----打擂台法
int main()
{
	int i, j, row = 0, colum = 0, max;
	int a[3][4] = { {1,3,4}, {-2,-4,8}, {9,0,4} };
	max = a[0][0];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				row = i;
				colum = j;
			}
		}
	}
	cout << row << " "<< colum <<" "<< max << endl;
	return 0;
}

int main()
{
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	printf("%d %d %d %d", i,a,b,c);//1 2 2 3
	return 0;
}

class B
{
public:
	B()
	{
		cout << "default constructor" << " ";
	}
	~B()
	{
		cout << "destructed" << " ";
	}
	B(int i) :data(i)
	{
		cout << "constructed by parameter" << data << " ";
	}
private:
	int data;
};

B Play(B b)
{
	return b;
}

int main()
{
	B temp = Play(5);
	return 0;
}

#https://www.nowcoder.com/questionTerminal/01e7bedf5dd2421aa6f879fd8055e51d
class Solution {
public:
	/**
	*
	* @param number string字符串
	* @return string字符串
	*/
	string change(string number) {
		// write code here
		string numbers = number;
		int left = 0;
		int right = numbers.size() - 1;

		while (left < right)
		{
			while (left < right && (numbers[left] - '0') % 2 != 0)
			{
				left++;
			}

			while (left < right && (numbers[right] - '0') % 2 != 0)
			{
				right--;
			}

			char temp = numbers[left];
			numbers[left] = numbers[right];
			numbers[right] = temp;

			left++;
			right--;
		}
		return numbers;
	}
};


#https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		long long sum = 0;
		v.resize(3 * n);
		for (int i = 0; i< (3 * n); i++)
		{
			cin >> v[i];
		}

		std::sort(v.begin(), v.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
}
#endif
