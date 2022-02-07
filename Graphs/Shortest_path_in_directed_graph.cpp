#include <bits/stdc++.h>
using namespace std;

int n,m,ss;
vector<int> dist;
vector<int> vis;
vector<vector<pair<int,int>>> adj;
stack<int> s;

void topo(int cur)
{
    vis[cur]=1;
    for(auto i: adj[cur])
    {
        if(!vis[i.first])
        topo(i.first);
    }
    s.push(cur);
}

void dfs(int cur)
{
    vis[cur]=1;
    for(auto i: adj[cur])
    {
        if(dist[i.first] > dist[cur] + i.second)
        {
            dist[i.first] = dist[cur] + i.second;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>n>>m>>ss;
       dist.clear();
       vis.clear();
       adj.clear();
       dist.resize(n,INT_MAX);
       dist[ss]=0;
       vis.resize(n,0);
       adj.resize(n);
       while(m--)
       {
           int u,v,w;
           cin>>u>>v>>w;
           adj[u].push_back({v,w});
       }
       for(int i=0;i<n;i++)
       {
           if(!vis[i])
             topo(i);
       }

       while(!s.empty())
       {
           int x = s.top();
           s.pop();
           if(dist[x]!=INT_MAX)
           {
               dfs(x);
           }
       }
       for(int i=0;i<n;i++)
       {
           (dist[i]==INT_MAX)? cout<<"INF " : cout<<dist[i]<<" ";
       }
    }
    return 0;
}
