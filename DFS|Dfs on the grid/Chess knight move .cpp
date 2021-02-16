https://www.codechef.com/problems/PRGCUP01

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ar[9][9];
int visit[9][9];
int dis[9][9];
int dx[]={-2,-2,-1,-1,2,2,1,1};
int dy[]={1,-1,2,-2,-1,1,2,-2};

bool isvalid(int x,int y)
{
    if(x<0 || y<0 || x>=8 || y>=8)
     return false;
     
     if(visit[x][y]==1)
      return false;
      
      return true;
    
    
}


void bfs(int x,int y)
{ 
     queue<pair<int,int>> q;
     q.push(make_pair(x,y));
     visit[x][y]=1;
     dis[x][y]=0;
     while(!q.empty())
     {
         int a=q.front().first;
         int b=q.front().second;
         q.pop();
         for(int i=0;i<8;i++)
         {
             int newnbrx=a+dx[i];
             int newnbry=b+dy[i];
             if(isvalid(newnbrx,newnbry))
             {
                 q.push(make_pair(newnbrx,newnbry));
                 visit[newnbrx][newnbry]=1;
                 dis[newnbrx][newnbry]=dis[a][b]+1;
             }
         }
         
         
     }
}




int main() 
{
    
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        string s,s1;
        cin>>s>>s1;
        int sx,sy,ex,ey;
       
            sx=s[0]-'a';
            sy=s[1]-'0';
    
    
            ex=s1[0]-'a';
            ey=s1[1]-'0';
        ey--;
        sy--;
       for(int i=0;i<8;i++)
       {
        for(int j=0;j<8;j++)
        {
            dis[i][j]=0;
            visit[i][j]=0;
        }
       }
       
       
      //  cout<<sx<<sy<<endl;
        bfs(sx,sy);
    
    
    
    
    // for(int i=0;i<8;i++)
    // {
    //     for(int j=0;j<8;j++)
    //      cout<<dis[i][j]<<" ";
    // cout<<endl;
        
    
    
    
    cout<<dis[ex][ey]<<endl;
    }
}
