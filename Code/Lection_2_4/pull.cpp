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
  
  node * current;
  current = new node;
  current->set_value(x);
  top=current;
  last=current;
}

list::~list()
{
  node * current_del, *current_next;
  current_del = top;
  while (current_del != NULL)
    {
      current_next = current_del->get_next();
      delete current_del;
      current_del = current_next;
    }
  cout<<"It's ok!";
  
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
  node * current;
  current = new node;
  current->set_value(x);
  current->set_next(top);
  top->set_prev(current);
  top=current;
}
void list::show_list()
{
  node *x;
  x=top;
  while(x != NULL)
    {
      cout<<x->get_value()<<"->";
      x=x->get_next();
    }
  cout<<endl;
}
