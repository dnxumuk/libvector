#pragma once

class string;

class NativeVector {
public:
  NativeVector() {};
    NativeVector(float x, float y, float z, float w) :
      x_(x), y_(y), z_(z), w_(w) {};
    void Debug(const std::string &msg);
    // +
    inline NativeVector operator+(float number);
    inline NativeVector operator+(const NativeVector &rvec);
    inline NativeVector& operator+=(const NativeVector &rvec) {
      x_ += rvec.x();
      y_ += rvec.y();
      z_ += rvec.z();
      w_ += rvec.w();
      return *this;
    }
    // -
    inline NativeVector operator-(float number);
    inline NativeVector operator-(const NativeVector &rvec);
    inline NativeVector& operator-=(const NativeVector &rvec) {
      x_ -= rvec.x();
      y_ -= rvec.y();
      z_ -= rvec.z();
      w_ -= rvec.w();
      return *this;
    }

    inline float x() const;
    inline float y() const;
    inline float z() const;
    inline float w() const;
private:
    float x_, y_, z_, w_;
};

// Accessors
float NativeVector::x() const {
  return x_;
}

float NativeVector::y() const {
  return y_;
}

float NativeVector::z() const {
  return z_;
}

float NativeVector::w() const {
  return w_;
}

// Operators
// + 
NativeVector NativeVector::operator+(float number) {
  return NativeVector(number + x_, number + y_, number + z_, number + w_);
}

NativeVector NativeVector::operator+(const NativeVector &rvec) {
  return NativeVector(x_+rvec.x(), y_+rvec.y(), z_+rvec.z(), w_+rvec.w());
}
// -
NativeVector NativeVector::operator-(float number) {
  return NativeVector(number - x_, number - y_, number - z_, number - w_);
}

NativeVector NativeVector::operator-(const NativeVector &rvec) {
  return NativeVector(x_ - rvec.x(), y_ - rvec.y(), z_ - rvec.z(), w_ - rvec.w());
}