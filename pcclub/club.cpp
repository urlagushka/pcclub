#include <pcclub/club.hpp>

#include <algorithm>

pc::club::club(pc::time_stamp open, pc::time_stamp close, std::size_t price, std::size_t table):
  __client(0),
  __table(table, std::nullopt),

  __open(open),
  __close(close),

  __price(price)
{}

void
pc::club::add_client(const client & rhs)
{
  if (is_client_inside(rhs))
  {
    throw std::runtime_error("YouShallNotPass");
  }

  if (!is_open(rhs.time.in_time.value()))
  {
    throw std::runtime_error("NotOpenYet");
  }

  __client[rhs.name] = rhs.time;
}

void
pc::club::pop_client(const client & rhs)
{

}

void
pc::club::take_table(const client & rhs, std::size_t table)
{
  if (!is_client_inside(rhs))
  {
    throw std::runtime_error("ClientUnknown");
  }

  if (__table[table].has_value())
  {
    throw std::runtime_error("PlaceIsBusy");
  }

  auto old_place = std::find_if(__table.begin(), __table.end(), [rhs](std::optional< client > & lhs)
  {
    if (lhs.has_value())
    {
      if (lhs.value().name == rhs.name)
      {
        return true;
      }
    }

    return false;
  });

  if (old_place != __table.end())
  {
    *old_place = std::nullopt;
  }

  __table[table] = rhs;
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
  return (rhs > __open && rhs < __close);
}

bool
pc::club::is_client_inside(const client & rhs) const
{
  auto found = __client.find(rhs.name);
  return found != __client.end();
}

void
pc::club::verify_client(const client & rhs)
{
  

  
  
  if (rhs.time.out_time.has_value())
  {
    if (!is_open(rhs.time.out_time.value()))
    {
      throw std::runtime_error("NotOpenYet");
    }
  }
}
