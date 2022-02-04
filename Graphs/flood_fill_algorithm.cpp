class Solution {
public:
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};
    bool isvalid(int i, int j, vector<vector<int>> &vis,int m, int n, int oldcolor, vector<vector<int>> &image)
    {
        return i>=0 && i<m && j>=0 && j<n && vis[i][j]==0 && image[i][j]==oldcolor;
    }
    
    void dfs(int i, int j, int color,vector<vector<int>> &image,int m,int n,vector<vector<int>> &vis,int oldcolor)
    {
        vis[i][j]=1;
        image[i][j]=color;
        for(int k=0;k<4;k++)
        {
            if(isvalid(i+dx[k],j+dy[k],vis,m,n,oldcolor,image))
            {
                dfs(i+dx[k],j+dy[k],color,image,m,n,vis,oldcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int oldcolor = image[sr][sc];
        vector<vector<int>> vis(m,vector<int> (n,0));
        dfs(sr,sc,newColor,image,m,n,vis,oldcolor);
        return image;
    }
};
