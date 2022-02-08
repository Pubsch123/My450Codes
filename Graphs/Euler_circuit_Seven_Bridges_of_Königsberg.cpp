#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
int n,m;

void dfs(int cur)
{
   vis[cur]=1;
   for(auto i: adj[cur])
   {
      if(!vis[i])
      {
          dfs(i);
      }
   }
}

bool Connected(){
    int u=-1;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>0)
        {
            u = i;
            break;
        }
    }
    if(u==-1) return true;
    dfs(u);
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && adj[i].size()>0)
        {
            return false;
        }
    }
    return true;
}

int Euler()
{
    if(!Connected())
    return 1;
    int odd = 0;
    for(int i=0;i<=n;i++)
    {
        if(adj[i].size()&1)
        odd++;
    }
    return odd;
}

int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n>>m;
        adj.resize(n+1);
        vis.resize(n+1,0);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int result = Euler();
        if(result==2)
        {
           cout<<"SemiConnected Euler Circuit\n"; 
        }else if(result==0)
        {
           cout<<"Euler Circuit\n"; 
        }else 
        {
           cout<<"Not a Euler Circuit\n"; 
        }
    }
    return 0;
}
