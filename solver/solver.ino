#include "maze.h"

Maze maze = Maze();
byte mouse_row = 4;
byte mouse_col = 0;

void print_maze()
{
  for (int row = 0; row < 5; row++)
  {
    for (int col = 0; col < 5; col++)
    {
      Serial.print(maze.get_cell(row, col).get_distance());
      Serial.print(" ");
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
  Serial.println();
//
  byte next;
  while(maze.get_cell(mouse_row, mouse_col).get_distance() != 0)
  {
    next = maze.flood(maze.to_pos(mouse_row, mouse_col));
    mouse_row = maze.y(next);
    mouse_col = maze.x(next);
    Serial.print(mouse_row);
    Serial.print(" ");
    Serial.print(mouse_col);
    
Serial.println();
//    
  }
//
Serial.println();
Serial.println("FINAL");
  print_maze();
  
  delay(5000);
}
