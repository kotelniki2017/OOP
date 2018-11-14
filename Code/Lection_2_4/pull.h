class node
{
 public:
  node();
  void set_next(node*);
  void set_prev(node*);
  void set_value(int value);
  node* get_next();
  node* get_prev();
  int get_value();
 private:
  int value;
  node* next;
  node* prev;
};
class list
{
 public:
  list(int);
  ~list();
  void show_list();
  // node get_list(int);
  void add_node_begin(int);
  /*
  node add_node_end(int);
  node del_node_begin(int);
  node del_node_end(int);
  */
  node get_top();
  node get_last();
  
 private:
  int n;
  node* top;
  node* last;
};
    
