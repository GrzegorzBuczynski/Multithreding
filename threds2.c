#include <pthread.h>

void *funkcja_watku(void *arg) {
  // Kod wykonywany przez wątek
  printf("Wątek: %d\n", (int)arg);
  return NULL;
}

int main() {
  pthread_t tid;
  int err;

  // Tworzenie wątku
  err = pthread_create(&tid, NULL, funkcja_watku, (void *)10);
  if (err != 0) {
    printf("Błąd tworzenia wątku: %s\n", strerror(err));
    return 1;
  }

  // Oczekiwanie na zakończenie wątku
  pthread_join(tid, NULL);

  printf("Wątek zakończony\n");
  return 0;
}
