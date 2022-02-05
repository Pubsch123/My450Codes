#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n,m;
vector<int> indegree;
vector<int> ans;

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        cin>>n>>m;
        adj.clear();
        indegree.clear();
        indegree.resize(n+2);
        ans.clear();
        ans.resize(n+1);
        adj.resize(n+2);
        queue<int> q;
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++)
	    {
	        for(auto j: adj[i])
	        {
	            indegree[j]++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(!indegree[i])
	        {
	            q.push(i);
	            ans[i] = 1;
	        }
	    }
	    while(!q.empty())
	    {
	        int x = q.front();
	        q.pop();
	        for(auto i: adj[x])
	        {
	            indegree[i]--;
	            if(!indegree[i])
	            {
	                q.push(i);
	                ans[i] = ans[x]+1;
	            }
	        }
	    }
	    for(int i=1;i<=n;i++)
	    cout<<ans[i]<<" ";
	    cout<<"\n";
    }
	return 0;
}
