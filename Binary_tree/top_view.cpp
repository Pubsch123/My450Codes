class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==nullptr) return ans;
        map<int,int> mapp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> p;
            p = q.front();
            q.pop();
            int x = p.second;
            Node* node = p.first;
            if(mapp.find(x)==mapp.end())
                mapp[x] = node->data;
            if(node->left)
            q.push({node->left,x-1});
            if(node->right)
            q.push({node->right,x+1});
        }
        for(auto i : mapp)
            ans.push_back(i.second);
        return ans;
    }

};
