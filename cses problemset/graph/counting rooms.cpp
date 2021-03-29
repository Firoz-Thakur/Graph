https://cses.fi/problemset/result/1904097/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
 
int vist[1001][1001];
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char ar[10001][10001];
bool isvalid(int x,int y)
{
   if(x<0 || y<0 || x>=n || y>=m)
     return false;
 
   if(vist[x][y]==1)
    return false;
 
  return true;
}
void dfs(int i,int j)
{
   vist[i][j]=1;
 
   for(int k=0;k<4;k++)
   {
       int curx=i+dx[k];
       int cuy=j+dy[k];
       if(isvalid(curx,cuy) && vist[curx][cuy]==0 && ar[curx][cuy]=='.' )
       {
         dfs(curx,cuy);
       }
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
 
for(int i=0;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
    cin>>ar[i][j];
  }
}
for(int i=0;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
    vist[i][j]=0;
  }
}
 
// for(int i=0;i<n;i++)
// {
//   for(int j=0;j<m;j++)
//   {
//      cout<<ar[i][j]<<" ";
//   }
//   cout<<endl;
// }
 
 
int c=0;
for(int i=0;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
     if(vist[i][j]==0 && ar[i][j]=='.')
     {
       dfs(i,j);
       c++;
 
     }
  }
}
cout<<c<<endl;
 
}
Share code to others
