#include<iostream>
using namespace std;
main()
{
  int n;
  cout<<"n=";
  cin>>n;
  int *a;
  a=new int[n];
  for(int i=2; i<=n; i++)
    {
      a[i]=i;
    }
  for(int p=0; p<n; p++)
    {
      if(a[p]!=0)
	{
	  s=p+a[p];
	  while(int s<n)
	    {
	      a[s]=0;
	      s+=a[p];
	    }
	}
    }
}
