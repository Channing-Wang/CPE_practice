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

bool compare(L a, L b)//�ۭq���ƧǪk
{
    if(a.c == b.c)//�����W�v(�j��p)�A�p�G�W�v�@��
        return a.letter < b.letter;//�N��letter(�p��j)
    return a.c > b.c;//���W�v(�j��p)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0 ; i < 26 ; ++i)//�إ�A~Z����l
    {
        letters[i].letter = 'A'+i;
        letters[i].c = 0;
    }

    for(int i = 0 ; s[i] != '\0' ; ++i)//�O���X�{�W�v
        letters[s[i]-'A'].c++;

    sort(letters, letters+26, compare);//sort, �H�ۭq���ƧǤ覡compare

    for(int i = 0 ; i < 26 ; ++i)//�L�X���G
    {
        if(letters[i].c)//�p�G�X�{�W�v�O0�N���L
            cout << (int)letters[i].letter << ' ' << letters[i].c << endl;
    }
    return 0;
}
