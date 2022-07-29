#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
typedef long long int ll;
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define endl '\n'
#define vl vector<long long>

vl intime , low ;
vector<bool> visited ;
vl points ;
unordered_map<ll , list<ll>> adjcacency ;
ll timer = 0;
void dfs(ll node , ll parent)
{
	low[node] = intime[node] = ++ timer ;
	visited[node] = true ;
	ll child = 0;

	list<ll> adj = adjcacency[node];
	for(auto itr = adj.begin() ;  itr != adj.end() ; itr++)
	{
		ll ch = *itr ;

		if(ch == parent)
			continue ;

		if(visited[ch] == true)
		{
			low[node] = min(low[node] , intime[ch]);
		}

		else
		{
			dfs(ch , node);

			low[node] = min(low[node] , low[ch]);

			if(low[ch] >= intime[node] and parent != -1)
			{
				points.pb(node) ;
			}

			++child ;
		}
	}

	if(parent == -1 and child >1)
		points.pb(node);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m; cin>>n>>m;

    for(int i=0 ; i<= n ; i++)
    {
    	visited.pb(false);
    	intime.pb(-1) ; low.pb(-1) ;
    }

    for(int i=0 ; i<m ; i++)
    {
    	ll u,v; cin>>u>>v;

    	adjcacency[u].pb(v);
    	adjcacency[v].pb(u);
    }

    for(int i=1 ; i<=n ; i++)
    {
    	if(visited[i] == false)
    		dfs(i , -1);
    }	


    for(int i=0 ; i<points.size() ; i++)
    	cout<<points[i]<<" ";

    cout<<endl;
    return 0;
}