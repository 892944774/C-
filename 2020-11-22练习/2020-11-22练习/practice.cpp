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
#endif

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