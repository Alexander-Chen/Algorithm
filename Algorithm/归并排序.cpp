#include <iostream>  

using namespace std;
int a[10000];
int temp[10000];

void MergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;  //迭代遍历左有序  
	int j = mid + 1;  //迭代遍历右有序  
	int m = mid, n = last;
	int k = 0;      //迭代临时数组  

					//左边或者右边遍历完毕  
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//若是右边遍历完毕  
	while (i <= m)
		temp[k++] = a[i++];
	//若是左边遍历完毕  
	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
//first,last为归并数组的下标  
void MergeSort(int a[], int first, int last, int temp[])
{
	if (first < last)        //递归边界  
	{
		int mid = (first + last) / 2;       //divide  
		MergeSort(a, first, mid, temp); //conqure左边，左边有序  
		MergeSort(a, mid + 1, last, temp);//conqure右边，右边有序  
		MergeArray(a, first, mid, last, temp);//归并两个有序表  
	}
}
int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MergeSort(a, 0, n - 1, temp);
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	getchar();
	getchar();
	return 0;
}