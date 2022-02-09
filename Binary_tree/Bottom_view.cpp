class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<pair<Node*,int>> q;
        map<int,int> mapp;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> p = q.front();
            q.pop();
            Node* node = p.first;
            int x = p.second;
            mapp[x] = node->data;
            if(node->left)
            q.push({node->left,x-1});
            if(node->right)
            q.push({node->right,x+1});
        }
        for(auto i: mapp)
        ans.push_back(i.second);
        return ans;
    }
};
