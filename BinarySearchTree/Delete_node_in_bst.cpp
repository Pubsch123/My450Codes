class Solution {
public:
       
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val>key) root->left = deleteNode(root->left,key);
        else if(root->val<key) root->right = deleteNode(root->right,key);       
        else{
            if(root->left == NULL && root->right == NULL) return NULL;
            if(root->left == NULL) return root->right;
            if(root->right == NULL) return root->left;
            else{
                TreeNode* ptr = root->right;
                while(ptr->left){
                    ptr = ptr->left;
                }
                root->val = ptr->val;
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};
