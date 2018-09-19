#include<iostream>
#include<stdlib.h>
using namespace std;
void matrixc(int n, int m, int k, int **a, int **b, int **c)
{
  int s=0;
  for(int i=0; i<n; i++)
    {
      for(int j=0; j<k; j++)
	{
	  s=0;
	  for(int l=0; l<m; l++)
	    s+=a[i][l]*b[j][l];
	  c[i][j]=s;
    }
  }
}
void zap(int n, int m, int **ar)
{
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) ar[i][j] = rand() %9;
}

void printing(int n, int m, int **ar)
  {
  for(int i=0; i<n; i++)
    {for(int j=0; j<m; j++) cout<<ar[i][j]<<"  ";
      cout<<endl;
    }
  }
main()
{
  int **a, **b, **c;
  int n,m,k;
  cout<<"Введите размерность массивов"<<endl;
  cout<<"n= ";
  cin>>n;
  cout<<"m= ";
  cin>>m;
  cout<<"k=";
  cin>>k;
  a = new int *[n];b = new int *[m];c=new int *[n];
  for (int i=0;i<n;i++) c[i] = new int [m];
  for (int i=0;i<n;i++) a[i] = new int [m];
  for (int i=0;i<m;i++) b[i] = new int [k];
  zap(n, m, a); printing(n,m,a);
  cout<<endl;
  zap(m, k, b); printing(m, k, b);
  cout<<endl;
  matrixc(n, m, k, a, b, c); printing(n, k, c);
  return 0;
}
  
