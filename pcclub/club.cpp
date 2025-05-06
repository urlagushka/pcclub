#include <pcclub/club.hpp>

pc::club::club(pc::time_stamp open, pc::time_stamp close, std::size_t price)
{}

void
pc::club::add_client(client rhs)
{

}

void
pc::club::pop_client(client rhs)
{

}

void
pc::club::take_table(const client & rhs, std::size_t table)
{

}

void
pc::club::free_table(std::size_t table)
{

}

std::size_t
pc::club::table_size() const
{
  return __table.size();
}

std::size_t
pc::club::client_size() const
{
  return __client.size();
}

bool
pc::club::is_open(const time_stamp & rhs) const
{

}
