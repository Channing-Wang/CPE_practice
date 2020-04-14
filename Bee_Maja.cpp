#include<iostream>

#define SIZE 100000

using namespace std;

struct node
{
    int x, y;
};

node p[SIZE+1];

void build()
{
    int indx = 2, num_circle, nowx = 0, nowy = 0, _count;
    p[1].x = 0;
    p[1].y = 0;
    for(num_circle = 1 ; indx <= SIZE ; ++num_circle)
    {
        for(_count = 0 ; _count < num_circle && indx <= SIZE ; ++_count, ++indx)//down
        {
            p[indx].x = nowx;
            p[indx].y = ++nowy;
        }
        for(_count = 0 ; _count < num_circle-1 && indx <= SIZE ; ++_count, ++indx)//left_down -> special
        {
            p[indx].x = --nowx;
            p[indx].y = ++nowy;
        }
        for(_count = 0 ; _count < num_circle && indx <= SIZE ; ++_count, ++indx)//left_up
        {
            p[indx].x = --nowx;
            p[indx].y = nowy;
        }
        for(_count = 0 ; _count < num_circle && indx <= SIZE ; ++_count, ++indx)//up
        {
            p[indx].x = nowx;
            p[indx].y = --nowy;
        }
        for(_count = 0 ; _count < num_circle && indx <= SIZE ; ++_count, ++indx)//right_up
        {
            p[indx].x = ++nowx;
            p[indx].y = --nowy;
        }
        for(_count = 0 ; _count < num_circle && indx <= SIZE ; ++_count, ++indx)//right_down
        {
            p[indx].x = ++nowx;
            p[indx].y = nowy;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int input;
    build();
    while(cin >> input)
        cout << p[input].x << ' ' << p[input].y << endl;
    return 0;
}
