#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
};

int ans=0;
int maxsubtreesum(Node* root)
{
    if(!root) return 0;
    int cur = 0;
    int lh = maxsubtreesum(root->left);
    int rh = maxsubtreesum(root->right);
    cur = root->data + lh+rh;
    ans = max(ans,cur);
    return cur;
}

int main()
{
    Node* node = new Node(5);
    node->left = new Node(3);
    node->right = new Node(-2);
    node->left->left = new Node(6);
    node->left->right = new Node(7);
    node->right->left = new Node(-12);
    node->right->right = new Node(7);
    maxsubtreesum(node);
    cout<<ans;
    return 0;
}
