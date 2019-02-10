#ifndef _GUARD_EVENT_HPP_
#define _GUARD_EVENT_HPP_

#include <chrono>
#include <string>

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

class GuardEventVisitor {
  virtual void visit(WentToSleep const sleep) = 0;
  virtual void visit(WakeUp const wake_up) = 0;
  virtual void visit(BeginShift const begin_shift) = 0;
};

class GuardEvent {
 protected:
  TimePoint const time_point;
  GuardEvent() = delete;
  GuardEvent(TimePoint const t) : time_point{t} {};

 public:
  static GuardEvent const from_str(std::string const &str);
};

class WentToSleep : public GuardEvent {
  friend class GuardEvent;
 private:
  WentToSleep() = delete;
  WentToSleep(TimePoint const t) : GuardEvent(t){};
};

class WakeUp : public GuardEvent {
  friend class GuardEvent;
 private:
  WakeUp() = delete;
  WakeUp(TimePoint const t) : GuardEvent(t){};
};

class BeginShift : public GuardEvent {
  friend class GuardEvent;
 private:
  int const guardId;

 public:
  BeginShift(int const gid, TimePoint const t) : GuardEvent(t), guardId{gid} {};
};

#endif