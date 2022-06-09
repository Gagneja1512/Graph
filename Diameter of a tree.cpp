#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;
	

	public:
	int maxDistance = -1;
	int maxNode ;
	Graph(int vertices)
	{
		numberOfVertices = vertices ;
		adjacenyList = new list<int>[vertices+1] ;
		visited = new bool[vertices] ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	void dfs(int node ,int distance)
	{
		visited[node-1] = true ;
		if(distance > maxDistance)
		{
			maxDistance = distance ;
			maxNode = node ;
		}
		
		list<int> adj = adjacenyList[node] ;
		for(auto itr = adj.begin() ; itr != adj.end() ; itr++)
		{
			if(visited[*(itr) - 1] == false)
			{
				dfs(*itr , distance + 1) ;
			}
		}
	}

	void reset()
	{
		for(int i=0 ; i<numberOfVertices ; i++)
		{
			visited[i] = false ;
		}
	}
};

int main()
{
	Graph g(7);
	g.addEdge(1 , 2) ;
	g.addEdge(3 , 2) ;
	g.addEdge(4 , 2) ;
	g.addEdge(3 , 7) ;
	g.addEdge(4 , 6) ;
	g.addEdge(4 , 5) ;

	g.dfs(1 , 0) ;
	g.reset() ;
	g.dfs(g.maxNode , 0);

	cout<<g.maxDistance<<endl;
	return 0;
}