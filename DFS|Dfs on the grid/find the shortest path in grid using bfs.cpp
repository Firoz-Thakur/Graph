5 5
3 3


3 3 3 3 3 
3 2 2 2 2 
3 2 1 1 1 
3 2 1 0 1 
3 2 1 1 1 






#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m;
int visit[10001][10001];
int dis[10001][10001];
int dx[]={-1,1,-1,1,1,0,0,-1};
int dy[]={-1,1,1,-1,0,1,-1,0};


bool isvalid(int x,int y)
{
  if(x<0 || y<0 || x>=n || y>=m)
     return false;

   if(visit[x][y]==1)
     return false;

return true;

}


void bfs(int x,int y)
{
  visit[x][y]=1;
  queue<pair<int,int> > q;
  q.push(make_pair(x,y));
  dis[x][y]=0;

  while(!q.empty())
 {
   int a=q.front().first;
   int b=q.front().second;
   q.pop();
   for(int i=0;i<8;i++)
   {
      if(isvalid(a+dx[i],b+dy[i]))
      {
        int newnbrx=a+dx[i];
        int newnbry=b+dy[i];
        q.push(make_pair(newnbrx,newnbry));
        dis[newnbrx][newnbry]=dis[a][b]+1;
        visit[newnbrx][newnbry]=1;
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

  
  int x,y;
  cin>>n>>m;
  cin>>x>>y;
  bfs(x,y);

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
       cout<<dis[i][j]<<" ";
    cout<<endl;
 }

}




	
