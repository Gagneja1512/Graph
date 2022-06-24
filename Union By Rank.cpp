#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<pair<int , int>> l;

public:
	Graph(int value)
	{
		v = value;
	}	

	void addEdge(int x , int y)
	{
		l.push_back(make_pair(x , y));
	}

	int find_set(int i , int parent[])
	{
		if(parent[i] == -1)
			return i ;

		return find_set(parent[i] , parent);	
	}

	void union_set(int a , int b , int parent[] , int rank[])
	{
		int s1 = find_set(a , parent);
		int s2 = find_set(b , parent);

		if(s1 != s2)
		{
			if(rank[s1] <= rank[s2])
			{
				parent[s1] = s2;
				rank[s2] = rank[s2] + rank[s1];
			}
			else
			{
				parent[s2] = s1;
				rank[s1] = rank[s1] + rank[s2];
			}
		}
	}

	bool contains_cycle()
	{
		int *parent = new int[v];
		int *rank = new int[v]; 

		for(int i=0 ; i<v ; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}	
		for(auto edge : l)
		{
			int i = edge.first ;
			int j = edge.second ;

			int s1 = find_set(i , parent);
			int s2 = find_set(j , parent);

			if(s1 != s2)
				union_set(s1 , s2 , parent, rank);

			else 
				return true ;	
		}

		return false ;
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0 , 1);
	g.addEdge(1 , 2);
	g.addEdge(2 , 3);
	g.addEdge(3 , 1);

	cout<<g.contains_cycle()<<endl;
	return 0;
}