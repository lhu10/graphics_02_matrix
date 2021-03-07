#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

void draw_eye(struct matrix *points, int x, int y, int z){
  add_edge(points, x, y, z, x, y+20, z);
  add_edge(points, x, y+20, z, x+10, y+30, z);
  add_edge(points, x+10, y+30, z, x+30, y+30, z);
  add_edge(points, x+30, y+30, z, x+40, y+20, z);
  add_edge(points, x+40, y+20, z, x+40, y, z);
}

void draw_frog(struct matrix *frogs, int x, int y, int z){
  add_edge(frogs, x, y, z, x+125, y, z);
  add_edge(frogs, x, y, z, x+40, y+45, z);
  draw_eye(frogs, x+40, y+45, z);
  add_edge(frogs, x+80, y+45, z, x+145, y+45, z);
  draw_eye(frogs, x+145, y+45, z);
  add_edge(frogs, x+145+40, y+45, z, x+250, y-25, z);
  add_edge(frogs, x, y, z, x+45, y-40, z);
}

int main() {

  struct matrix *m1;
  struct matrix *m2;

  m1 = new_matrix(4, 4);
  m2 = new_matrix(4, 2);

  printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");
  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix(m2);
  printf("\n");

  printf("Testing ident. m1 =\n");
  ident(m1);
  print_matrix(m1);
  printf("\n");

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m2);
  printf("\n");

  printf("Testing Matrix mult. m1 =\n");
  add_edge(m1, 1, 2, 3, 4, 5, 6);
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  print_matrix(m1);
  printf("\n");

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m2);
  
  free_matrix(m1);
  free_matrix(m2);

  screen s;
  clear_screen(s);
  color c; 
  struct matrix *frogs;
  frogs = new_matrix(4, 4);
  c.red = 0; 
  c.green = 180;
  c.blue = 0; 

  int x = 250; 
  int y = 250; 
  int z = 0; 

  draw_frog(frogs, x, y, z);
  draw_frog(frogs, x, y-110, z);
  draw_frog(frogs, x, y-220, z);
  draw_frog(frogs, x, y+110, z);
  draw_frog(frogs, x, y+220, z);
  draw_frog(frogs, x-230, y+50, z);
  draw_frog(frogs, x-230, y+50+220, z);
  draw_frog(frogs, x-230, y+50+110, z);
  draw_frog(frogs, x-230, y+50-110, z);
  draw_frog(frogs, x-230, y+50-220, z);
  draw_frog(frogs, x-230, y+50-330, z);
  draw_frog(frogs, x-460, y-10, z);
  draw_frog(frogs, x-460, y-10-110, z);
  draw_frog(frogs, x-460, y-10-220, z);
  draw_frog(frogs, x-460, y-10+110, z);
  draw_frog(frogs, x-460, y-10+220, z);

  draw_lines(frogs, s, c);
  
  display(s);
  save_extension(s, "frogvibe.png");
  free_matrix(frogs);

} 
