#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

void find_ans(vector<int> a, int &A, int &count_, int &pA)
{
    sort(a.begin(), a.end());
    int mid1 = a[(a.size()-1)/2];
    int mid2 = a[a.size()/2];
    A = mid1;

    count_ = 0;
    for(int i = 0 ; i < a.size() ; ++i)
        if(a[i] == mid1 || a[i] == mid2) count_++;

    pA = mid2 - mid1 + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number;
    int A = 0, count_ = 0, pA = 0;
    vector<int> a;
    while(cin >> number)
    {
        for(int i = 0 ; i < number ; ++i)
        {
            a.push_back(0);
            cin >> a[i];
        }
        find_ans(a, A, count_, pA);
        cout << A << ' ' << count_ << ' ' << pA << endl;
        a.clear();
    }
    return 0;
}
