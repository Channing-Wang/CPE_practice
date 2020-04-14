#include<iostream>
#include<algorithm>

#define SIZE 10000000
#define MOD 524287

//用mergesort來輔助計算inversion number

using namespace std;

int a[SIZE];//輸入

long long mergesort(int a[], int temp[], int left, int right);
long long _merge(int a[], int temp[], int left, int mid, int right);

long long MergeSort(int a[], int n)
{
    int *temp = new int[n];//用來儲存merge的結果
    return mergesort(a, temp, 0, n-1);//進入分割的步驟
}

long long mergesort(int a[], int temp[], int left, int right)//分割步驟
{
    long long inv_count = 0;
    if(right > left)//right = left 表示沒辦法分了
    {
        int mid = (left+right)/2;
        inv_count += mergesort(a, temp, left, mid);   //左邊一個
        inv_count += mergesort(a, temp, mid+1, right);//右邊一個
        inv_count += _merge(a, temp, left, mid+1, right);//全部分完了，開始merge
    }
    return inv_count;
}

long long _merge(int a[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    long long inv_count = 0;
    i = left;//左邊的頭
    j = mid; //右邊的頭
    k = left;//temp的頭
    while((i <= mid-1) && (j <= right))
    {
        if(a[i] <= a[j])//左邊比較小(正常), 直接放入temp
            temp[k++] = a[i++];
        else//右邊比較小(需要換位子)
        {
            temp[k++] = a[j++];
            inv_count += (mid-i);//inversion 的次數 = 這個數(i)之後到mid的數的個數
        }
    }
    while(i <= mid-1)//j先跑完, 左邊有剩的直接補上
        temp[k++] = a[i++];
    while(j <= right)//同理
        temp[k++] = a[j++];
    for(i = left ; i <= right ; ++i)//將merge結果更新到a
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
