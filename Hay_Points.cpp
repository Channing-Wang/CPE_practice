#include<iostream>
#include<map>
#include<cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> dict;
    int m, n;
    string s;
    unsigned int money, total = 0;
    cin >> m >> n;
    while(m--)
    {
        cin >> s >> money;
        dict[s] = money;
    }

    while(n--)
    {
        while(cin >> s && s != ".")
        {
            if(dict[s] > 0) total += dict[s];
        }
        cout << total << endl;
        total = 0;
    }

    return 0;
}
