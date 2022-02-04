 class Solution{
 public:
    // Function to detect cycle in an undirected graph.
    //  bool cycle_detect(vector<int> adj[],int s,vector<bool> &vis,int parent){
    //     vis[s] = 1;
    //     for(int u : adj[s]){
    //         if(vis[u]==false){
    //             if(cycle_detect(adj,u,vis,s)==true){
    //                 return true;
    //             }
    //         }
    //         else if(u!=parent){
    //             return true;
    //         }
    //     }
    // }
    bool cycle_detect(vector<int> adj[],int s,vector<bool> &vis,int parent){
       queue<pair<int,int>> q;
       q.push({s,-1});
       vis[s]=1;
       while(!q.empty()){
       int x = q.front().first;
       int y = q.front().second;
       for(auto i: adj[x])
           {
               if(!vis[i])
               {
                   vis[i]=1;
                   q.push({i,x});
               }else if(vis[i] && y!=i){
                    return true;
               }
           }
           q.pop();
       }
       return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                if(cycle_detect(adj,i,visited,-1)) return true;
            }
        }
        return false;
    }
  };
