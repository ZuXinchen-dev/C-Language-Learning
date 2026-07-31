#define _CRT_SECURE_NO_WARNINGS //scanf用

#include<stdio.h>
int main()
{
	printf("Hello World\n");
	return 0;
}


//二维斐波那契数列
int main()
{
	int arr[1001][1001] = { 0 };
	arr[1][1] = 1;
	int n, m=0;
	scanf("%d %d", &n,&m);
	for (int i = 1; i<=n; i ++)
	{
		for (int j = 1; j<=m; j ++)
		{
			if (i == 1 && j == 1)
				arr[i][j] = 1;
			else if (i >= 2 && j == 1)
				arr[i][j] = arr[i - 1][j];
			else if (i == 1 && j >= 2)
				arr[i][j] = arr[i][j - 1];
			else if (i >= 2 && j >= 2)
				arr[i][j] = (arr[i - 1][j] + arr[i][j - 1])%1000000007;//防止整数过大造成溢出，每一步都提前取余
		}
	}
	printf("%d", arr[n][m] );
	return 0;
}


//约瑟夫环
int main()
{
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	int arr[n];
}