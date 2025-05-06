#ifndef PCCLUB_CLUB_HPP
#define PCCLUB_CLUB_HPP

#include <chrono>
#include <unordered_map>
#include <optional>
#include <string_view>

#include <pcclub/client.hpp>

namespace pc
{
  using time_stamp = std::chrono::hh_mm_ss< std::chrono::hours::rep >;

  class club
  {
    public:
      club() = delete;
      club(time_stamp open, time_stamp close, std::size_t price);

      bool add_client(std::string_view name);
      bool pop_client(std::string_view name);

      bool take_table(const client & rhs, std::size_t table);
      bool free_table(std::size_t table);
      bool is_open(const time_stamp & rhs) const;

    private:
      std::vector< client > __inside;
      std::unordered_map< std::size_t, std::optional< client > > __tables;

      time_stamp __open;
      time_stamp __close;

      std::size_t __price;
  };
}

#endif
