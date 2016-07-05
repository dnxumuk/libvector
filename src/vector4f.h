#pragma once
#include <xmmintrin.h>

class vector4f
{
public:
  inline vector4f() {}
  inline vector4f(float f) : 
      _data(_mm_set1_ps(f)) {}
  inline vector4f(float f0, float f1, float f2, float f3) : 
      _data(_mm_setr_ps(f0, f1, f2, f3)) {}
  inline vector4f(const __m128& rhs) : 
      _data(rhs) {}

  inline vector4f& operator=(const __m128& rhs) {
    _data = rhs;
    return *this;
  }
  inline vector4f(const vector4f& rhs) : 
    _data(rhs._data) {}
  inline vector4f& operator=(const vector4f& rhs) {
    _data = rhs._data;
    return *this;
  }
  inline operator __m128() const {
    return _data;
  }
  inline vector4f& operator+=(const __m128 rvec) {
    *this = *this + rvec;
    return *this;
  }
private:

  __m128 _data;
};

vector4f operator+(const vector4f& lhs, const vector4f& rhs) {
  return _mm_add_ps(lhs, rhs);
}