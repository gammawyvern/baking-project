#include "baker.h"

void* create_baker(void* arg) {
  Baker* baker = (Baker*)arg;
  
  // Setup needed recipes, not sure about a better way tbh
  Recipe cookies = {
    ingredients = [
      Ingredient {
        name = "Flour",
        location = baker->kitchen->pantry
      },
      Ingredient {
        name = "Sugar",
        location = baker->kitchen->pantry
      },
      Ingredient {
        name = "Milk",
        location = baker->kitchen->refridgerator
      },
      Ingredient {
        name = "Butter",
        location = baker->kitchen->refridgerator
      }
    ]
  };

  sem_wait(&(baker->kitchen->mixer));
  printf("[%lu] - Using mixer\n", baker->id);
  sleep(1);
  sem_post(&(baker->kitchen->mixer));

  return NULL;
}

