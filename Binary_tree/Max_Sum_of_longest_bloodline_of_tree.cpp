class Solution
{
public:
    pair<int,int> maxsumlongest(Node* root)
    {
       if(!root) return {0,0};
       pair<int,int> p1 = maxsumlongest(root->left);
       pair<int,int> p2 = maxsumlongest(root->right);
       if(p1.first<p2.first) return {p2.first+1,p2.second+root->data};
       if(p1.first>p2.first) return {p1.first+1,p1.second+root->data};
       else return {p1.first+1, max(p1.second,p2.second)+root->data};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int,int> ans = maxsumlongest(root);
        return ans.second;
    }
};
