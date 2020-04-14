#include<iostream>
#include<stdio.h>

using namespace std;

long long a[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casenumber, casetime = 1;
    while(cin >> casenumber)
    {
        for(int i = 0 ; i < casenumber ; ++i)
        {
            cin >> a[i];
        }
        long long maxpro = 0;
        for(int i = 0 ; i < casenumber ; ++i)
        {
            long long p = 1;
            for(int j = i ; j < casenumber ; ++j)
            {
                p *= a[j];
                if(p > maxpro) maxpro = p;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", casetime++, maxpro);
    }
    return 0;
}
