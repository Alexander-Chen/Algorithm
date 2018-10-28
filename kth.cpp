#include<iostream>
#include<string.h>
#include<memory.h>
#include<algorithm>
using namespace std;
int mat[101][101][101];
//memset(mat,0, sizeof(mat));
bool cmp(int a, int b)
{
	return a > b;
}//从大到小排序

int dp(int m, int n,int k)
{
	int i, j;

	for (i = 1; i < m; i++)
	{
		mat[i][0][0] = mat[i][0][0] + mat[i - 1][0][0];
	}
	for (j = 1; j < n; j++)
	{
		mat[0][j][0] = mat[0][j][0] + mat[0][j - 1][0];
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			{
				//DP[i][j][s] = DP[i - 1][j][s-1] + mat[i][j], DP[i][j - 1][s-1] + mat[i][j];
				sort(mat[i - 1][j], mat[i - 1][j] + k, cmp);
				sort(mat[i][j - 1], mat[i][j - 1] + k, cmp);
				int yb = mat[i][j][0];
				merge(mat[i - 1][j], mat[i - 1][j] + k, mat[i][j - 1], mat[i][j - 1] + k, mat[i][j], cmp);
				for (int p = 0; p < k; p++)
				{
					mat[i][j][p] = mat[i][j][p] + yb;
				}
				
			}	
		}
		
	}
	for (int l = 0; l < k-1; l++)
	{
		cout << mat[m - 1][n - 1][l]<<' ';
	}
	cout << mat[m - 1][n - 1][k - 1] << endl;
	return 0;
}
int main()
{
	memset(mat, 0, sizeof(mat));
	int m, n;
	cin >> m >> n;
	int k;
	cin >> k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j][0];
		}
	}
	dp(m, n,k);
	//system("pause");
	return 0;
}
