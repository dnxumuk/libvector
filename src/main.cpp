#include <iostream>
#include <vector>
#include "NativeVector.h"
#include "vector4f.h"
#include "Utility.h"
#include "Profiler.h"

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
  testPlus(1'000'000'0);
  system("pause");
  return 0;
}

void testPlus(size_t count) {
  Profiler prf("native vec add", "SIMD vec add");
  // native
  {
    std::vector<NativeVector> lop(count);
    std::vector<NativeVector> rop(count);
    InitializeVectorsAsRandom<float>(lop, rop);
    
    NativeVector result;
    /*for (size_t i = 0; i < count; ++i) {
      lop[i] = NativeVector(_rnd(), _rnd(), _rnd(), _rnd());
      rop[i] = NativeVector(_rnd(), _rnd(), _rnd(), _rnd());
    }*/
    prf.StartFirst();
    for (size_t i = 0; i < count; ++i) {
      result += (lop[i] + rop[i]);
    }
    prf.StopFirst(); 
    std::cout << result.w();
  }

  // SIMD
  {
    std::vector<vector4f> lop(count);
    std::vector<vector4f> rop(count);
    vector4f result;
    for (size_t i = 0; i < count; ++i) {
      lop[i] = vector4f(_rnd(), _rnd(), _rnd(), _rnd());
      rop[i] = vector4f(_rnd(), _rnd(), _rnd(), _rnd());
    }
    prf.StartSecond();
    for (size_t i = 0; i < count; ++i) {
      result += (lop[i] + rop[i]);
    }
    prf.StopSecond();
    std::cout << (result ? 1: 0);
  }
  prf.DisplayComparedResults();
}

void testMinus(size_t count) {
  Profiler prf("native vec add", "SIMD vec add");
  // native
  {
    std::vector<NativeVector> lop(count);
    std::vector<NativeVector> rop(count);

    NativeVector result;
    for (size_t i = 0; i < count; ++i) {
      lop[i] = NativeVector(_rnd(), _rnd(), _rnd(), _rnd());
      rop[i] = NativeVector(_rnd(), _rnd(), _rnd(), _rnd());
    }
    prf.StartFirst();
    for (size_t i = 0; i < count; ++i) {
      result -= (lop[i] - rop[i]);
    }
    prf.StopFirst();
    std::cout << result.w();
  }

  // SIMD
  {
    std::vector<vector4f> lop(count);
    std::vector<vector4f> rop(count);
    vector4f result;
    for (size_t i = 0; i < count; ++i) {
      lop[i] = vector4f(_rnd(), _rnd(), _rnd(), _rnd());
      rop[i] = vector4f(_rnd(), _rnd(), _rnd(), _rnd());
    }
    prf.StartSecond();
    for (size_t i = 0; i < count; ++i) {
      result += (lop[i] + rop[i]);
    }
    prf.StopSecond();
    std::cout << (result ? 1 : 0);
  }
  prf.DisplayComparedResults();
}


