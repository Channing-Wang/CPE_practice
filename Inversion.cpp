#include<iostream>
#include<algorithm>

#define SIZE 10000000
#define MOD 524287

//��mergesort�ӻ��U�p��inversion number

using namespace std;

int a[SIZE];//��J

long long mergesort(int a[], int temp[], int left, int right);
long long _merge(int a[], int temp[], int left, int mid, int right);

long long MergeSort(int a[], int n)
{
    int *temp = new int[n];//�Ψ��x�smerge�����G
    return mergesort(a, temp, 0, n-1);//�i�J���Ϊ��B�J
}

long long mergesort(int a[], int temp[], int left, int right)//���ΨB�J
{
    long long inv_count = 0;
    if(right > left)//right = left ��ܨS��k���F
    {
        int mid = (left+right)/2;
        inv_count += mergesort(a, temp, left, mid);   //����@��
        inv_count += mergesort(a, temp, mid+1, right);//�k��@��
        inv_count += _merge(a, temp, left, mid+1, right);//���������F�A�}�lmerge
    }
    return inv_count;
}

long long _merge(int a[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    long long inv_count = 0;
    i = left;//���䪺�Y
    j = mid; //�k�䪺�Y
    k = left;//temp���Y
    while((i <= mid-1) && (j <= right))
    {
        if(a[i] <= a[j])//�������p(���`), ������Jtemp
            temp[k++] = a[i++];
        else//�k�����p(�ݭn����l)
        {
            temp[k++] = a[j++];
            inv_count += (mid-i);//inversion ������ = �o�Ӽ�(i)�����mid���ƪ��Ӽ�
        }
    }
    while(i <= mid-1)//j���]��, ���䦳�Ѫ������ɤW
        temp[k++] = a[i++];
    while(j <= right)//�P�z
        temp[k++] = a[j++];
    for(i = left ; i <= right ; ++i)//�Nmerge���G��s��a
        a[i] = temp[i];
    return inv_count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i];
    cout << MergeSort(a, n) % MOD << endl;
    return 0;
}
