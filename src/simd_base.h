#pragma once
//
//  Traits
//
template <class X>
struct simd_vector_traits;
//
//  Class for vector
//
template <class T>
class simd_base {
public:
  using value_type = simd_vector_traits<T>::data_type;

  inline T& operator()() { 
    return *static_cast<T*>(this); }

  inline const T& operator()() const { 
    return *static_cast<const T*>(this); }

  inline T& operator+=(const T& rhs) {
    (*this)() = (*this)() + rhs;
    return (*this)();
  }
  inline T& operator+=(const value_type& rhs) {
    (*this)() = (*this)() + T(rhs);
    return (*this)();
  }
  // Increment operators
  inline T operator++(int) {
    T tmp = (*this)();
    (*this) += value_type(1);
    return tmp;
  }
  inline T& operator++() {
    (*this)() += value_type(1);
    return (*this)();
  }
protected:
  inline simd_base() {
  }
  inline ~simd_base() {
  }
  inline simd_base(const simd_base&) {
  }
  inline simd_base& operator=(const  simd_base&) { 
    return *this; 
  }
};

//
// Class for boolean operations
//


template <class T>
class simd_bool_base {
public:
  inline       T& operator()() {
    return *static_cast<T*>(this);
  }

  inline const T& operator()() const {
    return *static_cast<const T*>(this);
  }

  inline T& operator&=(const T& rop) {
    (*this) = (*this) && rop;
    return (*this)();
  }

  inline T& operator|(const T& rhs) {
    (*this)() = (*this) || rhs;
    return (*this)();
  }

  inline T& operator^=(const T& rhs) {
    (*this)() = (*this)() ^ rhs;
    return (*this)();
  }
protected:
  inline simd_bool_base() {
  }
  inline ~simd_bool_base() {
  }
  inline simd_bool_base(const simd_bool_base&) {
  }
  inline simd_bool_base& operator=(const simd_bool_base&) {
    return *this;
  }
};

// Logical and operators
template <class T>
inline T operator&&(const simd_bool_base<T>& lop, const simd_bool_base<T>& rop) {
  return lop() & rop();
}

template <class T>
inline T operator&&(const simd_bool_base<T>& lop, bool rop) {
  return lop() & rop;
}

template <class T>
inline T operator||(bool lop, const simd_bool_base<T>& rop) {
  return lop & rop();
}

template <class T>
inline T operator!(const simd_bool_base<T>& rop) {
  return rop() == 0;
}


template <class T>
inline simd_base<T> operator+(const simd_base<T>& lhs, const simd_vector_traits<T>::type& rhs) {
  return lhs() + T(rhs);
}

template <class T>
inline simd_base<T> operator+(const simd_vector_traits<T>::type& lhs, const simd_base<T>& rhs) {
  return T(lhs) + rhs();
}


