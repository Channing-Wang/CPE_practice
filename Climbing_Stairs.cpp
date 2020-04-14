#include<iostream>

using namespace std;

#define N 10000000000000
long long a[101], carry[100];

int main()
{
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    carry[0] = carry[1] = carry[2] = 0;
    for(int i = 3 ; i < 101 ; ++i)
    {
        a[i] = a[i-1] + a[i-2];
        carry[i] = a[i]/N + carry[i-1] + carry[i-2];
        a[i] = a[i]%N;
    }
    int n;
    while(cin >> n)
    {
        if(carry[n])
            cout << carry[n];
        cout << a[n] << '\n';
    }
    return 0;
}
