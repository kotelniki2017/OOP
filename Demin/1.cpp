#include <iostream>
#include<iostream>
using namespace std;
int main()
{
int n;
	cout<<"Введите размерность массива n=";
	cin>>n;
	int *h;
	h=new int[n];
	srand(time(0));
	for(int i=0; i<n; i++)
	{
		h[i]=1+rand()%100;
		cout<<h[i]<<endl;
	}
	delete [] h;
	return 0;
}

