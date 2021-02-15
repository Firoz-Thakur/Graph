https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/description/

5
S P P P P
T P T P P
T P P P P
P T E T T
P T P T T
SAMPLE OUTPUT 
5




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
char ar[10001][100001];
int visit5[10001][10001];
int dis[10001][10001];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};


bool isvalid(int x,int y)
{
  if(x<0 || y<0 || x>=n || y>=n)
     return false;

   if(visit5[x][y]==1)
     return false;

return true;

}


void bfs(int x,int y)
{
  visit5[x][y]=1;
  queue<pair<int,int> > q;
  q.push(make_pair(x,y));
  dis[x][y]=0;

  while(!q.empty())
 {
   int a=q.front().first;
   int b=q.front().second;
   q.pop();
   for(int i=0;i<4;i++)
   {
      if(isvalid(a+dx[i],b+dy[i]) && (ar[a+dx[i]][b+dy[i]]=='P'|| ar[a+dx[i]][b+dy[i]]=='E'))
      {
        int newnbrx=a+dx[i];
        int newnbry=b+dy[i];
        q.push(make_pair(newnbrx,newnbry));
        dis[newnbrx][newnbry]=dis[a][b]+1;
        visit5[newnbrx][newnbry]=1;
      }
   }
}
}
int main()
{



  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>ar[i][j];
    }
  }
  int sx,sy,ex,ey;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(ar[i][j]=='S')
      {
        sx=i;
        sy=j;
      }
      else if(ar[i][j]=='E')
      {
        ex=i;
        ey=j;
      }
    }
  }
  //cout<<sx<<" "<<sy<<endl;
  // cout<<ex<<" "<<ey<<endl;
   
  
  bfs(sx,sy);
 
  //for(int i=0;i<n;i++)
  //{
  //  for(int j=0;j<n;j++)
  //  {
  //   cout<<dis[i][j]<<" ";	
  //  }
  //	cout<<endl;
  //}
    
 
  
cout<<dis[ex][ey];
 
 

}




	
