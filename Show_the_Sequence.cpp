#include<iostream>
#include<cstring>

using namespace std;

long long a[50];

void process(string s, int indx)
{
    char p;
    int i, sign = 1;
    long long m = 0;
    for(i = indx ; s[i] ; ++i)
    {
        if(s[i] == '-')
            sign = -1;
        else if(s[i] >= '0' && s[i] <= '9')
            m = m*10 + s[i] - '0';
        else
        {
            p = s[i];
            break;
        }
    }

    m *= sign;

    if(p == '+')
    {
        process(s, i+2);
        long long old = a[0];
        a[0] = m;
        for(int j = 1 ; j < 50 ; ++j)
        {
            long long temp = a[j-1] + old;
            old = a[j];
            a[j] = temp;
        }
    }
    else if(p == '*')
    {
        process(s, i+2);
        a[0] = a[0]*m;
        for(int j = 1 ; j < 50 ; ++j)
            a[j] = a[j] * a[j-1];
    }
    else
    {
        for(int j = 0 ; j < 50 ; ++j)
            a[j] = m;
    }
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    string s;
    int N;

    while(cin >> s >> N)
    {
        process(s, 1);
        for(int i = 0 ; i < N ; ++i)
        {
            cout << a[i];
            cout << ((i == N-1) ? '\n' : ' ');
        }
    }
    return 0;
}
