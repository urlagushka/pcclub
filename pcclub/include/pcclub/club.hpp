#ifndef PCCLUB_CLUB_HPP
#define PCCLUB_CLUB_HPP

#include <chrono>
#include <unordered_map>
#include <optional>

#include <pcclub/client.hpp>
#include <pcclub/time.hpp>

namespace pc
{
  class club
  {
    public:
      club() = delete;
      club(time_stamp open, time_stamp close, std::size_t price);

      void add_client(client rhs);
      void pop_client(client rhs);

      void take_table(const client & rhs, std::size_t table);
      void free_table(std::size_t table);

      std::size_t table_size() const;
      std::size_t client_size() const;

      bool is_open(const time_stamp & rhs) const;

    private:
      std::vector< client > __client;
      std::unordered_map< std::size_t, std::optional< client > > __table;

      time_stamp __open;
      time_stamp __close;

      std::size_t __price;
  };
}

#endif
