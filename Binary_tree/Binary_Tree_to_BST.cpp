class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void inorder(Node* root, vector<int> &ans)
    {
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    void inordernew(Node *root, vector<int> &ans, int &i)
    {
       if(!root) return;
       inordernew(root->left,ans,i);
       root->data = ans[i++];
       inordernew(root->right,ans,i);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        int i=0;
        inordernew(root, ans, i);
        return root;
    }
};
