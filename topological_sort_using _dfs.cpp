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
   	// mp[y].push_back(x);
   }
   
 void dfs_help(int src,map<int,bool> &vist, list<int> &order)
 {
  //  cout<<src<<" ";
    vist[src]=true;
    
    for(auto nbr:mp[src])
    {
        if(!vist[nbr])
        {
            dfs_help(nbr,vist,order);
        }
    }
    order.push_front(src);
    return ;    
 }

   void dfs(int src)
   {
     list<int> order;
     map<int,bool> vist;
     for(auto p:mp)
     {
         auto node=p.first;
         vist[node]=false;
     }
    dfs_help(src,vist,order);
  for(auto node: order)
  {
      cout<<node<<" ";
  }
   }
};


int main() {
	// your code goes here
	
	graph g;
	g.addedg(0,1);
	g.addedg(1,2);
    g.addedg(2,3);
    g.addedg(3,4);
    g.addedg(5,4);
  //  g.addedg(3,0);

    g.dfs(0);
	return 0;
}
