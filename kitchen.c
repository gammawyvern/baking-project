#include "kitchen.h"

void setup_kitchen(Kitchen* kitchen) {
  sem_init(&(kitchen->mixer), 0, 2);
  sem_init(&(kitchen->pantry), 0, 1);
  sem_init(&(kitchen->refrigerator), 0, 2);
  sem_init(&(kitchen->bowl), 0, 3);
  sem_init(&(kitchen->spoon), 0, 5);
  sem_init(&(kitchen->oven), 0, 1);
}

