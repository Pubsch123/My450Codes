class Solution{
    public:
    string result = "";
    void solve(int j, vector<vector<int>> &ans, vector<int> &vis,stack<int> &s)
    {
       vis[j]=1;
       for(auto i: ans[j])
       {
           if(!vis[i])
           solve(i,ans,vis,s);
       }
       s.push(j);
    }
    
    string findOrder(string s[], int n, int k) {
        vector<int> vis(27,0);
        vector<vector<int>> ans(k);
        int h=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<min((int)s[i].size(),(int)s[i+1].size());j++)
            {
                if(s[i][j] != s[i+1][j])
                {
                    ans[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                    break;
                }
            }
        }
        stack<int> ss;
        for(int i=0;i<k;i++)
        {
            if(!vis[i])
            {
                solve(i,ans,vis,ss);
            }
        }
        while(!ss.empty())
        {
            result += (ss.top()+'a');
            ss.pop();
        }
        // cout<<result<<" ";
        return result;
    }
};
