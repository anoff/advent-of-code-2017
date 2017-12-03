#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int x;
    int y;
} tuple;

// number of elements in one specific ring
int ring_elements (int id) {
  if ( id  > 0) {
    return 2 * (id * 2 + 1) + 2 * ((id - 1) * 2 +1);
  } else {
    return 1;
  }
}

// cumulative sum of elements until ring ID
int sum_ring_elements (int id) {
  int sum = 0, i;
  for (i = 0; i <= id; i++) {
    sum += ring_elements(i);
  }
  return sum;
}

// calculate manhattan distance
int distance (tuple pos) {
  return abs(pos.x) + abs(pos.y);
}
int main (int argc, char *argv[]) {
  // printf("%d, %d, %d\n", ring_elements(0), ring_elements(2), sum_ring_elements(2));

  if ( argc < 2 || (argc >= 2 && !strcmp(argv[1], ""))) {
    printf("Please provide memory location as argument\n");
    return 1;
  }
  int goal = atoi(argv[1]);

  tuple mem [ goal ];

  int ring = 0; // which is the currently active ring
  int i;
  tuple cur = {0,0}; // current position
  tuple dir = {1, 0}; // direction to move in the next step: x, y

  for ( i = 0; i <= goal; i++ ) {
    mem[i] = cur;
    // printf("mem[%d]: %d, %d\n", i, cur.x, cur.y);
    // step forward
    cur.x += dir.x;
    cur.y += dir.y;

    // check if ring is filled
    if ( i + 1 >= sum_ring_elements(ring) ) { // bottom right corner
      dir.x = 0;
      dir.y = 1;
      ring++;
    } else if (cur.y == ring && dir.y > 0) { // top right corner
      dir.x = -1;
      dir.y = 0;
    } else if (cur.x == -ring && dir.x < 0) { // top left corner
      dir.x = 0;
      dir.y = -1;
    } else if (cur.y == -ring && dir.y < 0) { // bottom left corner
      dir.x = 1;
      dir.y = 0;
    }
  }

  printf("Pos(%d) = %d,%d\n", goal, mem[goal - 1].x, mem[goal - 1].y);
  printf("Distance(%d) = %d\n", goal, distance(mem[goal - 1]));

  return 0;
}