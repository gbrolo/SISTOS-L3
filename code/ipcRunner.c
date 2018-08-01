#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == 0) {
        execl("./ipc", 1, 'a', (char*)NULL);
    } else {
        execl("./ipc", 2, 'b', (char*)NULL);
    }

    return 0;
}
