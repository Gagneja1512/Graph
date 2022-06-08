#include<bits/stdc++.h>
using namespace std;

class Graph{
	int numberOfVertices ;
	bool *visited ;
	list<int> *adjacenyList ;
	int *in_time ;
	int *out_time ;
	int timer ;

	public:
	Graph(int vertices)
	{
		numberOfVertices = vertices ;
		adjacenyList = new list<int>[vertices+1] ;
		visited = new bool[vertices] ;
		in_time = new int[vertices + 1] ;
		out_time = new int[vertices + 1] ;
		timer = 0 ;
		in_time[0] = timer ;
		out_time[0] = timer ;
		timer++ ;
	}

	void addEdge(int a , int b)
	{
		adjacenyList[a].push_back(b) ;
		adjacenyList[b].push_back(a) ;
	}

	void in_out(int node)
	{
		visited[node - 1] = true ;
		in_time[node] = timer++ ;
		list<int> adj = adjacenyList[node] ;

		for(auto itr = adj.begin() ; itr != adj.end() ; itr++)
		{
			int child  = *itr ;
			if(visited[child - 1] == false)
			{
				in_out(child) ;
			}
		}
		out_time[node] = timer++ ;
	}

	bool subtree(int node_1 , int node_2)
	{
		bool first = in_time[node_1] < in_time[node_2] ;
		bool second = out_time[node_1] > out_time[node_2] ;

		if(first and second)
			return true ;

		bool third = in_time[node_1] > in_time[node_2] ;
		bool fourth = out_time[node_1] < out_time[node_2] ;	

		if(third and fourth)	
			return true ;

		return false ;	
	}
};

int main()
{
	Graph g(7);
	g.addEdge(1 , 2) ;
	g.addEdge(2 , 3) ;
	g.addEdge(3 , 5) ;
	g.addEdge(2 , 4) ;
	g.addEdge(4 , 6) ;
	g.addEdge(4 , 7) ;

	g.in_out(1) ;

	bool ans = g.subtree(2 , 6); 
	cout<<ans<<endl;
	return 0;
}