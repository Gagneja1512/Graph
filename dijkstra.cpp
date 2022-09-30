class Solution {
public:
    int dijkstra(int source , int n , vector<pair<int , int>> g[])
    {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
        
        vector<int> distance(n+1 , INT_MAX) ;
        vector<bool> visited(n+1 , false) ; 
        
        distance[source] = 0 ;
        pq.push({distance[source] , source}) ;
        
        while(pq.size() > 0)
        {   
            auto node = pq.top() ;
            int v = node.second ;
            int vdis = node.first ;
                
            pq.pop() ;
            
            if(visited[v])
                continue ;
            visited[v] = true ;
            for(auto child : g[v])
            {
                int child_v = child.first ;
                int child_d = child.second ;
                
                if(child_d + distance[v] < distance[child_v])
                {
                    distance[child_v] = child_d + distance[v];
                    pq.push({distance[child_v] , child_v}) ;
                }
            }
        }
        
        int ans = INT_MIN ;
        for(int i=1 ; i<=n ; i++)
        {
            if(distance[i] == INT_MAX)
            {
                return -1 ;
            }
            
            //cout<<distance[i]<<' ' ;
            ans = max(ans , distance[i]) ;
        }
        
        return ans  ;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int , int>> g[n+1] ;
        
        int sz = times.size() ;
        for(int i=0 ; i<sz ; i++)
        {
            g[times[i][0]].push_back({times[i][1] , times[i][2]}) ;
        }
        
        return dijkstra(k , n , g) ;
    }
};