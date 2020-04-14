#include<iostream>
#include<string.h>
#include<stdio.h>

#define is_number(ch) ('0' <= ch && ch <= '9')
#define is_al(ch) (('a' <= ch && ch <= 'z')||('A' <= ch && ch <= 'Z'))

using namespace std;

struct node
{
    string word;
    node *next;
};

int main()
{
    node *head;
    char ch = getchar();
    while(true)
    {
        if(is_number(ch))
        {
            if(ch == '0') break;

            int num = 0;
            while(is_number(ch))
            {
                num = num*10 + (ch - '0');
                ch = getchar();
            }

            node *cur = head, *pre = NULL;
            for(int i = 0 ; i < num-1 ; ++i)
            {
                pre = cur;
                cur = cur->next;
            }
            cout << cur->word;

            if(cur != head)
            {
                pre->next = cur->next;
                cur->next = head;
                head = cur;
            }
        }
        else if(is_al(ch))
        {
            string word;
            while(is_al(ch))
            {
                word += ch;
                ch = getchar();
            }
            cout << word;

            node *n = new node;
            n->word = word;
            n->next = head;
            head = n;
        }
        else
        {
            putchar(ch);
            ch = getchar();
        }
    }
    return 0;
}
