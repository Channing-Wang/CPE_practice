#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    unsigned int n;
    while(cin >> n && n != 0)
    {
        double a = sqrt(n);
        if(a == int(a))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}
