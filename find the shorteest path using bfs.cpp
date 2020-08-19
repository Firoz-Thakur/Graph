find the shorteest path using bfs unweighted graph.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class graph
{
 public:
    map<int,list<int>> mp;
    
   void addedg(int x,int y)
   {
   	 mp[x].push_back(y);
   	 mp[y].push_back(x);
   }
   
   void bfs(int src)
   {
   	 map<int,int> dist;
   	 queue<int> q;
   	 q.push(0);
   	
   	for(auto node_pair : mp)
   	{
   		int node=node_pair.first;
   		dist[node]=INT_MAX;
   		
   	}
   	dist[0]=0;
   	while(!q.empty())
   	{
   		int first=q.front();
   		q.pop();
   		for(auto nbr:mp[first])
   		{
   			if(dist[nbr]==INT_MAX)
   			{
   				q.push(nbr);
   				dist[nbr]=dist[first]+1;
   			}
   		}
   	}
   	
   for(auto node_pair:mp)
   {
   	 int node =node_pair.first;
   	 
   	 cout<<"distace of "<<node<<" from the source is "<<dist[node]<<endl;
   }
   	
   }
};


int main() {
	// your code goes here
	
	graph g;
	g.addedg(0,1);
	g.addedg(0,3);
    g.addedg(1,2);
    g.addedg(2,3);
    g.addedg(3,4);
    g.addedg(4,5);
 
    g.bfs(0);
	return 0;
}

output: 


distace of 0 from the source is 0
distace of 1 from the source is 1
distace of 2 from the source is 2
distace of 3 from the source is 1
distace of 4 from the source is 2
distace of 5 from the source is 3
