https://www.hackerrank.com/challenges/journey-to-the-moon/copy-from/203561484

unordered_map<int,bool> visit;


void dfs(long long int src,unordered_map<long long int,list<long long int> > &astronaut,long long int &size)
{
    visit[src]=true;
    size++;
    for(auto nbr:astronaut[src])
    {
        if(visit[nbr]==false)
         dfs(nbr,astronaut,size);
    }
}
long long int  journeyToMoon(int n, vector<vector<int>> astronaut) {
  
  unordered_map<long long int,list<long long int> > graph;
    for(auto v: astronaut)
    {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
        
    }
  visit.clear();
  for(long long int i=0;i<n;i++)
  {
      visit[i]=false;
  }
  vector<long long int> v;
  long long int size=0;
  for(int i=0;i<n;i++)
  {   size=0;
      if(visit[i]==false)
      {
          dfs(i,graph,size);
          v.push_back(size);
      }
      
  }
  long long int  ans=0;
  long long int pre[v.size()];
  pre[v.size()-1]=v[v.size()-1];
  for(long long int i=v.size()-1;i>0;i--)
  {
      pre[i-1]=pre[i]+v[i-1];
      
  }
  for(long long int i=0;i<v.size()-1;i++)
  {
      ans+=v[i]*pre[i+1];
  }
  
 return ans;
}
