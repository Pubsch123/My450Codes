class Solution{
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int MAX = INT_MAX;
    struct compare{
        bool operator()(pair<int,int> p1, pair<int,int> p2)
        {
            return p1.first > p2.first;
        }
    };
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V+1,MAX);
        dist[S]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        pq.push({0,S});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(int i=0;i<(int)adj[node].size();i++)
            {
                int nextnode = adj[node][i][0];
                int diss = adj[node][i][1];
                if(diss+dist[node] < dist[nextnode])
                {
                    dist[nextnode] = dist[node]+diss;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        return dist;
    }
};
