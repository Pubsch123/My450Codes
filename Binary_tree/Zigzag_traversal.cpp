
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<Node*> q;
        stack<int> s;
        q.push(root);
        int p=0;
        while(!q.empty())
        {
            int siz = q.size();
            while(siz--){
            Node* node = q.front();
            q.pop();
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
            if(p==0)
            {
                ans.push_back(node->data);
            }else{
                s.push(node->data);
            }
            }
            while(!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
            p ^= 1;
        }
        return ans;
    }
};
