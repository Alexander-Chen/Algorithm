#include <iostream>  

using namespace std;
int a[10000];
int temp[10000];

void MergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;  //��������������  
	int j = mid + 1;  //��������������  
	int m = mid, n = last;
	int k = 0;      //������ʱ����  

					//��߻����ұ߱������  
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//�����ұ߱������  
	while (i <= m)
		temp[k++] = a[i++];
	//������߱������  
	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
//first,lastΪ�鲢������±�  
void MergeSort(int a[], int first, int last, int temp[])
{
	if (first < last)        //�ݹ�߽�  
	{
		int mid = (first + last) / 2;       //divide  
		MergeSort(a, first, mid, temp); //conqure��ߣ��������  
		MergeSort(a, mid + 1, last, temp);//conqure�ұߣ��ұ�����  
		MergeArray(a, first, mid, last, temp);//�鲢���������  
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