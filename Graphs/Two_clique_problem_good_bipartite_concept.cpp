#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis,color;
int n;
int f=0;

void dfs(int cur,int col)
{
    vis[cur]=1;
    color[cur] = col;
    for(auto i: adj[cur])
    {
        if(!vis[i]){
        dfs(i,col^1);
        }
        else if(color[i]==col)
        {
            f=1;
            return;
        }
    }
}

int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;
        vis.resize(n,0);
        adj.resize(n);
        color.resize(n,-1);
        int graph[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>graph[i][j];
        int newgraph[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        newgraph[i][j] = (i!=j)? !graph[i][j]:0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(newgraph[i][j])
        {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        dfs(0,0);
        if(f)
        cout<<"NOT POSSIBLE\n";
        else cout<<"POSSIBLE\n";
    }
    return 0;
}
