
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int solve(Node* node)
    {
        if(!node) return 0;
        int lh = solve(node->left);
        if(lh==-1) return -1;
        int rh = solve(node->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    
    bool isBalanced(Node *root)
    {
        if(solve(root)==-1) return false;
        else return true;
    }
};
