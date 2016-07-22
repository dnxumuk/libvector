#include "Profiler.h"
#include <iostream>
#include <iomanip>

Profiler::Profiler(std::string msg_first, std::string msg_second) {
  _msg[0] = msg_first;
  _msg[1] = msg_second;
}

Profiler::Profiler(std::string msg_first) {
  _msg[0] = msg_first;
}

void Profiler::StartFirst() {
  _from[0] = std::chrono::high_resolution_clock::now();
}

void Profiler::StopFirst() {
  _to[0] = std::chrono::high_resolution_clock::now();
}

void Profiler::StartSecond() {
  _from[1] = std::chrono::high_resolution_clock::now();
}

void Profiler::StopSecond() {
  _to[1] = std::chrono::high_resolution_clock::now();
}

void Profiler::DisplayResults() {
  std::cout << "---------------- Profiliing results ----------------"    << std::endl
            << "Time for 1-st " << _msg[0] << " " << GetFirstDuration()  << "ms" << std::endl
            << "Time for 2-nd " << _msg[1] << " " << GetSecondDuration() << "ms" << std::endl;
}

void Profiler::DisplaySingleResults() {
  std::cout << "---------------- Profiliing results ----------------" << std::endl
            << "Time for " << _msg[0] << " " << GetFirstDuration() << "ms" << std::endl;
}

void Profiler::DisplayComparedResults() {
  DisplayResults();


  auto time_first = static_cast<float>(GetFirstDuration());
  auto time_second = static_cast<float>(GetSecondDuration());
  float ratio = time_first/time_second;
  std::cout << "Second result is ";
  if (ratio > 1.) {
    double percent = (ratio - 1.) * 100;
    std::cout << std::fixed << std::setprecision(1) << percent << "% faster than first" << std::endl;
  } else if (ratio < 1.) {
    double percent = (100. / ratio) - 100.;
    std::cout << std::fixed << std::setprecision(1) << percent << "% slower than first" << std::endl;
  } else if (ratio == 1.) 
    std::cout << "the same" << std::endl;
}

uint32_t Profiler::GetFirstDuration() {
  return std::chrono::
      duration_cast<std::chrono::milliseconds>(_to[0] - _from[0]).count();
}

uint32_t Profiler::GetSecondDuration() {
  return std::chrono::
      duration_cast<std::chrono::milliseconds>(_to[1] - _from[1]).count();
}
