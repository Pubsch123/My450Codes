class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& list) {
        int n = list.size();
        map<string,vector<string>> adj;
        vector<int> vis(n+2,0);
        bool flag=1;
        int k=-1;
        for(int i=0;i<n;i++)
        {
            if(list[i] == endWord){
                flag=0; break;}
            if(list[i] == beginWord)
            {
                k=i;
            }
        }
        if(flag) return 0;
        queue<string> que;
        que.push(beginWord);
        if(k>-1)
            vis[k]=1;
        while(!que.empty())
        {
            string ss = que.front();
            for(int i=0;i<n;i++)
            {
                int cnt=0;
                if(vis[i]==0){
                  for(int j=0;j<(int)ss.size();j++)
                    {
                      if(ss[j] != list[i][j])
                       cnt++;
                    }
                   if(cnt==1)
                   {
                    adj[ss].push_back(list[i]);
                    que.push(list[i]);
                     vis[i] = 1;
                   }
                }
            }
            que.pop();
        }
        for(auto i: adj)
        {
            cout<<i.first<<"--> ";
            for(auto j: i.second)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        for(int i=0;i<n+2;i++)  vis[i]=0;
        que.push(beginWord);
        queue<string> que1;
        int cnt=0;
        string ss;
        while(!que.empty()  ||  !que1.empty()){
        bool f=0,f1=0;
        while(!que.empty())
        {
            f=1;
            ss = que.front();
            if(ss == endWord)
            break;
            for(auto i : adj[ss])
            {
                que1.push(i);
            }
            que.pop();
        }
            if(f)
            cnt++;
            if(ss == endWord)
            break;
        while(!que1.empty()){
            f1=1;
            ss = que1.front();
            if(ss == endWord)
            break;
            for(auto i : adj[ss])
            {
                que.push(i);
            }
            que1.pop();
        }
            if(f1)
            cnt++;
            if(ss == endWord)
            break;
     }
        if(ss == endWord)
        return cnt;
        else return 0;
    }
};
