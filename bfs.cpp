

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
   	 map<int,bool> visted;
   	 queue<int> q;
   	 q.push(0);
   	 visted[0]=true;
   	
   	while(!q.empty())
   	{
   		int first=q.front();
   		cout<<first<<",";
   		q.pop();
   		for(auto nbr:mp[first])
   		{
   			if(visted[nbr]==true)
   			 continue;
   			else
   			{
   				q.push(nbr);
   				visted[nbr]=true;;
   			}
   		}
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
