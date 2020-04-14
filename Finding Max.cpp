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
    if(leftidx == rightidx)//�]��leaf��, ���j����
    {
        root->max_within = a[leftidx];
        return;
    }
    int mid = (leftidx+rightidx)/2;//middle index
    root->left = new node; //���l�q
    root->right = new node;//�k�l�q
    build(root->left, leftidx, mid);
    build(root->right, mid+1, rightidx);
    root->max_within = max(root->left->max_within, root->right->max_within);//root_maxwithin����left, right�������̤j��
}

void modify(node* &root, int index, int replace_number)
{
    if(root->leftidx == root->rightidx)//�]��leaf��, ���j����
    {
        root->max_within = replace_number;
        return;
    }
    int mid = (root->leftidx+root->rightidx)/2;
    if(index <= mid)//�Q�ק諸�bmid���� or �N�Omid
    {
        modify(root->left, index, replace_number);
    }
    else//�Q�ק諸�bmid�k��
    {
        modify(root->right, index, replace_number);
    }
    root->max_within = max(root->left->max_within, root->right->max_within);//��s�̤j��
}

int find_max(node* &root, int leftidx, int rightidx)//���w�d��left index and right index
{
    if(root->leftidx == leftidx && root->rightidx == rightidx)//���n�����w�d��F, �Ǧ^�̤j��
    {
        return root->max_within;
    }
    int mid = (root->leftidx+root->rightidx)/2;
    if(rightidx <= mid)//�p�Gmid�b���w�d��k
    {
        return find_max(root->left, leftidx, rightidx);
    }
    else if(mid < leftidx)//�p�Gmid�b���w�d��
    {
        return find_max(root->right, leftidx, rightidx);
    }
    else//�p�Gmid�b���w�d��
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
