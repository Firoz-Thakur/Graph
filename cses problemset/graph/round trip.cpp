https://cses.fi/problemset/result/1907172/

#include <bits/stdc++.h>
using namespace std;


long long int n,m;
map<int,int> visit;
map<long long int ,list<long long int> > graph;
long long int st[10000001];
long long int ende,starte;
bool dfs(long long int par,long long int src)
{
  visit[src]=1;
  st[src]=par;
  for(auto x: graph[src])
  {
    if(!visit[x]){
       bool fl= dfs(src,x);
       if(fl==true)
         return true;
    }
    else if(par!=x){
        ende=src;
        starte=x;
        return true;
       }
  }

  return false;
  }


int main()
{
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("outp.txt", "w", stdout);
   #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

cin>>n>>m;
while(m--)
{
   long long int x,y;
   cin>>x>>y;
   graph[x].push_back(y);
   graph[y].push_back(x);
}

visit.clear();
bool fl=false;
vector<long long int > v;
for(long long int i=1;i<=n;i++)
{
    if(!visit[i])
    {
     fl=dfs(-1,i);
        if(fl==true)
             break;
    }
}
if(fl==false)
 cout<<"IMPOSSIBLE"<<endl;
else
{
   v.push_back(starte);
   while(ende!=starte)
   {
     v.push_back(ende);
     ende=st[ende];
   }
    v.push_back(starte);
    cout<<v.size()<<endl;
    for(long long int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
 }

}

