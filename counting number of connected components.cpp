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

	int connected_components()
	{
		int cc_count = 0;
		for(int i=0 ; i<numberOfVertices ; i++)
		{
			if(visited[i] == false)
			{
				dfs(i+1) ;
				cc_count++ ;
				cout<<endl ;
			}
		}

		return cc_count ;
	}
};

int main()
{   
	Graph g(8);
	g.addEdge(1 , 5) ;
	g.addEdge(5 , 2) ;
	g.addEdge(2 , 8) ;
	g.addEdge(8 , 6) ;
	g.addEdge(6 , 5) ;
	g.addEdge(6 , 4) ;
	g.addEdge(3 , 7) ;
    
	int components = g.connected_components() ;

	cout<<"Number of connected components are "<<components<<endl;

	return 0;
}