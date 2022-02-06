class Solution {
public:
    bool f=0;
    void dfs(int col, int cur, vector<int> &vis, vector<int> adj[], vector<int> &color)
    {
        vis[cur] = 1;
        color[cur] = col;
        for(auto i: adj[cur])
        {
            if(!vis[i])
            {
                dfs(col^1,i,vis,adj,color);
            }else{
                if(color[i] == col)
                {
                    f=1;
                    return;
                }
            }
        }
    }
    
	bool isBipartite(int n, vector<int>adj[]){
	    vector<int> color(n,-1);
	    vector<int> vis(n,0);
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(0,i,vis,adj,color);
	        }
	    }
	    if(f)
	    return false;
	    return true;
	}
};
