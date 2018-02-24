#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int s[10];
	int n;
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	for (int j = 0; j < n-1; j++)
	{
		for (int k = n - 2; k >= j; k--)
		{
			if (s[k] > s[k + 1])
				 tmp = s[k];
			s[k]= s[k + 1];
			s[k + 1] = tmp;
		}

	}
	for (int l =0; l <n; l++)
	{
		cout << s[l];
	}
	system("pause");
	return 0;
}