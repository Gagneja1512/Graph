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

	bool cycle_detection(int node , int parent)
	{
		visited[node-1] = true ;
		list<int> adj = adjacenyList[node] ;
		for(auto itr = adj.begin() ; itr!=adj.end() ; itr++)
		{
			int child = *itr ;
			if(visited[child] == false)
			{
				if(cycle_detection(child , node) == true)
					return true ;
			}
			else
			{
				if(child != parent)
					return true ;
			}
		}

		return false ;
	}
};

int main()
{
	Graph g(5);
	g.addEdge(1 , 2) ;
	g.addEdge(2 , 3) ;
	g.addEdge(3 , 4) ;
	g.addEdge(4 , 5) ;
	


	bool ans = g.cycle_detection(1 , -1) ;
	cout<<ans<<endl;
	return 0;
}