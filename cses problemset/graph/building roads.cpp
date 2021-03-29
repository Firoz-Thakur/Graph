https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
 
long long int  vist[1000001];
long long int n,m;
map<long long int ,list<long long int> > graph;
 
void dfs(long long int src)
{
   vist[src]=1;
   for(auto x: graph[src])
   {
     if(!vist[x])
       dfs(x);
   }
}
 
int main()
{
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("outp.txt", "w", stdout);
   #endif
 
 
cin>>n>>m;
while(m--)
{
   long long int x,y;
   cin>>x>>y;
   graph[x].push_back(y);
   graph[y].push_back(x);
}
 
vector<long long int> v;
for(int i=1;i<=n;i++)
{
  vist[i]=0;
}
 
for(long long int i=1;i<=n;i++)
{
    if(vist[i]==0)
    {
          dfs(i);
          v.push_back(i);
    }
}
 
if(v.size()==1)
  cout<<"0"<<endl;
else {
 cout<<v.size()-1;
 cout<<endl;
 for(int i=0;i<v.size()-1;i++)
 {
     cout<<v[i]<<" "<<v[i+1];
     cout<<endl;
 }
 
}
 
}
