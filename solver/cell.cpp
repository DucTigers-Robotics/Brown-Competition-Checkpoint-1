#include "cell.h"

Cell::Cell(byte d)
{
  distance = d;
  walls = 0;
}

bool Cell::has_north_wall()
{
  return walls & (1 << 0); 
}


bool Cell::has_south_wall()
{
  return walls & (1 << 1); 
}


bool Cell::has_east_wall()
{
  return walls & (1 << 2); 
}


bool Cell::has_west_wall()
{
  return walls & (1 << 3); 
}

void Cell::set_north_wall()
{
  walls |= (1 << 0);
}

void Cell::set_south_wall()
{
  walls |= (1 << 1);
}

void Cell::set_east_wall()
{
  walls |= (1 << 2);
}

void Cell::set_west_wall()
{
  walls |= (1 << 3);
}

byte Cell::get_distance()
{
  return distance;
}

void Cell::set_distance(byte d)
{
  distance = d;
}

