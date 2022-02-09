class Solution {
public:
    bool isleaf(Node* root)
    {
        if(root->left==NULL && root->right == NULL)
        return true;
        return false;
    }
    void lefft(Node* root, vector<int> &ans)
    {
        Node* nptr = root->left;
        while(nptr)
        {
            if(!isleaf(nptr)) ans.push_back(nptr->data);
            if(nptr->left) nptr = nptr->left;
            else nptr = nptr->right;
        }
    }
    void inorder(Node* root, vector<int> &ans)
    {
        if(!root)
        return;
        if(isleaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        inorder(root->left,ans);
        inorder(root->right,ans);
    }
    void rigght(Node* root,vector<int> &ans)
    {
        stack<int> s;
        Node* nptr = root->right;
        while(nptr)
        {
            if(!isleaf(nptr))
                s.push(nptr->data);
            if(nptr->right)
            nptr = nptr->right;
            else 
            nptr = nptr->left;
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        if(!isleaf(root)) ans.push_back(root->data);
        lefft(root,ans);
        inorder(root,ans);
        rigght(root,ans);
        return ans;
    }
};
