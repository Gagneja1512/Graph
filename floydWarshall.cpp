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
const int N = 501 ;
const int INF = 1e9 + 1 ;
vector<vector<int>> dist(N , vector<int>(N , INF)) ;


void solve_case()
{	
	int n , m; cin>>n>>m ;

	for(int i=0 ; i<m ; i++)
	{
		int x , y  ,wt ;
		cin>>x>>y>>wt ;

		dist[x][y] = wt ;
	}

	for(int k=1 ; k<=n ; k++)
	{
		for(int i=1 ; i<=n ; i++)
		{
			for(int j=1 ; j<=n ; j++)
			{
				if(dist[i][k] != INF and dist[k][j] != INF)
					dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ;
			}
		}
	}

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=n ; j++)
		{	
			if(i == j)
				dist[i][j] = 0 ;

			if(dist[i][j] == INF)
				cout<<"I ";
			else
				cout<<dist[i][j]<<' ';
		}

		cout<<endl;
	}

	return ;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve_case() ;
    
    return 0;
}