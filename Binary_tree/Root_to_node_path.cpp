class Solution{
public:
bool root_to_node_path(Node* root, int a, vector<int> &ans)
    {
        if(!root)
        {
           return false;
        }
        ans.push_back(root->data);
        if(root->data==a) return true;
        bool f1 = root_to_node_path(root->left,a,ans);
        bool f2 = root_to_node_path(root->right,a,ans);
        if(!f1 && !f2) {
            ans.pop_back();
            return false;
        }
        else 
        return true;
    }
    vector<int> Root_to_node(Node* root, int a, int b) {
        vector<int> ans;
        if(root==NULL) return ans;
        root_to_node_path(llca,a,ans);
        return ans;
    }
};
