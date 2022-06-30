#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int vertex;
	list<pair<int , int>> *l;

	public:
	Graph(int vertices)
	{
		vertex = vertices ;
		l = new list<pair<int , int>>[vertices];
	}

	void addEdge(int u , int v , int wt , bool undir = true)
	{
		l[u].push_back({wt , v});
		if(undir)
			l[v].push_back({wt , u});
	}

	int dijkstra(int src , int dest)
	{
		vector<int> dis(vertex , INT_MAX);
		set<pair<int , int>> s;

		dis[src] = 0;
		s.insert({0,src});

		while(!s.empty())
		{
			auto it = s.begin();
			int node = it->second ;
			int disTillNow = it->first ;
			s.erase(it) ;

			for(auto nbrPair : l[node])
			{
				int nbr = nbrPair.second ;
				int current = nbrPair.first ;

				if(current + disTillNow < dis[nbr])
				{
					auto f = s.find({dis[nbr] , nbr});
					if(f != s.end())
						s.erase(f);

					dis[nbr] = current + disTillNow ;
					s.insert({dis[nbr] , nbr});	
				}
			}
		}

		for(int i=0 ; i<vertex ; i++)
		{
			cout<<src<<" -> distance -> "<<dis[i]<<endl;
		}

		return dis[dest];
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0 , 1 , 1);
	g.addEdge(1 , 2 , 1);
	g.addEdge(0 , 2 , 4);
	g.addEdge(0 , 3 , 7);
	g.addEdge(3 , 2 , 2);
	g.addEdge(3 , 4 , 3);

	cout<<g.dijkstra(0 , 3)<<endl;
}