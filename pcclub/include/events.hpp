#ifndef PCCLUB_EVENTS_HPP
#define PCCLUB_EVENTS_HPP

#include <cstddef>
#include <stdexcept>
#include <string_view>
#include <chrono>
#include <utility>

#include <pcclub/club.hpp>

namespace pc
{
  using time_stamp = std::chrono::hh_mm_ss< std::chrono::hours::rep >;

  template< std::size_t N >
  std::pair< std::string, std::size_t >
  event(club &, time_stamp, std::string_view, std::size_t);
}

template< std::size_t N >
std::pair< std::string, std::size_t >
pc::event(club & ft_club, time_stamp time, std::string_view name, std::size_t = 0)
{
  return std::make_pair("unknown event!", 13);
}

template< >
std::pair< std::string, std::size_t >
pc::event< 1 >(club & ft_club, time_stamp time, std::string_view name, std::size_t = 0)
{
  client ft_client = {
    name,
    time,
    std::nullopt
  };

  try
  {
    club.add_client(ft_client);
  }
  catch (const std::runtime_error & error)
  {
    return std::make_pair(error.what(), 13);
  }

  return std::make_pair(name, 0);
}

template< >
std::pair< std::string, std::size_t >
pc::event< 2 >(club & ft_club, time_stamp time, std::string_view name, std::size_t table)
{
  client ft_client = {
    name,
    std::nullopt,
    std::nullopt
  };

  try
  {
    club.take_table(ft_client, table);
  }
  catch (const std::runtime_error & error)
  {
    return std::make_pair(error.what(), 13);
  }

  return std::make_pair(std::format("{} {}", name, table), 0);
}

template< >
std::pair< std::string, std::size_t >
pc::event< 3 >(club & ft_club, time_stamp time, std::string_view name, std::size_t = 0)
{
  client ft_client = {
    name,
    std::nullopt,
    std::nullopt
  };

  try
  {
    if (club.are_free_tables())
    {
      return std::make_pair("ICanWaitNoLonger", 13);
    }
    if (club.waiting_queue_size() > club.table_amount())
    {
      return std::make_pair("", 11);
    }
  }
  catch (const std::runtime_error & error)
  {
    return std::make_pair(error.what(), 13);
  }

  return std::make_pair(name, 0);
}

template< >
std::pair< std::string, std::size_t >
pc::event< 4 >(club & ft_club, time_stamp time, std::string_view name, std::size_t = 0)
{
  client ft_client = {
    name,
    std::nullopt,
    time
  };

  try
  {
    if (club.pop_client(ft_client) != 0)
    {
      return std::make_pair(name, 12);
    }
  }
  catch (const std::runtime_error & error)
  {
    return std::make_pair(error.what(), 13);
  }

  return std::make_pair(name, 0);
}

template< >
std::pair< std::string, std::size_t >
pc::event< 11 >(club & ft_club, time_stamp time, std::string_view name, std::size_t = 0)
{
  // клиент ушел
}

template< >
std::pair< std::string, std::size_t >
pc::event< 12 >(club & ft_club, time_stamp time, std::string_view name, std::size_t = 0)
{
  // клиент сел за стол
}

template< >
std::pair< std::string, std::size_t >
pc::event< 13 >(club &, time_stamp, std::string_view error, std::size_t = 0)
{
  return std::make_pair(error, 0);
}

#endif
