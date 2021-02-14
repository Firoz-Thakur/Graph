spoj.com/problems/TOPOSORT/




#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> ar[1000001];
//int vi[1000001];
int in[1000001];
vector<int> v;

void bfs(int n)
{
  priority_queue<int,vector<int>,greater<int> > q;

  for(int i=1;i<=n;i++)
  {
    if(in[i]==0)
       q.push(i);

 //  cout<<i<<" "<<in[i]<<endl;

  }

  

  while(!q.empty())
  {
    int x=q.top();
    q.pop();
    v.push_back(x);
    for(auto nbr:ar[x])
    {
        in[nbr]--;
        if(in[nbr]==0)
         q.push(nbr);
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


  
 int n,m;
 cin>>n>>m;

 
 for(int i=0;i<m;i++)
 {
   int x,y;
   cin>>x>>y;
   ar[x].push_back(y);
   in[y]++;
 }


  bfs(n);
  //cout<<v.size();
  if(v.size()==n)
  {
    for(int i=0;i<v.size();i++)
    {
      cout<<v[i]<<" ";
    }
  }
  else
  {
    cout<<"Sandro fails.";
  }
 

 }



	
