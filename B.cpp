#include "B.hpp"
#include <iostream>

struct A
{
  int x_{-1};

  A(int x);
  ~A();
};

A::A(int x) : x_{x}
{
  std::cout << "A::A(" << x_ << ")" << std::endl;
}

A::~A()
{
  std::cout << "A::~A(): x = " << x_ << std::endl;
}

namespace std {
void default_delete<A>::operator()(A *a) const
{
  delete a;
}
}

B::B(int x) : a{new A{x}}
{}
