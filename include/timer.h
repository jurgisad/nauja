#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include <iostream>
#include <chrono>
#include <vector>

class Timer {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
      return std::chrono::duration<double>
(std::chrono::high_resolution_clock::now() - start).count();
  }
};

class Timer2 {
  // panaudojame using
  using hrClock = std::chrono::high_resolution_clock;
  using durationDouble = std::chrono::duration<double>;
  private:
    std::chrono::time_point<hrClock> start;
  public:
    Timer2() : start{ hrClock::now() } {}
    void reset() {
      start = hrClock::now();
    }
    double elapsed() const {
      return durationDouble (hrClock::now() - start).count();
    }
};


#endif // TIMER_H_INCLUDED
