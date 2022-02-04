class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8] = {-1,-1,-2,-2,1,1,2,2};
    int dy[8] = {-2,2,-1,1,-2,2,-1,1};

	int minStepToReachTarget(vector<int>&K,vector<int>&T,int n)
	{
	   vector<int> ans;
	   vector<vector<int>> vis(n,vector<int>(n,0));
	   int kinx = K[0];
	   int kiny = K[1];
	   int tarx = T[0];
	   int tary = T[1];
	   queue<pair<int,int>> q;
	   q.push({kinx-1,kiny-1});
	   if(kinx==tarx && kiny==tary)
        {
            return 0;
        }
        while(!q.empty())
        {
           int x = q.front().first;
           int y = q.front().second;
           for(int k=0;k<8;k++)
           {
            if(x+dx[k] < n && y+dy[k] < n && x+dx[k] >= 0 && y+dy[k] >= 0 && !vis[x+dx[k]][y+dy[k]])
            {
                vis[x+dx[k]][y+dy[k]] = vis[x][y] + 1;
                q.push({x+dx[k],y+dy[k]});
            }
           }
           q.pop();
        }
        return vis[tarx-1][tary-1];
	}
};
