#include <bits/stdc++.h>
using namespace std;

class graph
{
  int V;
  list <int> *l;
  public:
  graph(int v)
  {
      this->V=v;
      l=new list<int> [V];
  }
  void addedg(int x,int y)
  {
     l[x].push_back(y);
     l[y].push_back(x);
  }
  
  bool istree()
  {
    queue<int> q;
    int *parent = new int[V];
    bool *vist=new bool[V];
    for(int i=0;i<V;i++)
    {
      parent[i]=i;
      vist[i]=false;
    }
   int src=0;
   q.push(src);
   vist[src]=true;
   while(!q.empty())
   {
      int node=q.front();
      q.pop();
      for(auto nbr:l[node])
      {
          if(vist[nbr]==true && parent[node]!=nbr)
          {
              return false;
          } 
          else
          {
              vist[nbr]=true;
              q.push(nbr);
              parent[nbr]=node;
          }
          
      }
   }
     return true; 

  }

};

int main()
{
    graph g(4);
    g.addedg(0,1);
    g.addedg(3,2);
    g.addedg(1,2);
    g.addedg(0,3);
   bool t=g.istree();
   if(t==false)
    cout<<"not a tree";
   else
     cout<<"yes,is a tree";

}
