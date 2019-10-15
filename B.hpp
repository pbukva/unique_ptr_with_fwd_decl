#pragma auto

#include <memory>

struct A;

namespace std {
template<>
struct default_delete<A>
{
  void operator ()(A* a) const;
};
}

struct B
{
  std::unique_ptr<A> a;
  B(int x);
};
