https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/description/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> ar[1000001];
int ccc[1000001];
int c_count;
unordered_map<int,int> vis;
void dfs(int src)
{
   vis[src]=1;
   ccc[src]=c_count;
   for(auto nbr:ar[src])
   {
     if(vis[nbr]==0)
        dfs(nbr);
   }

}

int main()
{

 
int t;
cin>>t;
while(t--)
{
 //int visit[1000001];
 int n,k;
 cin>>n>>k;
 c_count=0;
 //vis.clear()
 for(int i=1;i<=n;i++)
 {
    ar[i].clear();
    ccc[i]=0;
    vis[i]=0;
 }     
 vector<pair<int,int>> v;
 for(int i=1;i<=k;i++)
  {
  int x,y;
  string s;
  cin>>x>>s>>y;
  if(s=="="){
  ar[x].push_back(y);
  ar[y].push_back(x);
 }
 else
 {
   v.push_back(make_pair(x,y));
 }
}

 for(int i=1;i<=n;i++)
 { 
  if(vis[i]==0)
  {
    dfs(i);
    c_count++;
  }
 }
 int f=0;
 for(int i=0;i<v.size();i++)
 {
   int a=v[i].first;
   int b=v[i].second;
   if(ccc[a]==ccc[b])
   {
     f=1;
     break;
   }
 }
 if(f==1)
 {
  cout<<"NO"<<endl;
 }
 else
 {
  cout<<"YES"<<endl;
 }


 }

}




	
