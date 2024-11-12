#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  

int main() {
    key_t key = ftok("shmfile", 65);  
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT); 
    char* message = (char*) shmat(shmid, NULL, 0);  

    printf("Enter message to write to shared memory: ");
    fgets(message, SHM_SIZE, stdin); 

    printf("Server: Message written to shared memory: %s\n", message);
    getchar();  

    shmdt(message);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 

int main() {
    key_t key = ftok("shmfile", 65);  
    int shmid = shmget(key, SHM_SIZE, 0666); 
    char* message = (char*) shmat(shmid, NULL, 0); 

    printf("Client: Message read from shared memory: %s\n", message);

    shmdt(message); 
    return 0;
}
