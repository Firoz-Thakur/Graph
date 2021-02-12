https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/description/?layout=old



#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int temp=n;
 n--;
 map<int,list<int> > adj;
 while(n--)
 {
	int x,y;
	cin>>x>>y;
	adj[x].push_back(y);
	adj[y].push_back(x);
 }

int qi;
map<int,bool> mp;
cin>>qi;
while(qi--)
{
	int z;
    cin>>z;
	mp[z]=true;
}

queue<int> q;
map<int,int>visited;
q.push(1);
for(int i=1;i<=temp;i++)
{
	visited[i]=INT_MAX;
}

visited[1]=0;
while(!q.empty())
{ 
  int x=q.front();
  q.pop();
  for(auto nbr:adj[x])
  {
	  if(visited[nbr]==INT_MAX)
	  {
		  q.push(nbr);
		  visited[nbr]=visited[x]+1;
	  }
  }
}
int ans=INT_MAX;
int id=-1;
for(auto x: visited)
{
	if(mp[x.first]==true)
	{
      if(ans>x.second)
	  {
         ans=x.second;
		 id=x.first;
	  }
	}
}
cout<<id;

}
