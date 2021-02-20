https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

int dx[8]={2,2,-2,-2,1,1,-1,-1};
   int dy[8]={1,-1,1,-1,2,-2,2,-2};
   int ar[1001][1001];
   int visited[1001][1001];
   
   
   int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
      
     // never forget to clearn the global array
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<N;j++)
	        {
	            ar[i][j]=0;
	            visited[i][j]=0;
	        }

	    }
	    
	    
	   int x=KnightPos[0];
	   int y=KnightPos[1];
	   int t1=TargetPos[0];
	   int t2=TargetPos[1];
	   x--;
	   y--;
	   t1--;
	   t2--;
	   
	   queue<pair<int,int>> q;
       q.push(make_pair(x,y));
       ar[x][y]=0;
       visited[x][y]=1;
       while(!q.empty())
       {
           auto x=q.front();
           q.pop();
           int x1=x.first;
           int y1=x.second;
           if(x1==t1 && y1==t2)
            return ar[t1][t2];
           
           
           for(int i=0;i<8;i++)
           {
               int newx=x1+dx[i];
               int newy=y1+dy[i];
               if(visited[newx][newy]==0 && newx>=0 && newy>=0 && newx<N && newy<N)
                 {
                     q.push(make_pair(newx,newy));
                     ar[newx][newy]=ar[x1][y1]+1;
                     visited[newx][newy]=1;
                   // cout<<"x"<<"y"<<endl;
                 }
           }
         
       }
   }
  
