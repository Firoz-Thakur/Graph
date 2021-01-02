
https://practice.geeksforgeeks.org/problems/topological-sort/1#


vector<int> ordering;
 //vector<int> v;
 map<int,bool> vist;
    
void dfs(int src,vector<int> adj[])
{
   
   vist[src]=true;
   for(int nbr : adj[src])
   {
       if(!vist[nbr])
       {
           dfs(nbr,adj);
       }
   }
      
  ordering.push_back(src);    
  
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    
   
    
    for(int i=0;i<V;i++)
    {
        vist[i]=false;
    }
    
for(int i=0;i<V;i++)
{
  if(!vist[i])
    dfs(i,adj);
 
}  
  reverse(ordering.begin(),ordering.end()); // we can also use the liest and can performe the list.push_front operation.
    return ordering;
    
 
}

Bfs :


vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    
    vector<int> v;
    queue<int> q;
 
    int *indegree=new int[V]; 
   for(int i=0;i<V;i++)
   {
       indegree[i]=0;
       
   }
   for(int i=0;i<V;i++)
   {
       for(auto  z : adj[i])
       {
           indegree[z]++;
       }
   }
   for(int i=0;i<V;i++)
   {
       if(indegree[i]==0)
       {
           q.push(i);
       }
   }
   while(!q.empty())
   {
       int x=q.front();
       q.pop();
       v.push_back(x);
       
       for(int nbr : adj[x])
       {
           indegree[nbr]--;
           if(indegree[nbr]==0)
            q.push(nbr);
       }
   }
  
    
    return v;
}



