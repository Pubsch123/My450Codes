class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int> dp;
    int solve(Node* root)
    {
       if(!root) return 0;
       if(dp[root]) return dp[root];
       int a = root->data;
       if(root->left){
       a += solve(root->left->left);
       a += solve(root->left->right);
       }if(root->right){
       a += solve(root->right->left);
       a += solve(root->right->right);
       }
       int e = solve(root->left);
       e += solve(root->right);
       return dp[root] = max(e,a);
    }
    
    int getMaxSum(Node *root) 
    {
        return solve(root);
    }
};
