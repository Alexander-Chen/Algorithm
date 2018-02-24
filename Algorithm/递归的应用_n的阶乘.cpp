#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
using namespace std;
int jiecheng(int x);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", jiecheng(n));
	}
	return 0;
}
int jiecheng(int x)
{
	if (x == 0 || x == 1)
		return 1;
	else return (x*jiecheng(x-1));
}