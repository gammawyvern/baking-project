
void* create_baker(void* arg) {
  unsigned long id = (unsigned long)arg;

  sem_wait(&sem);
  printf("[%lu] Using resource\n", id);
  sleep(1);
  sem_post(&sem);

  return NULL;
}

