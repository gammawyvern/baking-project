#pragma once

#include <semaphore.h>

typedef struct {
  sem_t mixer;
  sem_t pantry;
  sem_t refrigerator;
  sem_t bowl;
  sem_t spoon;
  sem_t oven;
} Kitchen;

void setup_kitchen(Kitchen* kitchen);
