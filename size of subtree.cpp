#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;
	int *subtreeSize ;

	public:
	Graph(int vertices)
	{
		numberOfVertices = vertices ;
		adjacenyList = new list<int>[vertices+1] ;
		visited = new bool[vertices] ;
		subtreeSize = new int[vertices+1] ;
		subtreeSize[0] = 0 ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	int size_subtree(int node)
	{
		visited[node-1] = true ;
		int current_size = 1 ;
		
		list<int> adj = adjacenyList[node] ;
		for(auto itr = adj.begin() ; itr != adj.end() ; itr++)
		{
			if(visited[*(itr) - 1] == false)
			{   	
				int child = *itr;
				current_size = current_size + size_subtree(child) ;
			}
		}

		subtreeSize[node] = current_size ;
		return current_size ;
	}

	int subtree(int node)
	{
		return subtreeSize[node] ;
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

	int temp = g.size_subtree(1) ;
	temp = g.subtree(4) ;
	cout << temp << endl;
    
	return 0;
}