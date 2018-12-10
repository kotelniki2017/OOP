#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class array{
    friend ostream & operator<< (ostream &, array &);
    friend istream & operator>> (istream &, array &);
    friend array & operator+(array &, array&);
public:
    int & operator [] (int);
    array & operator++();
    array & operator++(int);
    array & operator+=(int);
    array & operator=(array &);
    bool operator ==(array &);
    void filling_random(void);
    const int get_size();
    array(int);
    array(array &);
    ~array();
private:
    int size;
    int *mass;
};
array current(1);

array::array(int n)
{
    size = n;
    mass = new int [size];
    for(int i=0; i<size; i++) mass[i]=0;
}
array & operator+(array &ar1, array &ar2)
{
    current=((ar1.get_size()<ar2.get_size())?ar2:ar1);
    for (int i=0;i<current.get_size();i++)
    {
        if((i<ar1.get_size())&&(i<ar2.get_size()))
            current[i]=ar1[i]+ar2[i];
        if((i<ar1.get_size())&&(i>=ar2.get_size()))
            current[i]=ar1[i];
        if((i>=ar1.get_size())&&(i<ar2.get_size()))
            current[i]=ar2[i];
    }
    return current;
}
array::array(array & copy)
{
    size=copy.get_size();
    mass=new int [size];
    for(int i =0; i<size; i++) mass[i]=copy[i];
}
bool array::operator==(array&ar2)
{
    if(size==ar2.get_size()){
        bool pr=true;
        for(int i=0; i<ar2.get_size();i++)
            if((mass[i])!=(ar2[i])){
                pr=false;
                break;
            }
        return pr;
    }
    else
        return false;
}
array & array::operator=(array & ar)
{
    size=ar.get_size();
    delete [] mass;
    mass=new int [size];
    for(int i=0;i<this->size;i++)this->mass[i]-ar[i];
    return *this;
}
array::~array(void)
{
    delete [] this->mass;
}

const int array::get_size()
{
    return this->size;
}
int & array::operator[](int n)
{
    if(n<size)
        return mass[n];
    else{
        if(n<0)
            return mass[0];
        else
            return mass[size-1];
    }
}
ostream & operator<<(ostream&output, array&arr){
    for(int i=0;i<arr.size;i++)
        output<<(arr[i])<<"; ";
    output<<endl;
}
istream & operator>>(istream & input, array &arr)
{
    cout<<"array size:";
    cin>>arr.size;
    delete [] arr.mass;
    arr.mass=new int[arr.size];
    for(int i =0;i<arr.size;i++)
    {
        cout<<"element"<<i<<": ";
        cin>>arr[i];}
}
array&array::operator++()
{
    for(int i=0;i<size;i++)
        mass[i]++;
    return *this;
}
array&array::operator++(int)
{
    current=*this;
    for(int i=0;i<size;i++)
        mass[i]++;
    return current;
}
array&array::operator+=(int value)
{
    for(int i=0;i<size;i++)
        mass[i]+=value;
    return *this;
}
void array::filling_random()
{
    for(int i=0; i<size;i++) mass[i]=rand()&100+1;
}

int main()
{
    srand(time(NULL));
    array x(10), y(5), z(5);
    x.filling_random();
    y.filling_random();
    cout<<x<<y;
    z=x+y;
    cout<<z;
    cout<<z++;
}
