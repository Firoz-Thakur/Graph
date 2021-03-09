public:
   
   struct edg{
       int u;
       int v;
       int cost;
   };
 

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<edg> Ed;
	    for(auto v:edges)
	    {
	       edg e; 
	       e.u=v[0];
	       e.v=v[1];
	       e.cost=v[2];
	       Ed.push_back(e);
	    }
	    int dis[n];
	    for(int i=0;i<n;i++)
	    {
	        dis[i]=INT_MAX;
	    }
	    
	   dis[0]=0;
// 	  vector<int> dis(n);
// 	  for(int i=0;i<n;i++)
// 	  {
// 	      cout<<dis[i]<<" ";
// 	  }
	  
	    
	    for(int i=0;i<n;i++)
	    {
	        for(auto e:Ed)
	        {
	            if(dis[e.u] != INT_MAX && dis[e.u]+e.cost<dis[e.v])
	            {
	                dis[e.v]=dis[e.u]+e.cost;
	            }
	            
	        }
	        
	    }
	   //  for(int i=0;i<n;i++)
	   // {
	   // cout<<dis[i]<<" ";
	   // }
	   for(auto e: Ed)
	    {
	        if(dis[e.u] != INT_MAX  && dis[e.u]+e.cost<dis[e.v])
	        return 1;
	    }
	    
	    
	    return 0;
	    
	}
};
