#include<iostream>

using namespace std;

int k, input[13], com[6];

void print()
{
    cout << com[0];
    for(int i = 1 ; i < 6 ; i++)
    {
        cout << " " << com[i];
    }
    cout << endl;
}

void combin(int index, int number_in_com)
{
    if(number_in_com == 6)
    {
        print();
        return;
    }
    if(index == k) return;
    int j;
    for(j = index ; j < k ; j++)
    {
        com[number_in_com] = input[j];
        combin(j+1, number_in_com+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(;;)
    {
        cin >> k;
        if(k == 0) break;
        for(int i = 0 ; i < k ; i++)
        {
            cin >> input[i];
        }
        combin(0, 0);
    }
    return 0;
}
