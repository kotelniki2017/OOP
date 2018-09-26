#include<iostream>
using namespace std;
struct lst{
  int data;
  struct lst *next;
};

int main()
{
  lst *a,*b,*c, d;

  a = new  lst;
  b = new  lst;
  c = new  lst;

  cout<<"a.data = "; cin>>a->data;
  cout<<"b.data = "; cin>>b->data;
  cout<<"c.data = "; cin>>c->data;

  a->next = b;
  b->next = c;
  c->next = &d;
  d.data= 666;
  d.next = NULL;

  lst *p;
  p=a;

  while (p != NULL)
    {
      cout << p->data<<endl;
      p=p->next;
    }

  delete [] a;
  delete [] b;
  delete [] c;

  return 0;
}
