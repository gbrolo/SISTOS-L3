#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

void* create_shm(size_t size) {
    return mmmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
}

int main (int argc, char *argv[]) {
    char x[1];
    int n, size, i;

    n = argv[1]
    x = argv[2]

    //printf("Enter number: ");
    //scanf("%d", &n);

    //printf("Enter letter: ");
    //scanf("%s", x);
    
    //printf("\nYour selections were: %s %d", x, n);  

    size = 128
    void* shm = create_shm(size);

    int pid = fork();

    if (pid == 0) {
        memcpy(shm, x, sizeof(x));
    } else {
        for (i = 0; i < size; i = i + 1 ) {
            if (i % n) {
                memcpy(shm, x, sizeof(x));
            }
        }
        wait(NULL);
        printf("Memory: %s\n", shm);
    }

    return 0;
}
