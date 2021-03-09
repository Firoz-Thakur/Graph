https://practice.geeksforgeeks.org/problems/bipartite-graph/1

map<int,bool> mp;
 map<int,int> cl;

 bool dfs(int src,vector<int> adj[],int c)
 {
     mp[src]=true;
     cl[src]=c;
     
     for(auto x: adj[src])
     {
         if(mp[x]==false)
         {
             bool y=dfs(src,adj,!c);
             if(y==false)
              return false;
         }
         else if(cl[x]==cl[src])
         {
             return false;
         }
     }
     
     return true;
 }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    // this can be done using the bfs algorithm
	  
	  mp.clear();
	  cl.clear();
	    int c=0;
	   // map<int,bool> mp;
	    //map<int,int> cl;
	   // for(int i=0;i<V;i++)
	   // {
	   //     mp[i]=false;
	   //     cl[i]=-1;
	   // }
	    for(int i=0;i<V;i++)
	    {
	       if(mp[i]==false) 
	        {
	         bool x=dfs(i,adj,c);
	         if(x==false)
	          return false;
 	        }
	    }
	    return true;
}
