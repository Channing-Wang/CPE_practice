#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
vector<ll> a;

int main()
{
    ll n, result;
    while(cin >> n && n)
    {
        ll temp = n;
        result = n;
        for(int i = 2 ; i <= temp ; ++i)
        {
            bool yes = false;
            while(!(temp%i))
            {
                temp /= i;
                yes = true;
            }
            if(yes)
                a.push_back(i);
        }
        for(int i = 0 ; i < a.size() ; ++i)
        {
            result *= (a[i]-1);
            result /= a[i];
        }
        cout << result << '\n';
        a.clear();
    }
    return 0;
}
