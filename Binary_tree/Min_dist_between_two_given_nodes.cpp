class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root, int n1, int n2)
    {
        if(!root) return NULL;
        if(root->data == n1) return root;
        if(root->data == n2) return root;
        Node* lh = lca(root->left,n1,n2);
        Node* rh = lca(root->right,n1,n2);
        if(!lh && rh) return rh;
        if(!rh && lh) return lh;
        if(lh && rh) return root;
    }
    int newsolve(Node* root, int a, int dep)
    {
        if(!root) return INT_MAX;
        if(root->data==a) return dep;
        int lh = newsolve(root->left,a,dep+1);
        int rh = newsolve(root->right,a,dep+1);
        return min(lh,rh);
    }
    int findDist(Node* root, int a, int b) {
        Node* llca = lca(root,a,b);
        int h1 = newsolve(llca,a,0);
        int h2 = newsolve(llca,b,0);
        return h1+h2;
    }
};
