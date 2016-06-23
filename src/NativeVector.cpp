#include <string>
#include <iostream>
#include "NativeVector.h"

void NativeVector::Debug(const std::string &msg)
{
  std::cout << msg << " [" <<
    x_ << "," << 
    y_ << "," <<
    z_ << "]" << std::endl;
}
