#ifndef PC_CLUB_CLIENT_HPP
#define PC_CLUB_CLIENT_HPP

#include <chrono>
#include <optional>
#include <string>

namespace pc
{
  using time_stamp = std::chrono::hh_mm_ss< std::chrono::hours::rep >;

  struct client
  {
    std::string name;

    std::optional< time_stamp > in_time;
    std::optional< time_stamp > out_time;
  };
}

#endif
