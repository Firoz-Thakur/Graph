unordered_map<int,bool> visit;

   bool dfs(int src,int p,vector<int> adj[])
   {
       visit[src]=true;
       for(auto nbr:adj[src])
       {
           if(!visit[nbr])
           {
               bool cycle_mila=dfs(nbr,src,adj);
               if(cycle_mila==true)
                return true;
           }
           else if(nbr!=p || nbr==src)
           {
               return true;
           }
           
       }
       return false;
   }

	bool isCycle(int V, vector<int>adj[]){
	    // Code here
   	    visit.clear();
   	    for(int i=0;i<V;i++)
   	    {
   	        if(!visit[i])
   	        {
   	            bool mila=dfs(i,-1,adj);
   	            if(mila==true)
   	             return true;
   	        }
   	    }
	    return false;
	   
	}
};
