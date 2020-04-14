#include<iostream>

using namespace std;

char mine[11][11], touch[11][11];
int result[11][11];
int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,-1,1,1,-1};

void check(int i, int j, int lines)
{
    int x, y;
    for(int k = 0 ; k < 8 ; ++k)
    {
        x = i + dir[k][0];
        y = j + dir[k][1];
        if((x>=0) && (x<lines) && (y>=0) && (y<lines))
            result[x][y]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase, lines;
    cin >> testcase;

    while(testcase--)
    {
        bool gameover = false;
        cin >> lines;

        for(int i = 0 ; i < lines ; ++i)
            for(int j = 0 ; j < lines ; ++j)
                result[i][j] = 0;

        for(int i = 0 ; i < lines ; ++i)
            cin >> mine[i];

        for(int i = 0 ; i < lines ; ++i)
            cin >> touch[i];

        for(int i = 0 ; i < lines ; ++i)
            for(int j = 0 ; j < lines ; ++j)
            {
                if(mine[i][j] == '*')
                    check(i, j, lines);
            }

        for(int i = 0 ; i < lines ; ++i)
        {
            for(int j = 0 ; j < lines ; ++j)
                if(mine[i][j] == '*' && touch[i][j] == 'x')
                    gameover = true;

            if(gameover) break;
        }

        if(gameover)
        {
            for(int i = 0 ; i < lines ; ++i)
            {
                for(int j = 0 ; j < lines ; ++j)
                {
                    if(mine[i][j] == '*')
                        cout << '*';
                    else if(touch[i][j] == 'x')
                        cout << result[i][j];
                    else
                        cout << '.';
                }
                cout << '\n';
            }
        }
        else
        {
            for(int i = 0 ; i < lines ; ++i)
            {
                for(int j = 0 ; j < lines ; ++j)
                {
                    if(touch[i][j] == 'x')
                        cout << result[i][j];
                    else
                        cout << '.';
                }
                cout << '\n';
            }
        }
        if(testcase)
            cout << '\n';
    }
    return 0;
}
