#pragma once
#include <vector>

template<typename T> T rand_val() {
  const int distribution = 10'000;
  const size_t accuracy = 10;
  return static_cast<T>((rand() % distribution) / accuracy);
};

template<typename TData_type,typename T>
void InitializeVector( std::vector<T> &vector) {
  for ( auto& item : vector)
    item = T(rand_val<TData_type>(), 
             rand_val<TData_type>(),
             rand_val<TData_type>(),
             rand_val<TData_type>());
}

template<typename TData_type>
void InitializeVectorsAsRandom() {
}

template<typename TData_type,typename TFirst, typename ...T>
void InitializeVectorsAsRandom( TFirst& current_arg, T& ...others_args) {
    InitializeVector<TData_type>(current_arg);
    InitializeVectorsAsRandom<TData_type>(others_args...);
}
