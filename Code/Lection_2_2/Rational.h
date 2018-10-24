class Rational
{
 public:
  Rational(int, int);
  void set_number(int, int);
  int get_up_number();
  int get_down_number();
  float real_presentation();
  void print_ratio();
  Rational sum(Rational, Rational);
  Rational prod(Rational, Rational);
  Rational dif(Rational, Rational);
  Rational dev(Rational, Rational);  
 private:
  int up_number;
  int down_number;
};
