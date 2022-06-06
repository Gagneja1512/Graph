#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;
	int *color ;

	public:
	Graph(int vertices)
	{
		numberOfVertices = vertices ;
		adjacenyList = new list<int>[vertices+1] ;
		visited = new bool[vertices] ;
		color = new int[vertices+1] ;
		color[0] = 1 ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	bool bipartite_test(int vertex)
	{
		for(int u : adjacenyList[vertex])
		{
			if(visited[u] == false)
			{
				visited[u] = true ;
				color[u] = !color[vertex] ;

				if(!bipartite_test(u))
				{
					return false ;
				}
			} 

			if(color[u] == color[vertex])
			{
				return false ;
			}
		}

		return true ;
	}
};

int main()
{
	Graph g(5);
	g.addEdge(1 , 2) ;
	g.addEdge(2 , 3) ;
	g.addEdge(3 , 4) ;
	g.addEdge(4 , 5) ;
	g.addEdge(2 , 4) ;


	bool ans = g.bipartite_test(1) ;
	cout<<ans<<endl;
	return 0;
}