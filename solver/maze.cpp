#include "maze.h"

Maze::Maze()
{
  init_config();
  
  head = 0;
}

void Maze::init_config()
{
  byte base = 14;
  byte midlo = 7;
  byte midhi = 8;
  byte offset = 0;

  for (byte row = 0; row < SIZE; row++)
  {
    offset = 0;
    if (row <= midlo)
    {
      offset = row;
    }
    else if (row >= midhi)
    {
      base = row - 1;
    }

    for (byte col = 0; col < SIZE; col++)
    {
      if (col <= midlo)
      {
        cells[row][col] = Cell(base - col - offset);
      }
      else if (col >= midhi)
      {
        cells[row][col] = Cell(base - midlo + (col - midhi) - offset);
      }
    }
  }
}

void Maze::push(byte pos)
{
  stack[head] = pos;
  head += 1;
}

byte Maze::pop()
{
  head -= 1;
  byte pos = stack[head];
  return pos;
}

Cell Maze::get_cell(byte row, byte col)
{
  return cells[row][col];
}

void Maze::set_wall(byte dir, byte row, byte col)
{
  switch(dir)
  {
    case NORTH:
    cells[row][col].set_north_wall();
    break;
    case SOUTH:
    cells[row][col].set_south_wall();
    break;
    case EAST:
    cells[row][col].set_east_wall();
    break;
    case WEST:
    cells[row][col].set_west_wall();
    break;
  }
}

boolean Maze::in_range(byte row, byte col)
{
  if (!(row >= 0 && row < SIZE))
  {
    return false;
  }
  if (!(col >= 0 && col < SIZE))
  {
    return false;
  }
  return true;
}

byte Maze::to_pos(byte row, byte col)
{
  byte pos = row;
  pos <<= 4;
  pos += col;
  return pos;
}

byte Maze::min_accessable_neighbour(byte pos)
{
// todo: make sure these are in range
  byte row = y(pos);
  byte col = x(pos);
  
  Cell c = cells[row][col];
  byte min_distance = 255;
  byte distance;
  byte champion_pos = 0;
  
  if (!c.has_north_wall())
  {
    if (in_range(row-1, col))
    {
       distance = cells[row-1][col].get_distance();
      if (distance < min_distance)
      {
        min_distance = distance;
        champion_pos = to_pos(row -1, col);
      } 
    }
  }
  if (!c.has_east_wall())
  {
    if (in_range(row, col + 1))
    {
      distance = cells[row][col+1].get_distance();
      if (distance < min_distance)
      {
        min_distance = distance;
        champion_pos = to_pos(row, col+1);
      }
    }
  }
  if (!c.has_south_wall())
  {
    if (in_range(row + 1, col))
     {
      distance = cells[row+1][col].get_distance();
      if (distance < min_distance)
      {
        min_distance = distance;
        champion_pos = to_pos(row + 1, col);
      }
     }
  }
  if (!c.has_west_wall())
  {
    if (in_range(row, col-1))
    {
      distance = cells[row][col-1].get_distance();
      if (distance < min_distance)
      {
        min_distance = distance;
        champion_pos = to_pos(row, col-1);
      }
    }
  }
  return champion_pos;
}

byte Maze::x(byte pos)
{
  pos <<= 4;
  return pos >> 4;
}

byte Maze::y(byte pos)
{
  return pos >> 4;;
}

void Maze::push_accessable_neighbours(byte row, byte col)
{
  if (!cells[row][col].has_north_wall())
  {
    push(to_pos(row-1, col));
  }
  if (!cells[row][col].has_east_wall())
  {
    push(to_pos(row, col+1));
  }
  if (!cells[row][col].has_south_wall())
  {
    push(to_pos(row+1, col));
  }
  if (!cells[row][col].has_west_wall())
  {
    push(to_pos(row, col-1));
  }
}

byte Maze::flood(byte pos)
{
  // push onot stack
  push(pos);

  // while not empty

  byte cur_pos;
  Cell cur_cell;
  byte min_dist;
  byte min_pos;

  // flood the maze
  while (head > 0)
  {
    cur_pos = pop();
    cur_cell = cells[y(cur_pos)][x(cur_pos)];
    min_pos = min_accessable_neighbour(cur_pos);
    min_dist = cells[y(min_pos)][x(min_pos)].get_distance();

    if (cur_cell.get_distance() == min_dist + 1)
    {
      continue;
    }

// maze.cells[cur_cell.row][cur_cell.col].d = maze.get_min(cur_cell) + 1
    cells[y(cur_pos)][x(cur_pos)].set_distance(min_dist + 1);
    push_accessable_neighbours(y(cur_pos), x(cur_pos));
    
  }

  // return the next position to travel too
  return min_accessable_neighbour(cur_pos);
}





