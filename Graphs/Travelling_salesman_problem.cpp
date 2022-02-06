#include <bits/stdc++.h>
using namespace std;

int n=4;
int matrix[10][10];
int visall = (1<<n)-1;
int dp[16][4];

int tsp(int mask, int pos)
{
    if(mask == visall)
    {
        return matrix[pos][0];
    }
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INT_MAX;
    for(int k=0;k<n;k++)
    {
        int uuu = mask&(1<<k);
        if(uuu==0){
        int newans = matrix[pos][k] + tsp(mask|(1<<k),k);
        ans = min(ans,newans);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    // cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<tsp(1,0);
    return 0;
}
