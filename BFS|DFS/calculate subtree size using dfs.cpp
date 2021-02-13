https://www.youtube.com/watch?v=rFVKXZZMH-U&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=16




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int visit[10001];
vector<int> ar[10001];
int dis[10001];


int dfs(int src)
{
   visit[src]=1;
   dis[src]=1;
   for(auto nbr:ar[src])
   {
     if(visit[nbr]==0)
      dis[src]+=dfs(nbr);
   }
   return dis[src];
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
  int x,y;
  cin>>x>>y;
  ar[x].push_back(y);
  ar[y].push_back(x);
 }
 for(int i=1;i<=n;i++)
 {
  visit[i]=0;
 }
 
 int x=dfs(1);
 
 for(int i=1;i<=temp;i++) {
  cout<<dis[i]<<" ";
}
}




	
