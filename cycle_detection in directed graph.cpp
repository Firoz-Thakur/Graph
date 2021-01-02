https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#




bool help(int src,vector<int> adj[],bool &visit,bool &st)
{

   visit[src]=true; 
   st[src]=true;
   
   for(auto nbr : adj[src])
   {
      if(st[nbr]==true)
       return true;
      else if(!visit[nbr])
      {
          bool cycle_mila=help(nbr,adj,visit,st);
          if(cycle_mila==true)
           return true;
      }
   }
    
  st[src]=false;
  return false;

}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
   
      bool *visit=new bool[V];
      bool *stk=new bool[V];
      
      for(int i=0;i<V;i++)
      {
        stk[i]=false;
        visit[i]=false;
      }  
      
     for(int i=0;i<V;i++)
     {
       if(visit[i]==false){
        bool x=help(i,adj,visit,stk);
        if(x==true)
         return 1;
       }
    }
   
return 0;
}
