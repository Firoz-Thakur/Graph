https://leetcode.com/problems/number-of-islands/


 class Solution {
public:
    
    int visit[3001][3001];
    int dx[5]={1,-1,0,0};
    int dy[5]={0,0,1,-1};
    int n,m;
    int c=0;
    bool isvalid(int i,int j)
    {
        
        if(i<0 || i>=n || j < 0 || j>=m)
        {
            return false;
        }
        if(visit[i][j]==1)
          return false;
        
        return true;
    }
    
    
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
       visit[x][y]=1;
       for(int i=0;i<4;i++)
        {
          if(isvalid(x+dx[i],y+dy[i]) && grid[x][y]=='1')
          {
              dfs(x+dx[i],y+dy[i],grid);
          }
        }   
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
       // mp.clear();
        vector<char> v=grid[0];
        m=v.size();
        n=grid.size();
     
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visit[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(visit[i][j]==0 && grid[i][j]=='1')
              {
                  dfs(i,j,grid);
                  c++;
              }
            }
        }
     return c;  
    }
    
    
};
