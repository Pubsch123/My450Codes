#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<ll>> adj;
vector<ll> vis,intime,outtime;
ll timer=1;

void dfs(ll cur)
{
	vis[cur]=1;
	intime[cur]=timer++;
	for(auto i: adj[cur])
	{
		if(!vis[i]){
     		dfs(i);
		}
	}
	outtime[cur]=timer++;
}

bool check(ll x, ll y)
{
     if(intime[x]>intime[y] && outtime[x] < outtime[y])
	    return true;
	    return false;
}

int main(){
	ll n;
	cin>>n;
	adj.resize(n+1);
	vis.resize(n+1,0);
	intime.resize(n+1);
	outtime.resize(n+1);
	ll m = n-1;
	while(m--)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	ll q;
	cin>>q;
	while(q--)
	{
	    ll x,u,v;
	    scanf("%d %d %d", &x, &u, &v);
	    if(!check(u,v) && !check(v,u))
	    {
	        cout<<"NO\n";
	        continue;
	    }
	    else if(x==1)
	    {
	        if(check(u,v))
	        cout<<"YES\n";
	        else
	        cout<<"NO\n";
	    }else if(x==0)
	    {
	        if(check(v,u))
	        cout<<"YES\n";
	        else
	        cout<<"NO\n";
	    }
	}
    return 0;
}
