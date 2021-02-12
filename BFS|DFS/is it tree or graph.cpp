https://www.spoj.com/problems/PT07Y/

tree having property :

1) single connected component .
2) not of edge=no of node-1

//us the concept of strongly connected compoennt (which can be done by dfs)


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(int src,map<int,list<int>> &adj,unordered_map<int,bool> &visited)
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
  int temp=e;
  unordered_map<int,bool> visited;
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
 if(c==1 && temp==n-1)
 cout<<"YES";
 else
 cout<<"NO";
 
 //cout<<c; 
}




	
