#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

#define isdigit(ch) (ch >= '0' && ch <= '9')

using namespace std;

int main()
{
    int n, m, run_time = 0;

    while(cin >> n && n)
    {
        run_time++;
        string input, standard = "", teamoutput = "";
        bool ac = false, p_error = false;

        getchar();
        for(int i = 0 ; i < n ; ++i)
        {
            getline(cin, input);
            standard += input;
            if(i) standard += '\n';
        }

        cin >> m;
        getchar();
        for(int i = 0 ; i < n ; ++i)
        {
            getline(cin, input);
            teamoutput += input;
            if(i) teamoutput += '\n';
        }

        if(standard == teamoutput)
        {
            printf("Run #%d: Accepted\n", run_time);
            continue;
        }

        for(int i = 0 ; i < standard.size() ; ++i)
            if(!isdigit(standard[i])) standard.erase(i,1), i--;
        for(int i = 0 ; i < teamoutput.size() ; ++i)
            if(!isdigit(teamoutput[i])) teamoutput.erase(i,1), i--;

        if(standard == teamoutput)
        {
            printf("Run #%d: Presentation Error\n", run_time);
            continue;
        }

        printf("Run #%d: Wrong Answer\n", run_time);
    }
    return 0;
}
