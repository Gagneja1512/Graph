#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;

	public:
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

	void dfs(int vertex)
	{
		visited[vertex-1] = true ;
		cout<<vertex<<"->";
		
		list<int> adj = adjacenyList[vertex] ;
		for(auto itr = adj.begin() ; itr != adj.end() ; itr++)
		{
			if(visited[*(itr) - 1] == false)
			{
				dfs(*itr) ;
			}
		}

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


	g.dfs(1) ;
	return 0;
}