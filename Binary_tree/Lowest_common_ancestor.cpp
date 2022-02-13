class Solution
{
    public:
    Node* solve(Node* root, int n1, int n2)
    {
        if(!root) return NULL;
        if(root->data == n1) return root;
        if(root->data == n2) return root;
        Node* lh = solve(root->left,n1,n2);
        Node* rh = solve(root->right,n1,n2);
        if(!lh && rh) return rh;
        if(!rh && lh) return lh;
        if(lh && rh) return root;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       return solve(root,n1,n2);
    }
};
