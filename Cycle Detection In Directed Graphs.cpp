#include<bits/stdc++.h>
using namespace std;

class graph{

	int v;
	list<int> *l;

	public:
	graph(int value)
	{
		v = value;
		l = new list<int>[value];
	}

	void addEdge(int x , int y)
	{
		l[x].push_back(y);
	}

	bool dfs(int node , vector<bool> &visited , vector<bool> &stack)
	{
		visited[node] = true ;
		stack[node] = true ;

		for(int nbr : l[node])
		{
			if(stack[nbr])
				return true ;

			else if(visited[nbr] == false)
			{
				if(dfs(nbr , visited , stack))
					return true ;
			}	
		}

		stack[node] = false;
		return false ;
	}

	bool cycle_detection()
	{
		vector<bool> visited(v+1 , false);
		vector<bool> stack(v+1 , false);

		for(int i=0 ; i<v ; i++)
		{
			if(visited[i] == false)
			{
				if(dfs(i , visited , stack))
					return true;
			}
		}

		return false;
	}
};

int main()
{
	graph g(6);
	g.addEdge(0 , 4);
	g.addEdge(0 , 5);
	g.addEdge(4 , 5);
	g.addEdge(0 , 1);
	g.addEdge(1 , 2);
	g.addEdge(2 , 3);
	g.addEdge(0 , 3);

	cout<<g.cycle_detection()<<endl;

	return 0;
}