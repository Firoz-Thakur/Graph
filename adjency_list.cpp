#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph{
 public:
  int V;
  list<int> *p;
  graph(int vx)
  {
  	V=vx;
  	p=new list<int> [V];
  }
  
  void add_vertax(int x,int y)
  {
  	p[x].push_back(y);
  	p[y].push_back(x);
  }
 
 void print_addcncylist()
 {
 	for(int i=0;i<V;i++)
 	{
 		cout<<"vertax"<<i<<"---> ";
 		for(int nbr:p[i])
 		 {
 		 	cout<<nbr<<",";
 		 }
 		cout<<endl;
 	}

 }
};


int main() {
	// your code goes here
 
   graph g(4);
   g.add_vertax(0,1);
   g.add_vertax(0,2);
   g.add_vertax(2,3);
   g.add_vertax(1,2);
   
   g.print_addcncylist();
	return 0;
}
