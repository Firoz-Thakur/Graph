https://cses.fi/problemset/result/1905369/

#include <bits/stdc++.h>
using namespace std;
 
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
 
long long int n,m;
cin>>n>>m;
long long int  par[1000001];
 
map<long long int ,list<long long int> > graph;
 
while(m--)
{
   long long int x,y;
   cin>>x>>y;
   graph[x].push_back(y);
   graph[y].push_back(x);
}
 
queue<long long int > q;
 
 
q.push(1);
par[1]=-1;
 
while(!q.empty())
{
  long long int x=q.front();
  q.pop();
  if(x==n)
     break;
  for(auto &nbr:graph[x])
  {   
    if(!par[nbr]){
      par[nbr]=x;
      q.push(nbr);
  }
  }
}
 
 
if(par[n])
{
   stack<long long int> st;
   st.push(n);
   long long int p=par[n];
   while(p!=-1)
   {
      st.push(p);    
      p=par[p];                        
   }
   cout<<(int)st.size()<<"\n";
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
}
else
{
  cout<<"IMPOSSIBLE";
}
 
}
