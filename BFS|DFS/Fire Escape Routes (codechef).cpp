problem: find the number of connected component
posible ways to chose a node to select from the graph ( simple multiplication of no of nodes in earch complenent) (and=ans*connected_componenet_size)


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(long long int src,unordered_map<long long int,bool> &visit,map<long long int ,list<long long int>> &adj,long long int &cnt)
{
    cnt++;
    visit[src]=true;
    for(auto nbr: adj[src])
    {
        if(visit[nbr]==false)
        {
            dfs(nbr,visit,adj,cnt);
        }
    }
}



int main() {
	// your code goes her
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,m;
	    cin>>n>>m;
	    map<long long int,list<long long int>> adj;
	    for(long long int i=0;i<m;i++)
	    {
	        long long int x,y;
	        cin>>x>>y;
	        adj[x].push_back(y);
	        adj[y].push_back(x);
	    }
	   unordered_map<long long int ,bool>visit;
	   for(long long int i=1;i<n;i++)
	   {
	      visit[i]=false;
	   }
	   
	  long long int c=0;
	  long long int ans=1;
	  long long int cnt;
	  for(long long int i=1;i<=n;i++)
	  {
	      cnt=0;
	      if(visit[i]==false)
	      {
	          dfs(i,visit,adj,cnt);
	          c++;
	          ans=ans*cnt;
	          ans=ans%1000000007;
	      }
	  }
	 cout<<c<<" "<<ans<<endl;   
	    
	}
	
	
	return 0;
}
