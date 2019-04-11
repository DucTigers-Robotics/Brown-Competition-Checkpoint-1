#ifndef MAZE_H
#define MAZE_H

#define SIZE 16
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

#include "cell.h"
#include <arduino.h>

class Maze
{
  private:
  Cell cells[SIZE][SIZE];
  byte stack[SIZE * SIZE];
  byte head;
  void init_config();

  public:
  Maze();
  ~Maze(){};
  
  void push(byte pos);
  byte pop();

  Cell get_cell(byte row, byte col);
  void set_wall(byte dir, byte row, byte col);
  
  byte x(byte pos);
  byte y(byte pos);

  byte min_accessable_neighbour(byte pos);
  void push_accessable_neighbours(byte row, byte col);
  
  boolean in_range(byte row, byte col);

  byte to_pos(byte row, byte col);

// adjusts the tiles and returns the next tile the robot should go to
  byte flood(byte pos);
};

#endif
