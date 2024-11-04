#include "baker.h"

void* create_baker(void* arg) {
  Baker* baker = (Baker*)arg;

  sem_wait(&(baker->kitchen->mixer));
  printf("[%lu] - Using mixer\n", baker->id);
  sleep(1);
  sem_post(&(baker->kitchen->mixer));

  return NULL;
}

