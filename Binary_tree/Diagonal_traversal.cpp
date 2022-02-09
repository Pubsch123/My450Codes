vector<int> diagonal(Node *root)
{
   queue<Node*> q;
   vector<int> ans;
   if(!root) return ans;
   q.push(root);
   while(!q.empty())
   {
       Node *ptr = q.front();
       q.pop();
       while(ptr)
       {
           if(ptr->left)
           q.push(ptr->left);
           ans.push_back(ptr->data);
           ptr = ptr->right;
       }
   }
   return ans;
}
