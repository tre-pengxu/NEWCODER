/*
测试用例：
7 2 6 9 0 4 0 5 1
0 8 0 6 0 7 4 3 2
3 4 1 0 8 5 0 0 9
0 5 2 4 6 8 0 0 7
0 3 7 0 0 0 6 8 0
0 9 0 0 0 3 0 1 0
0 0 0 0 0 0 0 0 0
9 0 0 0 2 1 5 0 0
8 0 0 3 0 0 0 0 0

0 9 5 0 2 0 0 6 0
0 0 7 1 0 3 9 0 2
6 0 0 0 0 5 3 0 4
0 4 0 0 1 0 6 0 7
5 0 0 2 0 7 0 0 9
7 0 3 0 9 0 0 2 0
0 0 9 8 0 0 0 0 6
8 0 6 3 0 2 1 0 5
0 5 0 0 7 0 2 8 3
*/

#include <iostream>
using namespace std;

int num[9][9]; //放置九宫格数据
int row[9][10]; //若row[i][k]值为1，表示i行已经有数字k存在(i的取值范围[0~8],k的取值范围[1~9])
int column[9][10]; //若column[j][k]值为1，表示j列已经有数字k存在
int block[9][10]; //若block[b][k]值为1，表示b块已经有数字k存在

void init()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> num[i][j];
			int value = num[i][j];
			int b = (i / 3) * 3 + (j / 3);
			if (value != 0)
				row[i][value] = column[j][value] = block[b][value] = 1;
			else
				row[i][value] = column[j][value] = block[b][value] = 0;
		}
	}
}

void output()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
}

void search(int n)
{
	if (n == 81) //边界条件
	{
		output();
		return;
	}
	int r = n / 9; //行号row
	int c = n % 9; //列号column
	int b = (r / 3) * 3 + (c / 3); //块号block

	if (num[r][c] != 0)
		search(n + 1);
	else{
		for (int k = 1; k <= 9; k++)
		{
			if (row[r][k] || column[c][k] || block[b][k]) //检查行、列和宫内是否冲突
				continue;
			else{ //给num[r][c]赋值k
				num[r][c] = k;
				row[r][k] = column[c][k] = block[b][k] = 1;
				search(n + 1); //回溯
				num[r][c] = 0;
				row[r][k] = column[c][k] = block[b][k] = 0;
			}
		}
	}
}

int main()
{	
	init();	
	search(0);
    return 0;
}