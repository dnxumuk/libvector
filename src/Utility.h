#pragma once
template<class T> T rand_val() {
  const int distribution = 10'000;
  const size_t accuracy = 10;
  return static_cast<T>((rand() % distribution) / accuracy);
};