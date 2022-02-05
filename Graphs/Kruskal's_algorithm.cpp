#include <bits/stdc++.h>
using namespace std;

struct var{
    int a,b,wt;
    var(int first, int second, int weight)
    {
        a = first;
        b = second; 
        wt = weight;
    }
};

    bool compare(var v1, var v2)
    {
        return v1.wt < v2.wt;
    }

int findpar(int node, vector<int> &parent)
{
    if(node == parent[node])
    return node;
    return parent[node] = findpar(parent[node],parent);
}

void unnion(int x1, int x2, vector<int> &parent, vector<int> &rank)
{
    int s1 = findpar(x1,parent);
    int s2 = findpar(x2,parent);
    if(s1!=s2)
    {
        if(rank[s1] < rank[s2])
        {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }else{
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<var> edge;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edge.push_back(var{u,v,w});
        }
        sort(edge.begin(),edge.end(),compare);
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        int mindist=0;
        vector<pair<int,int>> mst;
        for(var i: edge)
        {
            if(findpar(i.a,parent) != findpar(i.b,parent))
            {
                mindist += i.wt;
                mst.push_back({i.a,i.b});
                unnion(i.a,i.b,parent,rank);
            }
        }
        cout<<mindist<<"\n";
        for(int i=0;i<(int)mst.size();i++)
        {
            cout<<mst[i].first<<"--"<<mst[i].second<<"\n";
        }
    }
	return 0;
}
