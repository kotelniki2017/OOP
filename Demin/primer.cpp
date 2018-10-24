#include <iostream>
using namespace std;
class Rational
{
public:
	Rational();
	void Operation(float, float, float, char);
	private:
	float num;
	float upnum;
	float downnum;
	char OP;
};
Rational::Rational() {num=upnum=downnum=OP=0;}
void Rational::Operation(float n, float u, float d, char o)
{
	cout<<"Print num: ";
while(o!=1)	
{
cin>>u>>d;
cin>>o;
if(o='+')
{
n+=(u/d);
cout<<n<<endl;
}
if(o='-')
{
n-=(u/d);
cout<<n<<endl;
}
if(o='*')
{
n*=(u/d);
cout<<n<<endl;
}	
if(o='/')
{
n/=(n/d);
cout<<n<<endl;
}
}
	cout<<"= ";
cout<<n<<endl;	
}
int main()
{
Rational p;
	p.Operation(0, 0, 0, 0);
	return 0;
}