#pragma once
#include <chrono>
#include <string>

class Profiler
{
public:
  Profiler(std::string msg_first ,std::string msg_second);
  Profiler(std::string msg_first);

  void StartFirst();
  void StopFirst();
  void StartSecond();
  void StopSecond();

  void DisplayResults();
  void DisplaySingleResults();
  void DisplayComparedResults();
  ~Profiler() {};

private:
  uint32_t GetFirstDuration();
  uint32_t GetSecondDuration();

  const static size_t _compared_obj_amount = 2;
  std::string _msg[_compared_obj_amount];
  std::chrono::time_point<std::chrono::steady_clock> _from[_compared_obj_amount];
  std::chrono::time_point<std::chrono::steady_clock> _to[_compared_obj_amount];
};

