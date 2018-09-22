#include<iostream>
using namespace std;
int rand(int n, int k) {
 
     int res = 0;
     for (int i=1; i<=n; ++i)
         res = (res + k) % i;
     return ++res;
 }
 
int main(){
    int n,k;
	{ 
        cout<<"Введите людей и через скольких ";
		cin>>n>>k;
        if (n==0 && k==0) return 0;
        if (n==1) cout<<"1"<<endl;
        else cout<<rand(n,k);
    }
    return 0;
}
