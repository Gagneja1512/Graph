#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;
	int *distance;

	public:
	Graph(int vertices)
	{
		numberOfVertices = vertices ;
		adjacenyList = new list<int>[vertices+1] ;
		visited = new bool[vertices+1] ;
		distance = new int[vertices+1] ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	int* bfs(int node)
	{
		queue<int> q;
		q.push(node) ;

		visited[node] = true ;
		distance[node] = 0 ;

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
					q.push(child) ;
					distance[child] = distance[current] + 1;
					visited[child] = true ;
				}
			}
		}

		return distance ;
	}
	
};

int main()
{
	Graph g(7);
	g.addEdge(1 , 2) ;
	g.addEdge(3 , 2) ;
	g.addEdge(4 , 2) ;
	g.addEdge(1 , 3) ;
	g.addEdge(3 , 5) ;
	g.addEdge(5 , 6) ;
	g.addEdge(5 , 7) ;
	g.addEdge(7 , 6) ;

	int *arr = g.bfs(3) ;
	for(int i=1 ; i<8 ; i++)
		cout<<arr[i]<<" " ;


	return 0;
}