#include<iostream>
#include "pull.h"
using namespace std;
node::node()
{
  value=0;
  next=NULL;
  prev=NULL;
}
int node::get_value()
{
  return value;
}
node* node::get_prev()
{
  return prev;
}
node* node::get_next()
{
  return next;
}
void node::set_next(node* p)
{
  next=p;
}
void node::set_prev(node* p)
{
  prev=p;
}
void node::set_value(int x)
{
  value=x;
}
list::list(int x)
{
  node current;
  current.set_value(x);
  top=&current;
  last=&current;
}
node list::get_top()
{
  return *top;
}
node list::get_last()
{
  return *last;
}
void list::add_node_begin(int x)
{
  node current;
  current.set_value(x);
  current.set_next(top);
  top->set_prev(&current);
  top=&current;
  cout<<top<<endl<<last<<endl;
}
void list::show_list()
{
  node *x;
  x=top;
  while(x != last)
    {
      cout<<x->get_value()<<"->";
      x=x->get_next();
    }
  cout<<endl;
}
