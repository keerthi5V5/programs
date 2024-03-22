#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shmid = shmget(ftok("shm_program", 65), SHM_SIZE, IPC_CREAT | 0666);
    char *shm_ptr = shmat(shmid, NULL, 0);
    printf("Parent process writing to shared memory...\n");
    strncpy(shm_ptr, "Hello from shared memory!", SHM_SIZE);
    printf("Data:%s\n",shm_ptr);
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process reading from shared memory: %s\n", shm_ptr);
        shmdt(shm_ptr);
    } else {
        wait(NULL);
        shmdt(shm_ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

