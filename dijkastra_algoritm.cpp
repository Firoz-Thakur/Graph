https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?company[]=Amazon&company[]=Amazon&page=1&sortBy=submissions&category[]=Graph&query=company[]Amazonpage1sortBysubmissionscompany[]Amazoncategory[]Graph#


vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    unordered_map<int,list<pair<int , int>> > m;
    
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(g[i][j]!=0)
            {
                m[i].push_back(make_pair(j,g[i][j]));
            }
        }
            
    }
 unordered_map<int,int> dist;
 for(int i=0;i<V;i++)
 {
     dist[i]=INT_MAX;
 }
   
   dist[src]=0;
   set<pair<int,int>> s;
   
   s.insert(make_pair(0,src));
   
   while(!s.empty())
   {
     
            auto p=*(s.begin());
            s.erase(s.begin());
            int node=p.second;
            int nodeDist=p.first;

            for(auto neighPair : m[node])
            {
                if(nodeDist + neighPair.second < dist[neighPair.first])
                {
                    int dest =neighPair.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }

                    dist[dest]=nodeDist + neighPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
           
           
    

   }
            
  
  vector<int> v(V);
  for(auto x : dist)
  {
      v[x.first]=x.second;
  }
   
   return v;
   
   //return v;
   
}
