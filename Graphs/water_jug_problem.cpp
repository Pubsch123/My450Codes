class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        int newcapacity = jug1 + jug2;
        map<int,int> vis;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int a[4] = {jug1,-jug1,jug2,-jug2};
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(x+a[i]==target)
                {
                    return true;
                }
                if(x+a[i]<=newcapacity &&  x+a[i]>=0 && !vis[x+a[i]])
                {
                    vis[x+a[i]] = 1;
                    q.push(x+a[i]);
                }
            }
        }
        return false;
    }
};
