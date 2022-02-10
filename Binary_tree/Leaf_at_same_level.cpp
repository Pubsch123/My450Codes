class Solution{
  public:
    /*You are required to complete this method*/
    set<int> s;
    void height(Node *root, int a)
    {
        if(!root) return;
        if(!root->left && !root->right)
        s.insert(a);
        height(root->left,1+a);
        height(root->right,1+a);
    }
    
    bool check(Node *root)
    {
        height(root,0);
        if(s.size()==1) return true;
        return false;
    }
};
