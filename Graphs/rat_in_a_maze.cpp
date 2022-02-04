class Solution{
    public:
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    char s[4] = {'D','L','R','U'};
    
    void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &sol,string move, vector<vector<int>> &vis)
    {
        if(i==n-1 && j==n-1)
        {
            sol.push_back(move);
            return;
        }
        for(int k=0;k<4;k++){ 
           if(i+dx[k]<n && j+dy[k]<n && i+dx[k]>=0 && j+dy[k]>=0 && !vis[i+dx[k]][j+dy[k]] && maze[i+dx[k]][j+dy[k]])
           {   
              vis[i][j] = 1;
              solve(i+dx[k],j+dy[k],maze,n,sol,move+s[k],vis);
              vis[i][j] = 0;
           }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> sol;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(maze[0][0]==1)
        {
            solve(0,0,maze,n,sol,"",vis);
        }
        return sol;
    }
};
