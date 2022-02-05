class Solution {
public:
	bool isPossible(int n, vector<pair<int, int>>& courses) {
	    vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto c : courses)
        {
            graph[c.second].push_back(c.first);
            indegree[c.first]++;
        }
    
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) 
                q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            cnt++;
            for(auto nbr: graph[curr])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0) 
                    q.push(nbr);
            }
        }
        if(cnt!=n) 
        	return false;
        	
        return true;
	}
};
