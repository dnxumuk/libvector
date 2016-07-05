#include <iostream>
#include <vector>
#include "NativeVector.h"
#include "vector4f.h"
#include "Utility.h"

using vec = NativeVector;
void testPlus(size_t);

float _rnd() {
  return rand_val<float>();
}

int main()
{
  vec a(0., 0., 0.,0.);
  vec b(1., 2., 3.,4.);
  auto c = a + b;
  testPlus(900000);
  system("pause");
  return 0;
}

void testPlus(size_t count) {
  std::vector<NativeVector> lop(count);
  std::vector<NativeVector> rop(count);
  for (size_t i = 0; i < count; ++i) {
    lop[i] = NativeVector(_rnd(), _rnd(), _rnd(), _rnd());
    rop[i] = NativeVector(_rnd(), _rnd(), _rnd(), _rnd());
  }
  NativeVector result;
  for (size_t i = 0; i < count; ++i) {
    result = lop[i] + rop[i];
  }
}

