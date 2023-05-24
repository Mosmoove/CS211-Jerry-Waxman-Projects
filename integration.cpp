#include <iostream>
#include <cmath>
using namespace std;

typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b)
{
   double sum = 0;
   double small_base = 0.0001;
   double x = a;

   while (x < b)
   {
      // f(x) represents the height
      // small_base represents the width of the rectangle
      sum += f(x) * small_base;
      x += small_base;
   }
   return sum;
}

double line(double x)
{
   return x;
}
double square(double x)
{
   return x * x;
}
double cube(double x)
{
   return x * x * x;
}

int main()
{

   cout << "The area of f(x) = x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
   cout << "The area of f(x) = x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
   cout << "The area of f(x) = x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;

   return 0;
}