public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    
    vector<int> st;
    int visit[5001];
    
    void dfs1(int src,vector<int> adj[])
    {
        visit[src]=1;
        for(int nbr : adj[src])
        {
            if(visit[nbr]==0)
            {
                dfs1(nbr,adj);
            }
        }
        
     st.push_back(src);    
    }
    
     void dfs2(int src,map<int,list<int>> &adj) //without passing through the reference it is giving tle
    {
        visit[src]=1;
        for(int nbr : adj[src])
        {
            if(visit[nbr]==0)
            {
                dfs2(nbr,adj);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        //code here
        map<int, list<int> > mp;
        
        for(int i=0;i<V;i++)
        {
            for(int nbr: adj[i])
            {
                mp[nbr].push_back(i);
            }
        }
        
        st.clear();
     //   visit.clear();
        for(int i=0;i<V;i++)
        {
            visit[i]=0;
        }
        
        // chose any random vertax and apply the dfs
        for(int i=0;i<V;i++)
        {
            if(visit[i]==0)
            {
                dfs1(i,adj);
            }
        }
        //now apply the dfs on reversed graph ,, 
        for(int i=0;i<V;i++)
        {
            visit[i]=0;
        }
        
        int c=0;
        
        for(int i=st.size()-1;i>=0;i--)
        {
            if(visit[st[i]]==0)
            {
                dfs2(st[i],mp);
                c++;
            }
        }
     return c;   
    }
};
