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
const int N = 1e3 + 1 ;
const int INF = 1e9 + 1 ;
int n , m;

vector<vector<int>> v(N , vector<int>(N)) ;
vector<vector<bool>> vis(N , vector<bool>(N , false)) ;
vector<vector<int>> level(N , vector<int>(N , INF)) ;

vector<pair<int , int>> movements = {
	{-1 , -1} , {0 , -1} , {1 , -1} ,
	{-1 , 0} , {1 , 0} ,
	{-1 , 1} , {0 , 1} , {1 , 1} 
};

bool valid(int x , int y)
{
	if(x>=0 and y>=0 and x<n and y<m)
		return true ;

	return false ;
}

void bfs()
{
	int mx = INT_MIN ;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			mx = max(mx , v[i][j]) ;
		}
	}

	queue<pair<int , int>> q ;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			if(mx == v[i][j])
			{
				q.push({i , j}) ;
				level[i][j] = 0 ;
				vis[i][j] = true ;

				//cout<<i+1<<' '<<j+1<<endl ;
			}
		}
	}	

	int ans = 0 ;

	while(!q.empty()) 
	{
		auto curr = q.front() ;
		int currx = curr.ff ;
		int curry = curr.ss ;
		q.pop() ;

		for(auto mov : movements)
		{
			int childx = currx + mov.ff ;
			int childy = curry + mov.ss ;

			if(valid(childx , childy) == false)
				continue ;

			if(vis[childx][childy])
				continue ;

			q.push({childx , childy}) ;
			level[childx][childy] = level[currx][curry] + 1;
			vis[childx][childy] = true ;
			ans = max(ans , level[childx][childy]) ; 
		}
	}

	cout<<ans<<endl;
	return ;
}

void solve_case()
{
    cin>>n>>m ;

    for(int i=0 ; i<n ; i++)
    {
    	for(int j=0 ; j<m ; j++)
    	{
    		level[i][j] = INF ;
    		vis[i][j] = false ;
    	}
    }

    for(int i=0 ; i<n ; i++)
    {
    	for(int j=0 ; j<m ; j++)
    		cin>>v[i][j] ;
    }

    bfs() ;
    return ;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve_case();
    }
    return 0;
}