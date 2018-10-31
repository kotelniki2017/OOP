#include<iostream>
#include<stdlib.h>
#include "pull.h"
using namespace std;
int main()
{
  srand(time(NULL));
  int n;
  cout<<"Cколько узлов хотите ввести?"<<endl;
  cin>>n;
  list T(rand()%100);
  for(int i=0; i<n-1; i++)
    {
      T.add_node_begin(rand()%100);
    }
  T.show_list();
  return 0;
}
