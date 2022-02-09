class Solution
{
    public:
    bool flag;
    int solve(Node* root)
    {
        int a=0,b=0;
        if(root->left)
        a = solve(root->left);
        if(root->right)
        b = solve(root->right);
        if((root->left) || (root->right)) 
        {
            if(root->data != a+b) flag=false;
        }
        return a+b+root->data;
    }
    bool isSumTree(Node* root)
    {
        flag=true;
        solve(root);
        return flag;
    }
};
