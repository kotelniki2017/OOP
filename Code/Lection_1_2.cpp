#include<iostream>
#include<stdlib.h>
using namespace std;
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
  int **a, **b;
  int n,m;
  cout<<"Введите размерность массивов"<<endl;
  cout<<"n= ";
  cin>>n;
  cout<<"m= ";
  cin>>m;
  a = new int *[n];b = new int *[m];
  for (int i=0;i<n;i++) a[i] = new int [m];
  for (int i=0;i<m;i++) b[i] = new int [n];
  zap(n, m, a); printing(n,m,a);
  for(int i=0; i<n;i++)
    {
      for(int j=0; j<m; j++)
	b[j][i]=a[i][j];
    }
  cout<<endl;2
  printing(m, n, b);
  return 0;
}
  
