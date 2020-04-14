#include<iostream>
#include<algorithm>

#define SIZE 300000
#define SMALLEST -1000000000

int a[SIZE];

using namespace std;

struct node
{
    int leftidx, rightidx;
    int max_within;
    node *left = NULL, *right = NULL;
};

void build(node* &root, int leftidx, int rightidx)
{
    root->leftidx = leftidx;
    root->rightidx = rightidx;
    if(leftidx == rightidx)//跑到leaf啦, 遞迴結束
    {
        root->max_within = a[leftidx];
        return;
    }
    int mid = (leftidx+rightidx)/2;//middle index
    root->left = new node; //左子段
    root->right = new node;//右子段
    build(root->left, leftidx, mid);
    build(root->right, mid+1, rightidx);
    root->max_within = max(root->left->max_within, root->right->max_within);//root_maxwithin紀錄left, right之間的最大值
}

void modify(node* &root, int index, int replace_number)
{
    if(root->leftidx == root->rightidx)//跑到leaf啦, 遞迴結束
    {
        root->max_within = replace_number;
        return;
    }
    int mid = (root->leftidx+root->rightidx)/2;
    if(index <= mid)//想修改的在mid左邊 or 就是mid
    {
        modify(root->left, index, replace_number);
    }
    else//想修改的在mid右邊
    {
        modify(root->right, index, replace_number);
    }
    root->max_within = max(root->left->max_within, root->right->max_within);//更新最大值
}

int find_max(node* &root, int leftidx, int rightidx)//指定範圍的left index and right index
{
    if(root->leftidx == leftidx && root->rightidx == rightidx)//找到要的指定範圍了, 傳回最大值
    {
        return root->max_within;
    }
    int mid = (root->leftidx+root->rightidx)/2;
    if(rightidx <= mid)//如果mid在指定範圍右
    {
        return find_max(root->left, leftidx, rightidx);
    }
    else if(mid < leftidx)//如果mid在指定範圍左
    {
        return find_max(root->right, leftidx, rightidx);
    }
    else//如果mid在指定範圍中
    {
        return max(find_max(root->left, leftidx, mid), find_max(root->right, mid+1, rightidx));
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
    int i, j, k;
    for(int t = 0 ; t < command ; ++t)
    {
        cin >> i >> j >> k;
        if(i == 1)
            modify(root, j, k);
        else
            cout << find_max(root, j, k) << endl;
    }
    return 0;
}
