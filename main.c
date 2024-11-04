#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void* create_baker(void* arg);

sem_t sem;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: ./a.out num_of_bakers\n");
    return 1;
  }

  int num_of_bakers = atoi(argv[1]);
  if (num_of_bakers < 2) {
    printf("\nMust have at least 2 bakers\n");
    return 1;
  }

  sem_init(&sem, 0, 1);

  pthread_t bakers[num_of_bakers];
  for (unsigned long id=0; id<num_of_bakers; id++) {
    int result = pthread_create(&bakers[id], NULL, create_baker, (void*)id);
    if (result != 0) {
      perror("Failed to create thread");
      return 1;
      }
  }

  for (unsigned long id=0; id<num_of_bakers; id++) {
    pthread_join(bakers[id], NULL);
  }

  sem_destroy(&sem);
  return 0;
}

void* create_baker(void* arg) {
  unsigned long id = (unsigned long)arg;

  sem_wait(&sem);
  printf("[%lu] Using resource\n", id);
  sleep(1);
  sem_post(&sem);

  return NULL;
}
