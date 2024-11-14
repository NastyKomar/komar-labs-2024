#include "output.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "countExpNegPow2x.h"

void asafov::makeLine(int a, char b)
{
  for (int i = 0; i < a; i++)
  {
    std::cout << b;
  }
  std::cout << '\n';
}

void asafov::writeLine(double x, size_t k, double error)
{
double value = 0;
  try
  {
    value = countExpNegPow2x(x, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << "<MATH ERROR>";
  }
  (x < 0) ? (std::cout << std::fixed << "|") : (std::cout << std::fixed << "| ");
  std::cout << std::fixed << x << " | " << value << " | " << std::exp(-1.0 * right * right) << " | \n";
}

void asafov::output(double left, double right, double step, size_t numberMax, double error)
{
  asafov::makeLine(34, '=');
  std::cout << '\n';
  for (double i = left; i < right; i += step)
  {
    asafov::writeLine(i, numberMax, error);
  }
  asafov::writeLine(right, numberMax, error);
  asafov::makeLine(34, '=');
}
