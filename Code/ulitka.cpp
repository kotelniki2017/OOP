

class pole
{
public:
  pole(int,int);
  ~pole();
  void left(int, int, int);
  void right(int, int, int);
  void up(int, int, int);
  void down(int, int, int);
private:
  int current_number;
  int count_row;
  int count_column;
  int **array;
};


pole::pole(int a,int b)
{
  current_number=1;
  count_row=a;
  count_column=b;
  array=new int*[count_row];
  for(int i=0; i<a; i++)
    {
      array[i]=new int[count_column];
    }
  }
pole::~pole()
{
  for(int i=0; i<count_row; i++)
    delete [] array[i];
  delete [] array;
}
void pole::right(int a, int b, int c)
{
  for(int i=b; i<=c; i++)
    {
      array[a][i]=current_number;
      current_number++;
    }
}
void pole::left(int a, int b, int c)
{
  for(int i=b; i>=c; i--)
    {
      array[a][i]=current_number;
      current_number++;
    }
}
void pole::up(int a, int b, int c)
{
  for(int i=b; i>=c; i--)
    {
      array[i][a]=current_number;
      current_number++;
    }
}
void pole::down(int a, int b, int c)
{
  for(int i=b; i<=c; i++)
    {
      array[i][a]=current_number;
      current_number++;
    }
}


  
