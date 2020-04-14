#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

char dungeon[30][30][30];

struct Point
{
    int l, r, c;
    int d;
    Point(int level, int row, int column, int distance)
    {
        l = level;
        r = row;
        c = column;
        d = distance;
    }
};

int BFS_dungeon(int start_l, int start_r, int start_c, int L, int R, int C)
{
    queue<Point> Q;
    Q.push(Point(start_l, start_r, start_c, 0));

    while(!Q.empty())
    {
        Point a = Q.front();
        Q.pop();

        if(a.l >= L || a.r >= R || a.c >= C || a.l < 0 || a.r < 0 || a.c < 0)
            continue;
        if(dungeon[a.l][a.r][a.c] == '#')
            continue;
        if(dungeon[a.l][a.r][a.c] == 'E')
            return a.d;

        dungeon[a.l][a.r][a.c] = '#';
        Q.push(Point(a.l-1, a.r, a.c, a.d+1));
        Q.push(Point(a.l+1, a.r, a.c, a.d+1));
        Q.push(Point(a.l, a.r-1, a.c, a.d+1));
        Q.push(Point(a.l, a.r+1, a.c, a.d+1));
        Q.push(Point(a.l, a.r, a.c-1, a.d+1));
        Q.push(Point(a.l, a.r, a.c+1, a.d+1));
    }

    return 0;
}

int main()
{
    int L, R, C;
    char item;
    while((cin >> L >> R >> C) && L && R && C)
    {
        int start_l = 0, start_r = 0, start_c = 0;
        for(int k = 0 ; k < L ; ++k)
            for(int i = 0 ; i < R ; ++i)
                for(int j = 0 ; j < C ; ++j)
                    dungeon[k][i][j] = '\0';
        for(int k = 0 ; k < L ; ++k)
            for(int i = 0 ; i < R ; ++i)
                for(int j = 0 ; j < C ; ++j)
                {
                    cin >> dungeon[k][i][j];
                    if(dungeon[k][i][j] == 'S')
                    {
                        start_l = k;
                        start_r = i;
                        start_c = j;
                        dungeon[k][i][j] = '.';
                    }
                }

        int result = BFS_dungeon(start_l, start_r, start_c, L, R, C);
        if(result)
            printf("Escaped in %d minute(s).\n", result);
        else
            printf("Trapped!\n");
    }
    return 0;
}
