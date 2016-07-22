#pragma once
#include <xmmintrin.h>
#include "simd_base.h"

//
// Trait specialisation
//
class vector4f;
class vector4fb;

template <>
struct simd_vector_traits<vector4f> {
  using data_type   = float;
  using bool_class = vector4fb;
};

//
// Arithmetics operators pre-declaring
//
vector4f operator+(const vector4f& lhs, const vector4f& rhs);
vector4f operator*(const vector4f& lhs, const vector4f& rhs);
vector4f operator-(const vector4f& lhs, const vector4f& rhs);
vector4f operator/(const vector4f& lhs, const vector4f& rhs);

//
// Class vector for SSExx and float
// It performs basic math operations implementation
//
class vector4f : 
    public simd_base<vector4f>
{
public:
  // Constuctors
  inline vector4f() {
  }
  inline vector4f(float data) : _data(_mm_set1_ps(data)) {
  }
  inline vector4f(float x, float y, float z, float w) : _data(_mm_setr_ps(x,y,z,w)) {
  }
  inline vector4f(const __m128& src) : _data(src) {
  }
  inline vector4f(const vector4f& src) : _data(src._data) {
  }
  inline vector4f& operator=(const __m128& src) {
    _data = src;
    return *this;
  }
  // Type-cast operators
  inline operator __m128() const {
    return _data;
  }
private:
  __m128 _data;
};

// Math implemetation
inline vector4f operator+(const vector4f& lop, const vector4f& rop) {
  return _mm_add_ps(lop, rop);
}

inline vector4f operator-(const vector4f& lop, const vector4f& rop) {
  return _mm_sub_ps(lop, rop);
}

inline vector4f operator*(const vector4f& lop, const vector4f& rop) {
  return _mm_mul_ps(lop, rop);
}

inline vector4f operator/(const vector4f& lop, const vector4f& rop) {
  return _mm_div_ps(lop, rop);
}

// Comparsion
inline vector4fb operator==(const vector4f& lhs, const vector4f& rhs) {
  return _mm_cmpeq_ps(lhs, rhs);
}

inline vector4fb operator!=(const vector4f& lhs, const vector4f& rhs) {
  return _mm_cmpneq_ps(lhs, rhs);
}

inline vector4fb operator<(const vector4f& lhs, const vector4f& rhs) {
  return _mm_cmplt_ps(lhs, rhs);
}

inline vector4fb operator<=(const vector4f& lhs, const vector4f& rhs) {
  return _mm_cmple_ps(lhs, rhs);
}


//
// Class for boolean comparsion
//

class vector4fb :
  public simd_bool_base<vector4fb> {
public:
  inline vector4fb() {
  }
  inline vector4fb(bool val) :
    _data(_mm_castsi128_ps(_mm_set1_epi32(-static_cast<int>(val)))) {
  }
  inline vector4fb(bool val0, bool val1, bool val2, bool val3) :
    _data(_mm_castsi128_ps(_mm_setr_epi32(
      -static_cast<int>(val0),
      -static_cast<int>(val1),
      -static_cast<int>(val2),
      -static_cast<int>(val3)))) {
  };
  inline vector4fb(const __m128& src) :
    _data(src) {
  }
  inline vector4fb& operator=(const __m128& src) {
    _data = src;
    return *this;
  }
  inline operator __m128() const {
    return _data;
  }
private:
  __m128 _data;
};

inline vector4fb operator&(const vector4fb& lop, const vector4fb& rop) {
  return _mm_and_ps(lop, rop);
}

inline vector4fb operator|(const vector4fb& lop, const vector4fb& rop) {
  return _mm_or_ps(lop, rop);
}

inline vector4fb operator^(const vector4fb& lop, const vector4fb& rop) {
  return _mm_xor_ps(lop, rop);
}

inline vector4fb operator~(const vector4fb& rop) {
  return _mm_xor_ps(rop,
    _mm_castsi128_ps(_mm_set1_epi32(-1)));
}

inline vector4fb operator==(const vector4fb& lop, const vector4fb& rop) {
  return _mm_cmpeq_ps(lop, rop);
}

inline vector4fb operator!=(const vector4fb& lop, const vector4fb& rop) {
  return _mm_cmpneq_ps(lop, rop);
}
