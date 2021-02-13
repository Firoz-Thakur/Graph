https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/submissions/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
vector<int> ar[1000001];
int vi[1000001];
int d[1000001];
int level[1000001];
 
void bfs(int src, int dis)
{
  queue<int> q;
  vi[src]=true;
  q.push(src);
  d[src]=0;
  //level[d[src]]=0;
  while(!q.empty())
  {
    int x=q.front();
    q.pop();
    for(auto nbr:ar[x])
    {
      if(vi[nbr]==false)
      {
        vi[nbr]=true;
        d[nbr]=d[x]+1;
        level[d[nbr]]++;
        q.push(nbr);
      }
    }
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
 
 
  
 int n,e;
 cin>>n>>e;
 
 //vi.clear();
 
 while(e--)
 {
   int x,y;
   cin>>x>>y;
   ar[x].push_back(y);
   ar[y].push_back(x);
 }
 
 
 int q;
 cin>>q;
 while(q--)
 {
   for(int i=0;i<=n;i++)
   {
    vi[i]=0;
   // ar[i].clear();
    d[i]=0;
    level[i]=0;
   }
 
   int x,dis;
   cin>>x>>dis;
   bfs(x,dis);
   // for(int i=1;i<=n;i++)
     // cout<<level[i]<<" ";
   cout<<level[dis]<<endl;
 }

}
 
