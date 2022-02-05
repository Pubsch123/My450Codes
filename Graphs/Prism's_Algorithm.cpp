int fnc(vector<int>wt,vector<int>vis,int v){
    int weight=INT_MAX,node;
    for(int i=0;i<v;i++){
        if(!vis[i] && wt[i]<weight){
            weight=wt[i];
            node=i;
        }
    }
    return node;
}
   int spanningTree(int v, vector<vector<int>> adj[])
   {
       vector<int>vis(v,0),wt(v,INT_MAX);
       wt[0]=0;
       int cnt=v-1;
       while(cnt--){
               int curr=fnc(wt,vis,v);
               vis[curr]=1;
               for(auto it:adj[curr]){
                   int vertex=it[0];
                   int weight=it[1];
                   if(!vis[vertex] && wt[vertex]>weight)
                       wt[vertex]=weight;
               }
       }
       int sum=0;
       for(int x : wt)sum+=x;
       return sum;
   }
