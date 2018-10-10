#include<iostream>
using namespace std;
struct two_list{
int data;
	struct two_list *next;
	struct two_list *prev;
};
void add_first(two_list *&p, int a, two_list *&tail)
{
two_list *current=new two_list;
	if(p!=NULL)
	{
	current->data=a;
	current->next=p;
	current->prev=NULL;
	p->prev=current;
		p=current;
	}
	else
	{
	current->data=a;
	current->next=p;
	current->prev=NULL;
	p=current;
		tail=p;
	}
}
void add_last(two_list *&p1, two list *&p2, int a)
{
two_list *current=new two_list;
	if(p2!=NULL)
	{
	current->data=a;
		current->prev=p2;
		current->next=NULL;
		p2->next=current;
		p2=current;
	}
	else
	{
	current->data=a;
	current->prev=p2;
	current->next=NULL;
	p2=current;
	p1=p2;
	}
}
int main()
{
two_list *first = NULL, *last = NULL;
  return 0;
}