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

void inorder(Node* mirr)
{
    if(mirr==NULL)
    return;
    inorder(mirr->left);
    cout<<mirr->data<<" ";
    inorder(mirr->right);
}
void preorder(Node* mirr)
{
    if(mirr==NULL)
    return;
    cout<<mirr->data<<" ";
    preorder(mirr->left);
    preorder(mirr->right);
}
void postorder(Node* mirr)
{
    if(mirr==NULL)
    return;
    postorder(mirr->left);
    postorder(mirr->right);
    cout<<mirr->data<<" ";
}

void mirror(Node* node, Node **mirr)
{
    if(node==NULL)
    {
        mirr = NULL;
        return;
    }
    *mirr = new Node(node->data);
    mirror(node->right, &((*mirr)->left));
    mirror(node->left, &((*mirr)->right));
}

int main()
{
    Node* node = new Node(5);
    node->left = new Node(3);
    node->right = new Node(1);
    node->left->left = new Node(4);
    node->left->right = new Node(7);
    Node* mirr = NULL;
    cout<<"original tree: ";
    inorder(node);
    cout<<"\n";
    mirror(node,&mirr);
    cout<<"Mirror tree: ";
    inorder(mirr);
    return 0;
}
