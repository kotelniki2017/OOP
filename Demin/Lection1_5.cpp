#include<iostream>
using namespace std;
struct stack{
  int data;
  struct stack *next;
};

int pop(stack * &p)
{
  if (p != NULL)
    {
      
      int a = p->data;
      p=p->next;
      return a;
    }
  else
    return 0;
}

void push(stack * &p, int element)
{
  stack *current;
  current = new stack;
  current->data = element;
  current->next = p;
  p = current;
}

int main()
{
  stack *my_stack=NULL, *current = NULL;
  int key, a;
  do
    {
      cout<<"1 - Добавить в стек, 2 - удалить из стека; 3 - выход"; cin>>key;
      switch (key)
	{
	case 1:
	  cout<<"a="; cin >> a;
	  push(my_stack, a);
	  break;
	case 2:
	  cout<<pop(my_stack)<<endl;
	  break;
	case 3:
	  break;
	default:
	  cout<<"Ошибка ввода"<<endl;
	}
    }
  while (key != 3);

  while (my_stack != NULL)
    {
      current = my_stack->next;
      delete [] my_stack;
      my_stack = current;
    }
  return 0;
}
