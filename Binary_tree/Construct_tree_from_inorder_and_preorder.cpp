class Solution{
    public:
    
    Node* solve(int in[], int pre[], int n, map<int,int> &mapp, int instart, int inend, int prestart, int preend)
    {
        if(prestart>preend || instart>inend) return NULL;
        Node* root = new Node(pre[prestart]);
        int inroot = mapp[pre[prestart]];
        int range = inroot-instart;
        root->left = solve(in,pre,n,mapp,instart,inroot-1,prestart+1,prestart+range);
        root->right = solve(in,pre,n,mapp,inroot+1,inend,prestart+range+1,preend);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
       map<int,int> mapp;
       for(int i=0;i<n;i++)
       mapp[in[i]]=i;
       Node* root = solve(in,pre,n,mapp,0,n-1,0,n-1);
       return root;
    }
};
