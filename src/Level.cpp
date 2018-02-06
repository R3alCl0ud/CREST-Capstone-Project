#include "headers/Level.hpp"

int genNextItem(int seed) {
  // Generate next item based on call to rand
  int nextItem = (int)(ceil((rand() * 4)));

  // 1 is for up, 2 is for down, 3 is for spike, 4 is straight
  // 1 cannot come after 3, and no two values can be the same

  // If the previous item is a spike, the only 2 possibilities are a
  // flat area or a drop down.
  if (seed == 3) return (nextItem % 2 == 0) ? 2 : 4;

  // If the previous item isn't flat, nor a spike, but value is repeated,
  // try again.
  if (seed != 4 && nextItem == seed) return genNextItem(seed);

  // If the previous item is flat, the next item may be anything
  return nextItem;
}
