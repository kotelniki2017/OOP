

  #include <iostream>

using namespace std;

class Complex
{
public:
  Complex(float, float);
  Complex plus  (Complex, Complex);
  Complex minus (Complex, Complex);
  Complex proiz (Complex, Complex);
  Complex delen (Complex, Complex);
  float   getReal(){return real;};
  float   getIma(){return ima;};
  void    input();
  void    show();
private:
  float  real;
  float  ima;
};
Complex :: Complex (float a, float b){real = a; ima = b;}
Complex Complex::plus(Complex a, Complex b) 
{
  return Complex(a.getReal() + b.getReal(), a.getIma() + b.getIma());
}
Complex Complex::minus(Complex a, Complex b) 
{
  return Complex(a.getReal() - b.getReal() , a.getIma() - b.getIma());
}
Complex Complex::proiz(Complex a, Complex b) 
{
  return Complex(a.getReal() * b.getReal() - a.getIma() * b.getIma(), a.getReal() * b.getIma() + a.getIma() * b.getReal() );
}
Complex Complex::delen(Complex a, Complex b) 
{
  return Complex((a.getReal() * b.getReal() + a.getIma()  * b.getIma())/(b.getReal() * b.getReal() + b.getIma() * b.getIma()), (a.getIma() * b.getReal() + a.getReal() * b.getIma())/(b.getReal() * b.getReal() + b.getIma() * b.getIma()));
}


void Complex :: input()
{
  cout<<"input real"<<endl;
  cin >> real;
  cout<<"input Ima"<<endl;
  cin >> ima;
}

void Complex :: show()
{
  cout<<real<<"+"<<ima<<"*I"<<endl;
}

int main()
{
  Complex a(1,3),b(2,4),c(0,0);
  a.input();
  b.input();
  c= b.plus(a,b);
  c.show();
}

  

