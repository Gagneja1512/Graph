#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long int ll;
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define endl '\n'
#define vl vector<long long>
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 1e5 + 1 ;
const int INF = 1e9 ;
vector<pair<int , int>> g[N] ;
vector<int> level(N , INF) ;

int n , m;

int bfs()
{
	deque<int> q;
	q.push_back(1) ;
	level[1] = 0 ;

	while(!q.empty())
	{
		int current = q.front() ;
		q.pop_front() ;

		for(auto child : g[current])
		{
			int child_v = child.ff ;
			int wt = child.ss ;

			if(level[current] + wt < level[child_v])
			{
				level[child_v] = wt + level[current] ;
				if(wt == 1)
					q.push_back(child_v);
				else
					q.push_front(child_v) ;
			}
		}
	}

	return level[n] == INF ? -1 : level[n] ;
}

void solve_case()
{
    cin>>n>>m ;
    for(int i=0 ; i<m ; i++)
    {
    	int x , y; cin>>x>>y ;
    	if(x == y)
    		continue ;

    	g[x].pb({y , 0});
    	g[y].pb({x , 1});
    }

    cout<<bfs()<<endl;
    return ;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
        solve_case();
    
    return 0;
}