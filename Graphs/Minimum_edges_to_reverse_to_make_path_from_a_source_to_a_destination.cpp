#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<int> dist;
vector<vector<pair<int,int>>> adj;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int src,dst;

int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        adj.resize(n+1);
        vis.resize(n+1,0);
        dist.resize(n+1,INT_MAX);
        cin>>src>>dst;
        dist[src]=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        pq.push({0,src});
        while(!pq.empty())
        {
            int node = pq.top().second;
            vis[node] = 1;
            pq.pop();
            for(auto i: adj[node])
            {
               if(!vis[i.first]){
               int np = i.first;
               int wt = i.second;
               if(dist[node]+wt < dist[np])
                 {
                   dist[np] = dist[node] + wt;
                   pq.push({dist[np],np});
                 }
               }
            }
        }
        cout<<"The Minimum edges to reverse to make path from a source to a destination : "<<dist[dst];
    }
    return 0;
}
