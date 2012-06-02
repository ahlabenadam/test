/*
 * shmget1.c
 *
 *  Created on: Jun 1, 2012
 *      Author: aka_w
 */

#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#define SHM_PERM (IPC_CREAT | IPC_EXCL)
#define SIZE 256
#define KEY  0xabcd
#define CONT_SIZE 10

struct container {
    pthread_t th;
    int i;
};

void start(void* arg) {
    int shmfd;

    struct container *p_cont = (struct container*)arg;
    shmfd = shmget(KEY, SIZE, SHM_PERM);
    if (shmfd ==  -1)  {
        fprintf(stderr, "Error: %d\n", errno);
        return;
    }
    fprintf(stderr, "Container %d initialized\n", p_cont->i);
}

int main(int argc, char* argv[]) {
    int i;
    struct container   cont[CONT_SIZE];

    for(i=0;i<CONT_SIZE;i++) {
        cont[i].i=i;
        fprintf(stderr, "Starting index :%d\n", i);
        pthread_create(&cont[i].th, NULL, start, &cont[i]);
    }
    getchar();
    for(i=0;i<CONT_SIZE;i++) {
        int *err;
        pthread_join(cont[i].th, &err);
    }
    shmctl(KEY, IPC_RMID, NULL);
    return 0;
}
