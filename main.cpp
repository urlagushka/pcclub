#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>

#include <pcclub/events.hpp>
#include <pcclub/club.hpp>
#include <pcclub/client.hpp>

int main(int argc, char ** argv)
{
  std::filesystem::path src = "/Users/urlagushka/Documents/pcclub/src.txt";
  std::ifstream in(src);

  std::size_t table = 0;
  pc::time_stamp open;
  pc::time_stamp close;
  std::size_t price = 0;

  in >> table;
  in >> std::chrono::parse("%H:%M", open);
  in >> std::chrono::parse("%H:%M", close);
  in >> price;

  if (!in)
  {
    std::cerr << "input error! (init stage)\n";
    return 1;
  }

  while (in)
  {
    pc::time_stamp tmp;
    std::size_t event_id = 0;
    std::string str_data = "";
    std::size_t sub_data = 0;

    in >> std::chrono::parse("%H:%M", tmp);
    in >> event_id;
    in >> client_name;

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
      [str_data, event_id] = event< event_id >(club, tmp, str_data, sub_data);
    }
    std::cout << std::format("{} {} {}\n", tmp, event_id, str_data);
  }

  return 0;
}
