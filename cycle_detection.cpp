bool help(int src,bool *vist,bool *stack,vector<int> adj[])
{
    
    vist[src]=true;
    stack[src]=true;
    
    for(auto nbr:adj[src])
    {
        
        if(stack[nbr]==true)
         return true;
        else if(vist[nbr]==false)
        {
            bool cycle_mila=help(nbr,vist,stack,adj);
            if(cycle_mila==true)
            {
                return true;
            }
        }
    }
    stack[src]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool *vist=new bool[V];
    bool *stack=new bool [V];
    for(int i=0;i<V;i++)
    {
        vist[i]=false;
        stack[i]=false;
    }
    return help(0,vist,stack,adj);

}
