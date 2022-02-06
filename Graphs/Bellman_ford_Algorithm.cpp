class Solution {
public:
	    int isNegativeWeightCycle(int n, vector<vector<int>>edges){
       vector<int>dist(n,INT_MAX);
       dist[0]=0;
       for(int i=0;i<n-1;i++){
           for(int j=0;j<edges.size();j++){
               int sn=edges[j][0];
               int dn=edges[j][1];
               int wt=edges[j][2];
               if(dist[sn]!=INT_MAX && (dist[sn]+wt<dist[dn]))dist[dn]=dist[sn]+wt;
           }
       }
       for(auto it:edges){
           if(dist[it[0]]+it[2]<dist[it[1]])return 1;
       }
       return 0;
    }
};
