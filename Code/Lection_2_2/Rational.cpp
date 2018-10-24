#include<iostream>
#include "Rational.h"

using namespace std;

Rational::Rational(int a, int b)
{up_number = a; down_number = b;}

Rational::set_number(int a, int b)
{up_number = a; down_number = b;}

Rational::get_up_number()
{return up_number;}

Rational::get_down_number()
{return down_number;}

Rational::real_presentation()
{return (float)up_number/down_number;}

Rational::print_ration()
{cout<<up_number<<"/"<<down_number;}

