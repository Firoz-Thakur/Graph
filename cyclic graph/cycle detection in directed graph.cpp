

# using topological sorting 1: )
	bool isCyclic(int V, vector<int> adj[]) {
   
     int indeg[V]={0};
  
     for(int i=0;i<V;i++)
     {
         for(auto x : adj[i])
         {
             indeg[x]++;
         }
     }
     queue<int> q;
     for(int i=0;i<V;i++)
     {
         if(indeg[i]==0)
         {
             q.push(i);
         }
     }
     int c=0;
     while(!q.empty())
     {
         int x=q.front();
         c++;
         q.pop();
         for(auto nbr : adj[x])
         {
             indeg[nbr]--;
             if(indeg[nbr]==0)
             {
                 q.push(nbr);
                 
             }
         }
     }
     if(c!=V)
      return true;
     else
      return false;
    
	}
# using the DFs, simple store the call stack and find if there any neighbour which is already in the call stack ,if it is it means there is a cycle



    unordered_map<int,bool> mp;
    unordered_map<int,bool> stck;
 
   bool dfs(int src,vector<int> adj[])
   {
       mp[src]=true;
       stck[src]=true;
    
      for(auto nbr: adj[src])
      {
         if(stck[nbr]==true)
          return true;
         else if(mp[nbr]==false)
         {
             bool cycle_mila=dfs(nbr,adj);
             if(cycle_mila==true)
              return true;
         }
      }
      
      stck[src]=false;
      return false;
    }
	
	
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	stck.clear();
	   	mp.clear();
	   //	bool *stck=new bool[V];
	   //	bool *mp=new bool[V];
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    stck[i]=false;
	   	    mp[i]=false;
	   	}
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(mp[i]==false)
	   	    {
	   	        bool mila=dfs(i,adj);
	   	        if(mila==true)
	   	         return mila;
	   	    }
	   	}
	   	return false;
	}
	
	
