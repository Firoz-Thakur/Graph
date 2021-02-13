use the concept of the single shortest path.
use the concept of dfs

https://www.spoj.com/problems/PT07Z/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int visit[10001];
vector<int> ar[10001];
int mx=-1;
int nodmx=-1;
void dfs(int src,int dis)
{
   visit[src]=1;
   if(dis>mx)
   {
     nodmx=src;
     mx=dis;
   }
   for(auto nbr:ar[src])
   {
     if(visit[nbr]==0)
      dfs(nbr,dis+1);
   }
}
int main()
{

  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("outp.txt", "w", stdout);
#endif

 
 int n;
 cin>>n;
 int temp=n;
 for(int i=1;i<temp;i++)
 {
  int x,y;cin>>x>>y;
  ar[x].push_back(y),ar[y].push_back(x);
 }
 
 dfs(1,0);

 for(int i=1;i<=n;i++)
 {  
    visit[i]=0; 
 }
 mx=-1;
 dfs(nodmx,0);

cout<<mx;

}




	
