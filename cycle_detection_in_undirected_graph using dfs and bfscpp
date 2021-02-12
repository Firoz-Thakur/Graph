https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

Example:
Input:
3
2 1
0 1
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
0
0
1

Explanation:
Testcase 1: There is a graph with 2 vertices and 1 edge from 0 to 1. So there is no cycle.
Testcase 2: There is a graph with 3 vertices and 3 edges from 0 to 1, 1 to 2 and 2 to 3.
Testcase 3: There is a cycle in the given graph formed by vertices 2, 3 and 4.



bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   
   map<int,bool> visit;
   
   int *par=new int[V];
   
    
  for(int i=0;i<V;i++)
  {
    par[i]=i; 
    visit[i]=false;
      
  }  

 for(int i=0;i<V;i++)
 {
  if(!visit[i])
  { 
   queue<int> q;
   q.push(i);
   visit[i]=true;
  
   while(!q.empty())
   {
       int x=q.front();
       q.pop();
       
       for(int nbr : g[x])
       {
          if(visit[nbr]==true && par[x]!=nbr)
          {
              return 1;
          }
          else if(!visit[nbr])
          {
              visit[nbr]=true;
              par[nbr]=x;
              q.push(nbr);
          }
       }
   }
 }
 }
   
   return 0;
}


// using dfs

class Solution {
public:
 
  bool dfs(int src,int par,unordered_map<int,bool> &mp,vector<int> g[])
  {
     mp[src]=true;
     
     for(auto nbr:g[src])
     {
         if(mp[nbr]==false)
         {
            bool x=dfs(nbr,src,mp,g);
            if(x==true)
             return true;
         }
         else if(nbr!=par)
         {
             return true;
         }
     }
     return false;
        
  }
 
  bool isCycle(int V, vector<int> g[]){
	    // Code here
//cycle can be detected using bfs and connected componet logic
 
 
     unordered_map<int,bool> visit;
     for(int i=0;i<V;i++)
     {
         visit[i]=false;
     }
    
     for(int i=0;i<V;i++)
     {
         if(visit[i]==false)
         {
             bool x=dfs(i,i,visit,g);
             if(x==true)
              return true;
         }
     }
     
     return false;
	}
};
