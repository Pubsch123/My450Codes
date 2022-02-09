class Solution
{
    public: 
    
    void inorder(Node* mirr,vector<Node*> &v)
    {
    if(mirr==NULL)
    return;
    inorder(mirr->left,v);
    v.push_back(mirr);
    inorder(mirr->right,v);
    }
    
    Node * bToDLL(Node *root)
    {
       vector<Node*> v;
      inorder(root,v);
       Node* newnode = newNode(1);
      Node* nptrr = newnode;
      for(int i=0;i<(int)v.size();i++)
      {
          Node* nptr = newNode(v[i]->data);
          newnode->right = nptr;
          nptr->left = newnode;
          newnode = newnode->right;
      }
      newnode = NULL;
      Node* pptr = nptrr;
      nptrr = nptrr->right;
      nptrr->left=NULL;
      return nptrr; 
    }
};
