#include <stdio.h>
#include <pthread.h>
void *printOddNumbers(void *arg) {
    printf("Child thread (Odd numbers): ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}
void *printEvenNumbers(void *arg) {
    printf("Child thread (Even numbers): ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}
void *printMultiplesOf3(void *arg) {
    printf("Child thread (Multiples of 3): ");
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}
void *printMultiplesOf5(void *arg) {
    printf("Child thread (Multiples of 5): ");
    for (int i = 1; i <= 10; i++) {
        if (i % 5 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}
int main() {
    pthread_t tid1, tid2, tid3, tid4;
    pthread_create(&tid1, NULL, printOddNumbers, NULL);
    pthread_create(&tid2, NULL, printEvenNumbers, NULL);
    pthread_create(&tid3, NULL, printMultiplesOf3, NULL);
    pthread_create(&tid4, NULL, printMultiplesOf5, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    return 0;
}
