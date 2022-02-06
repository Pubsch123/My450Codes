class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> a(n*n,0);
        int k=0;
        int f=0;
        for(int i=n-1;i>=0;i--)
        {
            if(f==0)
            {
                for(int j=0;j<n;j++)
                {
                    a[k++] = board[i][j];
                }
                f=1;
            }else{
                for(int j=n-1;j>=0;j--)
                {
                    a[k++] = board[i][j];
                }
                f=0;
            }
        }
        int start = 0;
        int totalstep = 0;
        queue<int> q;
        vector<int> vis(n*n,0);
        if(a[0]>-1)
            start = a[0]-1;
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        { 
            int cursize = q.size();
            while(cursize--)
            {
                int cur = q.front();
                q.pop();
                if(cur == n*n-1)
                    return totalstep;
                for(int i = cur+1; i <= min(n*n-1,cur+6); i++)
                {
                    int next = i;
                    if(a[i]>-1)
                        next = a[i]-1;
                    if(vis[next]==0)
                    {
                        vis[next]=1;
                        q.push(next);
                    }
                }
            }
            totalstep++;
        }
        return -1;
    }
};
