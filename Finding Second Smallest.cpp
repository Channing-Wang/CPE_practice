#include<iostream>
#include<algorithm>
#include<climits>

#define SIZE 2000000

int a[SIZE];

using namespace std;

struct node
{
    int leftidx, rightidx;
    int min1, min2;
    node *left = NULL, *right = NULL;
};

void second_min(node* &root, node* left, node* right);
void build(node* &root, int leftidx, int rightidx);
void find_second_min(node* &root, node* &ans, int leftidx, int rightidx);

void build(node* &root, int leftidx, int rightidx)
{
    root->leftidx = leftidx;
    root->rightidx = rightidx;
    if(leftidx == rightidx)//跑到leaf啦, 遞迴結束
    {
        root->min1 = a[leftidx];
        root->min2 = INT_MAX;
        return;
    }
    int mid = (leftidx+rightidx)/2;//middle index
    root->left = new node; //左子段
    root->right = new node;//右子段
    build(root->left, leftidx, mid);
    build(root->right, mid+1, rightidx);
    second_min(root, root->left, root->right);//root_min2紀錄left, right之間的最小值
}

void second_min(node* &root, node* left, node* right)
{
    if(left->min1 < right->min1)
    {
        root->min1 = left->min1;
        if(left->min2 < right->min1)
            root->min2 = left->min2;
        else
            root->min2 = right->min1;
    }
    else
    {
        root->min1 = right->min1;
        if(right->min2 < left->min1)
            root->min2 = right->min2;
        else
            root->min2 = left->min1;
    }
}

void find_second_min(node* &root, node* &ans, int leftidx, int rightidx)//指定範圍的left index and right index
{
    if(root->leftidx == leftidx && root->rightidx == rightidx)//找到要的指定範圍了, 傳回第二最小值
    {
        node* temp = new node;
        temp->min1 = ans->min1;
        temp->min2 = ans->min2;
        second_min(ans, root, temp);
        delete temp;
        return;
    }
    int mid = (root->leftidx+root->rightidx)/2;
    if(rightidx <= mid)//如果mid在指定範圍右
    {
        return find_second_min(root->left, ans, leftidx, rightidx);
    }
    else if(mid < leftidx)//如果mid在指定範圍左
    {
        return find_second_min(root->right, ans, leftidx, rightidx);
    }
    else//如果mid在指定範圍中
    {
        find_second_min(root->left, ans, leftidx, mid);
        find_second_min(root->right, ans, mid+1, rightidx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int num, command;
    cin >> num >> command;
    for(int i = 0 ; i < num ; ++i)
        cin >> a[i];
    node* root = new node;
    build(root, 0, num-1);
    node* ans = new node;//用來記錄min, second min
    int j, k;
    while(command--)
    {
        cin >> j >> k;
        ans->min1 = INT_MAX;
        ans->min2 = INT_MAX;
        find_second_min(root, ans, j, k);
        cout << ans->min2 << endl;
    }
    return 0;
}
