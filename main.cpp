#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <format>
#include <locale>

#include <pcclub/events.hpp>
#include <pcclub/club.hpp>
#include <pcclub/client.hpp>
#include <pcclub/time.hpp>

int main(int argc, char ** argv)
{
  std::filesystem::path src = "/Users/urlagushka/Documents/pcclub/src.txt";
  std::ifstream in(src);

  std::size_t table = 0;
  pc::time_stamp open{};
  pc::time_stamp close{};
  std::size_t price = 0;

  in >> table >> open >> close >> price;

  if (!in)
  {
    std::cerr << "input error! (init stage)\n";
    return 1;
  }

  pc::club club(open, close, price);
  while (in)
  {
    pc::time_stamp time{};
    std::size_t event_id = 0;
    std::string str_data;
    std::size_t sub_data = 0;

    in >> time >> event_id >> str_data;
    if (event_id == 2)
    {
      in >> sub_data;
    }

    if (!in)
    {
      std::cerr << "input error! (process stage)\n";
      return 1;
    }

    while (event_id != 0)
    {
      auto event_out = event_call(event_id, club, time, str_data, sub_data);
      str_data = event_out.first;
      event_id = event_out.second;
    }
    std::cout << std::format("{} {} {}\n", time, event_id, str_data);
  }

  return 0;
}
