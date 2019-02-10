#include "guard_event.hpp"
#include <exception>
#include <ctime>
#include <iomanip>
#include <regex>

std::regex wake_up_matcher{"^\[(.*?)\]\s+wakes\s+up$"};
std::regex fall_asleep_matcher{"^\[(.*?)\]\s+falls\s+asleep$"};
std::regex begins_shift_matcher{
    "^\[(.*?)\]\s+Guard\s+#(\d+)\s+begins\s+shift$"};

TimePoint parse_time(std::string const& str);

GuardEvent const GuardEvent::from_str(std::string const& str) {
  std::smatch matched;
  std::regex_match(str, matched, wake_up_matcher);

  if (!matched.empty()) {
    return WakeUp{parse_time(matched[1].str())};
  }

  std::regex_match(str, matched, fall_asleep_matcher);

  if (!matched.empty()) {
    return WentToSleep{parse_time(matched[1].str())};
  }

  std::regex_match(str, matched, begins_shift_matcher);

  if (!matched.empty()) {
    return BeginShift {
      std::stoi(matched[2].str()), parse_time(matched[1].str())
    };
  }

  throw "Could not parse the input";
}

TimePoint parse_time(std::string const& str) {
  std::tm tm = {};
  std::stringstream ss{str};
  ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
  return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}