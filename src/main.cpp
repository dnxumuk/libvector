#include <iostream>
#include <vector>
#include "NativeVector.h"

using vec = NativeVector;
void testPlus(size_t);

int main()
{
  vec a(0., 0., 0.);
  vec b(1., 2., 3.);
  auto c = a + b;
  testPlus(900000);
  system("pause");
  return 0;
}

void testPlus(size_t count) {
  std::vector<NativeVector> lop(count);
  std::vector<NativeVector> rop(count);
  for (size_t i = 0; i < count; ++i) {
    lop[i] = NativeVector( (rand()%1000)/10 , (rand() % 1000) / 10 , (rand() % 1000) / 10);
    rop[i] = NativeVector((rand() % 1000) / 10, (rand() % 1000) / 10, (rand() % 1000) / 10);
  }
  NativeVector result;
  for (size_t i = 0; i < count; ++i) {
    result = lop[i] + rop[i];
  }
}

