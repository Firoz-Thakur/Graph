#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class graph
{
 public:
 
  map <string ,list<pair<string,int>>> l;
	
 void addedg(string x,string y,bool dir,int wt)
 {
 	l[x].push_back(make_pair(y,wt));
 	if(dir)
 	{
 			l[y].push_back(make_pair(x,wt));
 	}
 	
 }
 
 void print()
 {
 	for(auto it=l.begin();it!=l.end();it++)
 	{
 		string s1=it->first;
 		list<pair<string,int>> l1=it->second;
 		cout<<s1<<" --->";
 		for(auto nbr : l1)
 		{
 			cout<<nbr.first<<","<<nbr.second<<" ";
 		}
 		cout<<endl;
 	}
 	
 	
 }
 
};


int main() {
	// your code goes here
	
	graph g;
	g.addedg("A","B",true,12);
    g.addedg("B","d",true,40);
    g.addedg("A","C",true,10);
	g.addedg("C","D",true,40);
	g.addedg("A","D",false,50);
 
    g.print();
	return 0;
}
