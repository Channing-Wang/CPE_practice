#include<iostream>
#include<vector>
#include<limits>

using namespace std;

struct dot
{
    double x, y, tan;
};

double x[101], y[101];
vector<dot> v;

bool found(double x, double y, double tan)
{
    double tan_check = 0;
    for(int i = 0 ; i < v.size() ; ++i)
    {
        if(v[i].x == x)
        {
            tan_check = numeric_limits<double>::max();
        }
        else
        {
            tan_check = (v[i].y-y)/(v[i].x-x);
        }
        if(tan_check == v[i].tan && tan_check == tan)
            return true;
    }
    return false;
}

int main()
{
    int testcase, num_node;
    cin >> testcase;
    while(testcase--)
    {
        cin >> num_node;
        for(int i = 0 ; i < num_node ; ++i)
        {
            cin >> x[i] >> y[i];
        }
        for(int i = 0 ; i < num_node ; ++i)
            for(int j = i+1 ; j < num_node ; ++j)
            {
                dot D;
                D.x = x[j];
                D.y = y[j];
                if(x[i] == x[j])
                {
                    D.tan = numeric_limits<double>::max();
                }
                else
                {
                    D.tan = (y[i]-y[j])/(x[i]-x[j]);
                }
                if(!found(D.x, D.y, D.tan))
                {
                    v.push_back(D);
                }
            }
        cout << v.size() << '\n';
        v.clear();
    }
    return 0;
}
