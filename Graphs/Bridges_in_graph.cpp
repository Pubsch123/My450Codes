#include <bits/stdc++.h>
using namespace std;

int n,m,timer=0;
vector<int> tim;
vector<int> mintime;
vector<int> vis;
vector<vector<int>> adj;

void dfs(int cur, int par)
{
    vis[cur]=1;
    tim[cur] = mintime[cur] = timer++;
    for(auto it: adj[cur])
    {
        if(it != par)
        {
            if(vis[it]==0)
            {
                dfs(it,cur);
                mintime[cur] = min(mintime[cur],mintime[it]);
                if(mintime[it] > tim[cur])
                {
                    cout<<cur<<" "<<it<<"\n";
                }
            }else{
                mintime[cur] = min(mintime[cur],tim[it]);
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>n>>m;
       tim.clear();
       mintime.clear();
       vis.clear();
       adj.clear();
       tim.resize(n,-1);
       mintime.resize(n,-1);
       vis.resize(n,0);
       adj.resize(n);
       while(m--)
       {
           int u,v;
           cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       cout<<"The bridges in the Graphs : \n";
       for(int i=0;i<n;i++)
       {
           if(vis[i]==0)
           {
               dfs(i,-1);
           }
       }
    }
    return 0;
}
