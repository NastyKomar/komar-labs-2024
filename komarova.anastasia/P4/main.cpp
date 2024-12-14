#include <iostream>
#include "change.h"
#include "dynamic.h"
#include <cstddef>
int main
{
  size_t size_str = 20, size_str_now = 0;
  char* str = komarova::read(std::cin, size_str, size_str_now, '\n');
  if (str == nullptr)
  {
    std::cerr << "No memory allocated or incorrect parameters \n";
    return 1;
  }
  if (size_str_now == 0)
  {
    free(str);
    std::cerr << "Empty string \n";
    return 1;
  }
  char* str_res = reinterpret_cast< char* >(malloc((size_str_now + 1) * sizeof(char)));
  if (str_res == nullptr)
  {
    free(str);
    std::cerr << "No memory allocated \n";
    return 1;
  }
  str_res[size_str_now] = '\0';
  str_rep = komarova::rep_sym(str, str_res);
  std::cout << str_rep << "\n";
  std::cout << komarova::vowels(const char * str, char * str_res) << "\n";
  free(str);
  free(str_res);
}