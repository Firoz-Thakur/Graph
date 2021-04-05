https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        map<int,list<pair<int,int>>> mp;
        
        
        for(auto x : flights)
        {
            int u=x[0];
            int v=x[1];
            int d=x[2];
            mp[u].push_back(make_pair(v,d));
        }
        priority_queue< vector<int> , vector<vector<int> >,greater<vector<int>> > pq;
        
        pq.push({0,src,K+1});
        
        while(!pq.empty())
        {
            auto vec=pq.top();
            pq.pop();
            int dis=vec[0];
            int node=vec[1];
            int step_remaining=vec[2];
            if(step_remaining<0)
                continue;
            
            if(node==dst)
                 return dis;
            
            for(auto nbr : mp[node])
            {
                int next_nbr=nbr.first;
                int next_dis=nbr.second;
                pq.push({dis+next_dis,next_nbr,step_remaining-1});
            }
        }
        
        
        return -1;
    }
};
