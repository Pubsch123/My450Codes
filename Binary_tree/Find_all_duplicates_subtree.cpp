unordered_map<string,int> mp;
vector<Node*> ans;

string postorder(Node *node){
   if(!node) return ("@");
   string s1 = postorder(node->left);
   string s2 = postorder(node->right);
   
   string res{};
   res = s1 + to_string(node->data) + s2;
   mp[res]++;
   if(mp[res] == 2) ans.push_back(node);
   return (res);
}

vector<Node*> printAllDups(Node* root)
{
   mp.clear();
   ans.clear();
   postorder(root);
   return ans;
}
