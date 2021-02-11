https://leetcode.com/problems/course-schedule-ii/submissions/


public:
    vector<int> findOrder(int n, vector<vector<int>>& mp) {
    int temp=n;
    int *indeg=new int[n];
    map<int, list<int>> adj;
    for(int i=0;i<n;i++)
    {
        indeg[i]=0;
    }
        
    for(auto x: mp)
    {
      adj[x[1]].push_back(x[0]);
      indeg[x[0]]++;
    }
        
    vector<int> v2;
   
   queue<int>q;
   for(int i=0;i<n;i++)
   {
       if(indeg[i]==0)
         q.push(i);
   }
    int c=0;
    vector<int> v;
     while(!q.empty()) 
     {
        int x=q.front();
        q.pop();
        v.push_back(x);
        c++;
        for(auto nbr: adj[x])
        {
            indeg[nbr]--;
            if(indeg[nbr]==0)
                q.push(nbr);
        }
     }
      cout<<c; 
    if(c==temp)
        return v;
    else
        return v2;
    }
};





