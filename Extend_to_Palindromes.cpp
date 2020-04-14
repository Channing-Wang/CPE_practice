#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/*
void palindrom(string s)
{
    bool yes = true;
    int mid = s.size()/2;
    if(s.size()&1)
    {
        for(int i = mid-1, j = mid+1 ; s[j] ; --i, ++j)
            if(s[i] != s[j])
            {
                yes = false;
                break;
            }
    }
    else
    {
        for(int i = mid-1, j = mid ; s[j] ; --i, ++j)
            if(s[i] != s[j])
            {
                yes = false;
                break;
            }
    }
    if(yes)
        cout << s << '\n';
    else
    {
        int i, j, k, center1 = s.size()-1, center2 = s.size()-1;
        string ss = s + s;
        for(k = s.size()-2 ; k >= mid ; --k)
        {
            for(i = k-1, j = k+1 ; s[j] ; --i, ++j)
            {
                if(s[i] != s[j])
                    break;
            }
            if(!s[j])
                center1 = k;
        }
        for(k = s.size()-2 ; k >= mid ; --k)
        {
            for(i = k, j = k+1 ; s[j] ; --i, ++j)
            {
                if(s[i] != s[j])
                    break;
            }
            if(!s[j])
                center2 = k;
        }
        if(center2 < center1)
        {
            for(i = center2, j = center2+1 ; i >= 0 ; --i, ++j)
                ss[j] = ss[i];
        }
        else
        {
            for(i = center1-1, j = center1+1 ; i >= 0 ; --i, ++j)
                ss[j] = ss[i];
        }
        ss[j] = '\0';
        for(int n = 0 ; ss[n] ; ++n)
            cout << ss[n];
        cout << '\n';
    }
}

int main()
{
    string s;
    while(cin >> s)
    {
        palindrom(s);
    }
    return 0;
}
*/

int fail[100000] = {-1};

int main()
{
    string s;
    string rs;
    while(cin >> rs)
    {
        int i, j;
        s = rs;
        reverse(rs.begin(), rs.end());
        for(i = 1, j = -1 ; i < rs.size() ; ++i)
        {
            while(j >= 0 && rs[j+1] != rs[i]) j = fail[j];
            if(rs[j+1] == rs[i]) j++;
            fail[i] = j;
        }
        for(i = 0, j = -1 ; i < s.size() ; ++i)
        {
            while(j >= 0 && rs[j+1] != s[i]) j = fail[j];
            if(rs[j+1] == s[i]) j++;
        }
        cout << s << &rs[j+1] << '\n';
    }
    return 0;
}
