#include<iostream>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<stdio.h>

using namespace std;

struct Contestant
{
    bool join;
    int contestant_number;
    int sovled_problem;
    int time_penalty;
    int error[10];
};

bool compare(Contestant A, Contestant B)
{
    if(A.sovled_problem > B.sovled_problem) return true;
    if(A.sovled_problem < B.sovled_problem) return false;
    if(A.time_penalty < B.time_penalty) return true;
    if(A.time_penalty > B.time_penalty) return false;
    if(A.contestant_number < B.contestant_number) return true;
    return false;
}

int main()
{
    int testcase;
    string input;
    stringstream ss;
    Contestant C[101];
    while(cin >> testcase)
    {
        getchar();//
        getchar();//為了吃掉空行

        while(testcase--)
        {

            for(int i = 0 ; i < 101 ; ++i)//initialize
            {
                C[i].join = false;
                C[i].sovled_problem = 0;
                C[i].time_penalty = 0;
                C[i].contestant_number = i;
                for(int j = 0 ; j < 10 ; ++j)
                    C[i].error[j] = 0;
            }

            while(getline(cin,input) && input != "")
            {
                int cnumber, problem, time;
                char ch;
                ss.clear();
                ss.str(input);
                ss >> cnumber >> problem >> time >> ch;

                C[cnumber].join = true;
                if(C[cnumber].error[problem] == -1) continue;
                if(ch == 'C')
                {
                    C[cnumber].time_penalty += time+C[cnumber].error[problem]*20;
                    C[cnumber].sovled_problem++;
                    C[cnumber].error[problem] = -1;
                }
                else if(ch == 'I')
                {
                    C[cnumber].error[problem]++;
                }
            }
            sort(C, C+101, compare);
            for(int i = 0 ; i < 101 ; ++i)
            {
                if(C[i].join)
                    cout << C[i].contestant_number << ' ' << C[i].sovled_problem << ' ' << C[i].time_penalty << '\n';
            }
            if(testcase)
                cout << '\n';
        }
    }
    return 0;
}
