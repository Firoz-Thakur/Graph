https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1#

int find(int a[],int x)
{
       //add code here
    if(a[x]==x)
     return x; 
      
     return a[x]=find(a,a[x]); 
       
       
}
void unionSet(int a[],int x,int z)
{
	//add code here.
	int ab=find(a,x);
	int b=find(a,z);
	if(ab!=b)
	{
	    a[ab]=b;
	}
}
