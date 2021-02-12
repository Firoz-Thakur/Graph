https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/?layout=old


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(int src,map<int,list<int>> adj,map<int,bool> &visited)
{
  visited[src]=true;

  for(auto nbr: adj[src])
  {
    if(visited[nbr]==false)
     dfs(nbr,adj,visited);
  }
}


int main()
{
  map<int,list<int> > adj;
  int n,e;
  cin>>n>>e;
  map<int,bool> visited;
  for(int i=1;i<=n;i++)
  {
    visited[i]=false;
  }
  while(e--)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
int c=0;
 for(int i=1;i<=n;i++)
 {
   if(visited[i]==false)
   {
     dfs(i,adj,visited);
     c++;
   }
 }
 cout<<c; 
}




	

