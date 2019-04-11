#ifndef CELL_H
#define CELL_H

#include <arduino.h>

class Cell
{
  private:
  //byte pos;
  byte walls;
  byte distance;

  public:
  Cell(){};
  Cell(byte d);
  ~Cell(){};

  bool has_north_wall();
  bool has_south_wall();
  bool has_east_wall();
  bool has_west_wall();

  void set_north_wall();
  void set_south_wall();
  void set_east_wall();
  void set_west_wall();

  byte get_distance();
  void set_distance(byte distance);

  // byte x();
  // byte y();
};

#endif
