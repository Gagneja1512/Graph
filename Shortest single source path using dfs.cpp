#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;
	int *distance ;

	public:
	Graph(int vertices)
	{
		numberOfVertices = vertices ;
		adjacenyList = new list<int>[vertices+1] ;
		visited = new bool[vertices] ;
		distance = new int[vertices] ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	void shortest_path(int vertex , int d)
	{
		visited[vertex-1] = true ;
		distance[vertex-1] = d ;
		
		list<int> adj = adjacenyList[vertex] ;
		for(auto itr = adj.begin() ; itr != adj.end() ; itr++)
		{
			if(visited[*(itr) - 1] == false)
			{
				shortest_path(*itr , distance[vertex-1] + 1) ;
			}
		}
	}

	int distance_shortest(int node)
	{
		return distance[node-1] ;
	}
};

int main()
{
	Graph g(6);
	g.addEdge(1 , 2) ;
	g.addEdge(3 , 2) ;
	g.addEdge(4 , 2) ;
	g.addEdge(4 , 5) ;
	g.addEdge(4 , 6) ;


	g.shortest_path(1 , 0) ;
	int ans = g.distance_shortest(5) ;
	cout<<ans<<endl;
	return 0;
}