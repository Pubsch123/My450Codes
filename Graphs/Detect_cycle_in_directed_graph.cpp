class Solution{
public:
    // Function to detect cycle in a directed graph.
    // bool dfs(int cur, int vis[], int check[], vector<int> adj[])
    // {
    //     vis[cur]=1;
    //     check[cur]=1;
    //     for(auto i: adj[cur])
    //     {
    //       if(!vis[i])
    //       {
    //           if(dfs(i,vis,check,adj)) return true;
    //       }else if(check[i])
    //       return true;
    //     }
    //     check[cur]=0;
    //     return false;
    // }

    bool isCyclic(int V, vector<int> adj[]) {
          int vis[V],check[V];
          memset(vis,0,sizeof(vis));
          memset(check,0,sizeof(check));
          for(int ii=0;ii<V;ii++)
          {
               for(auto i: adj[ii])
                {
                  check[i]++;
                }   
          }
         queue<int> que;
        for(int i=0;i<V;i++)
        {
            if(!check[i])
            que.push(i);
        }
        while(!que.empty())
        {
            int x=que.front();
            for(auto i: adj[x])
            {
                check[i]--;
                if(!check[i])
                {
                    que.push(i);
                }
            }
            que.pop();
        }
         for(int i=0;i<V;i++)
        {
            if(check[i])
            return true;
        }
        return false;
    }
 };
