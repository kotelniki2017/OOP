#include<iostream>
using namespace std;

class Complex
{
public:
  Complex(float, float);
  void View();
  Complex Sum(Complex,Complex);
  Complex Minus(Complex,Complex);
  Complex Prod(Complex,Complex);
  Complex Dif(Complex,Complex);
  float get_real();
  float get_image();
  void set_real(float);
  void set_image(float);
private:
  float real;
  float image;
};

Complex::Complex(float alpha, float betta)
{
  real = alpha;
  image = betta;
}

void Complex::View()
{
  cout << "(" << real << ", " << image << ")" << endl;
}

float Complex::get_real()
{
  return real;
}
Complex Complex::Sum(Complex a, Complex b)
{
  Complex current(a.real+b.real,a.image + b.image);
  return current;
}

Complex Complex :: Minus(Complex a, Complex b)
{
  Complex current(a.real-b.real, a.image-b.image);
  return current;
}

Complex Complex :: Prod (Complex a, Complex b)
{
  Complex current(a.real*b.real-a.image*b.image, a.real*b.image+a.image*b.real);
  return current;
}

Complex Complex :: Dif (Complex a, Complex b)
{
  float x, y, z;
  z = b.real*b.real+b.image*b.image;
  x = a.real*b.real+a.image*b.image;
  y = b.real*a.image-a.real*b.image;
  Complex current(x/z, y/z);
  return current;
}

int main()
{
  Complex p1(1,2), p2(2,3), r(0,0);
  p1.View(); p2.View();
  r=r.Sum(p1,p2);
  r.View();
  r=r.Minus(p1,p2);
  r.View();
  r=r.Prod(p1,p2);
  r.View();
  r=r.Dif(p1,p2);
  cout<<r.get_real()<<endl;
  r.View();
  return  0;

}
