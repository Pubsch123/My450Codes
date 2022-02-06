class Solution
{
	public:
	vector<int> vis;
	vector<vector<int>> adj1;
	stack<int> s;
	void toposort(int cur, vector<int> adj[])
	{
	    vis[cur] = 1;
	    for(auto i: adj[cur])
	    {
	        if(!vis[i])
	        {
	            toposort(i,adj);
	        }
	    }
	    s.push(cur);
	}
	
	void dfs(int cur)
	{
	    vis[cur] = 1;
	    for(auto i: adj1[cur])
	    {
	        if(!vis[i])
	        {
	            dfs(i);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vis.resize(V,0);
        adj1.resize(V);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            toposort(i,adj);
        }
        
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto j: adj[i])
            {
                adj1[j].push_back(i);
            }
        }

        int cnt=0;
        while(!s.empty()){
            int i = s.top();
            s.pop();
            if(!vis[i])
            {
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};
