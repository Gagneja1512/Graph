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

int subTreeSize(ll cur , ll parent , unordered_map<ll , list<ll>> &adj, vector<ll> &subtree)
{
	ll cur_size = 1;
	list<ll> v = adj[cur];
	for(auto itr = v.begin() ; itr != v.end() ; itr++)
	{	
		ll x = *itr;
		if(x != parent)
			cur_size += subTreeSize(x , cur , adj , subtree);
	}

	subtree[cur] = cur_size;
	return cur_size;
}

void buildTree(unordered_map<ll , list<ll>> &adj, ll n)
{
	for(int i=0 ; i<n-1 ; i++)
	{
		ll u , v ; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n ; cin>>n;
    unordered_map<ll , list<ll>> adj;
    buildTree(adj , n);

    vector<ll> subtree(n , 0);

    int size = subTreeSize(0 , -1 , adj , subtree);
    for(int i=0 ; i<n ; i++)
    	cout<<subtree[i]<<" ";

    cout<<endl;
    return 0;
}
