#include <pcclub/time.hpp>

#include <chrono>
#include <string>
#include <format>
#include <sstream>
#include <iomanip>

std::istream &
pc::operator>>(std::istream & in, time_stamp & ts)
{
  std::string tmp;
  in >> tmp;

  ts.hours = std::chrono::hours(std::stoi(tmp.substr(0, 2)));
  ts.minutes = std::chrono::minutes(std::stoi(tmp.substr(3, 5)));

  return in;
}

std::ostream &
pc::operator>>(std::ostream & out, const time_stamp & ts)
{
  out << std::setfill('0') << std::setw(2) << ts.hours.count() << ":";
  out << std::setfill('0') << std::setw(2) << ts.minutes.count() << "\n";
  return out;
}
