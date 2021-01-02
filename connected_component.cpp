
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph {

 public :

 map<int,list<int> > l;

 void add(int x,int y)
 {
	 l[x].push_back(y);
	 l[y].push_back(x);
 }

void dfs(int src,map<int,bool> &visited)
{
   visited[src]=true;
   for(auto nbr : l[src])
   {
   if(!visited[nbr])
	   dfs(nbr,visited);
   }
}

void find_connected_comp(int src,int n)
{
  map<int,bool> visited;
  
  for(int i=1;i<=n;i++)
  {
	  visited[i]=false;
  }
  
  int c=0;
  for(int i=1;i<=n;i++)
  {
      if(!visited[i])
      {
		  dfs(i,visited);
		  c++;
	    }
  }
  cout<<c<<endl;

  }

};


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("fuck.txt", "w", stdout);
    #endif
  



    graph g;
    
	int a,b;
	cin>>a>>b;
	while(b--)
	{
		int x,y;
		cin>>x>>y;
		g.add(x,y);
	}
 
   g.find_connected_comp(1,a); 




}



	

