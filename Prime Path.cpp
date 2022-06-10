//Given 4 digit primes numbers . You have to convert one number to other by converting one digit of first number to another digit. The task is to find the minimum number of operations to convert to other number. Incase if its not possible to convert print "impossible".

#include<bits/stdc++.h>
using namespace std;

class Graph{
	bool *visited ;
	list<int> *adjacenyList ;
	int *distance;
	vector<int> primes ;

	public:
	Graph()
	{
		adjacenyList = new list<int>[10000] ;
		visited = new bool[10000] ;
		distance = new int[10000] ;

		for(int i=0 ; i<10000 ; i++)
			distance[i] = -1 ;
	}

	bool isprime(int a)
	{
		for(int i=2 ; i*i<=a ; i++)
		{
			if(a%i == 0)
				return false ;
		}

		return true ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	bool isValid(int a , int b)
	{
		int count = 0 ;

		while(a > 0)
		{
			if(a%10 != b%10)
			{
				count++ ;
			}

			a = a/10 ;
			b = b/10 ;
		}

		if(count == 1)
			return true ;

		else 
			return false ;	
	}

	void buildGraph()
	{
		for(int i=1000 ; i<=9999 ; i++)
		{
			if(isprime(i))
			{
				primes.push_back(i) ;
			}
		}


		for(int i=0 ; i<primes.size() ; i++)
		{
			for(int j=i+1 ; j<primes.size() ; j++)
			{
				int a = primes[i] ;
				int b = primes[j] ;

				if(isValid(a , b))
				{
					addEdge(a , b) ;
				}
			}
		}
	}

	int* bfs(int source)
	{
		queue<int> q;
		q.push(source) ;

		visited[source] = true ;
		distance[source] = 0 ;

		while(!q.empty())
		{
			int current = q.front() ;
			q.pop() ;

			list<int> adj = adjacenyList[current] ;
			for(auto itr = adj.begin() ; itr != adj.end() ; itr++)
			{
				int child = *itr ;

				if(visited[child] == false)
				{
					visited[child] = true ;
					distance[child] = distance[current] + 1 ;
					q.push(child) ;
				}
			}
		}

		return distance ;
	}

};	

int main()
{
	Graph g;

	g.buildGraph() ;

	int a , b;
	cin>>a>>b ;

	int *arr = g.bfs(a) ;

	if(arr[b] == -1)
		cout<<"IMPOSSIBLE" ;

	else
		cout<<arr[b]<<endl;

	return 0;	

}