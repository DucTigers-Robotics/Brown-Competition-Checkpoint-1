#include "maze.h"

Maze maze = Maze();
byte mouse_row = 4;
byte mouse_col = 0;

void print_maze()
{
  for (int row = 0; row < 16; row++)
  {
    for (int col = 0; col < 16; col++)
    {
      Serial.print(maze.get_cell(row, col).get_distance());
      Serial.print("\t");
    }
    Serial.println();
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setting up");
}

void loop() {

  Serial.println("INITNIAL");
  print_maze();

  
  delay(50000);
}
