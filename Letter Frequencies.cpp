#include<iostream>
#include<algorithm>

using namespace std;

struct L
{
    char letter;
    int c;
};

char s[1001];
L letters[26];

bool compare(L a, L b)//自訂的排序法
{
    if(a.c == b.c)//先比頻率(大到小)，如果頻率一樣
        return a.letter < b.letter;//就比letter(小到大)
    return a.c > b.c;//比頻率(大到小)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0 ; i < 26 ; ++i)//建立A~Z的格子
    {
        letters[i].letter = 'A'+i;
        letters[i].c = 0;
    }

    for(int i = 0 ; s[i] != '\0' ; ++i)//記錄出現頻率
        letters[s[i]-'A'].c++;

    sort(letters, letters+26, compare);//sort, 以自訂的排序方式compare

    for(int i = 0 ; i < 26 ; ++i)//印出結果
    {
        if(letters[i].c)//如果出現頻率是0就不印
            cout << (int)letters[i].letter << ' ' << letters[i].c << endl;
    }
    return 0;
}
