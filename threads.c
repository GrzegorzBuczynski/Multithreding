#include <pthread.h>

void *funkcja_watku(void *arg) {
  // Kod wykonywany przez wątek
  for (int i = 0; i < 10; i++) {
    printf("Wątek: %d\n", i);
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t tid;
  int err;
  int err2;

  // Tworzenie wątku
  err = pthread_create(&tid, NULL, funkcja_watku, NULL);
   err2 = pthread_create(&tid, NULL, funkcja_watku, NULL);
  if (err != 0) {
    printf("Błąd tworzenia wątku: %s\n", strerror(err));
    return 1;
  }
    if (err2 != 0) {
    printf("Błąd tworzenia wątku: %s\n", strerror(err));
    return 1;
  }

  // Oczekiwanie na zakończenie wątku
  pthread_join(tid, NULL);

  printf("Wątek zakończony\n");
  return 0;
}
