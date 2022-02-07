#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> vis;
bool f=0;

void dfs(int cur, int wt)
{
    vis[cur]=1;
    for(auto i: adj[cur])
    {
       if(wt<=0)
       {
           f=1;
           return;
       }
       if(!vis[i.first])
       {
           dfs(i.first,wt-i.second);
       }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       f=0;
       int n,m,ss,wt;
       cin>>n>>m>>ss>>wt;
       vis.clear();
       adj.clear();
       vis.resize(n,0);
       adj.resize(n);
       while(m--)
       {
           int u,v,w;
           cin>>u>>v>>w;
           adj[u].push_back({v,w});
           adj[v].push_back({u,w});
       }
       dfs(ss,wt);
       if(f)
       cout<<"TRUE\n";
       else
       cout<<"FALSE\n";
    }
    return 0;
}
