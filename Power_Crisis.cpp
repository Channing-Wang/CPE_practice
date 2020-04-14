/*
bool check(int m, int n)
{
    int last;
    bool visit[100] = {false};
    for(int i = 0, k = m, c = 0 ; c < n ;)
    {
        if(!visit[i] && (i < n))
        {
            if(k == m)
            {
                last = i;
                c++;
                k = 1;
                visit[i] = true;
            }
            else
            {
                i++;
                k++;
            }
        }
        else
        {
            i++;
            if(i > n)
                i = 0;
        }
    }
    if(last == 12)
        return true;
    return false;
}
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n, m, last;
	while ( cin >> n && n )
	{
	    n--;
		for ( m = 1 ; ; ++m )
        {
			last = 0;
			for ( int j = 1 ; j <= n ; ++ j )
				last = (last+m)%j;
			if ( last == 11 )
			{
				cout << m << '\n';
				break;
			}
		}
	}
	return 0;
}
