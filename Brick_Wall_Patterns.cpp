#include<iostream>

using namespace std;

long long dp[51];

void build_dp()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= 50 ; ++i)
        dp[i] = dp[i-1] + dp[i-2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    build_dp();
    while(cin >> n)
    {
        if(!n) break;
        cout << dp[n] << endl;
    }
    return 0;
}
