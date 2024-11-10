#include "string.hpp"

char * mozhegova::inputString(std::istream & in, char stop)
{
  size_t length = 10;
  char * str = nullptr;
  try
  {
    str = new char [length];
  }
  catch(const std::bad_alloc & e)
  {
    throw;
  }
  char next = '\0';
  std::noskipws(std::cin);
  for (size_t size = 0; (std::cin >> next) && (next != stop); size++)
  {
    if (size == length)
    {
      str = mozhegova::changeSize(str, length);
    }
    str[size] = next;
  }
  std::skipws(std::cin);
  return str;
}

char * mozhegova::changeSize(char * nowstr, size_t length)
{
  char * newstr = nullptr;
  try
  {
    newstr = new char [length + 10];
  }
  catch(const std::bad_alloc & e)
  {
    delete[] nowstr;
    throw;
  }
  for (size_t i = 0; i < length; i++)
  {
    newstr[i] = nowstr[i];
  }
  delete[] nowstr;
  return newstr;
}