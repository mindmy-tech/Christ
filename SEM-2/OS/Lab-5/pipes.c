#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pipefd[2]; 
    pid_t cpid;

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    cpid = fork(); // Create a child process

    if (cpid == -1) {
        perror("fork");
        return 1;
    }

    if (cpid == 0) { // Child process
        close(pipefd[1]);
        char buffer[256];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else { 
        close(pipefd[0]);
        write(pipefd[1], "Hello, child!", 14); 
        close(pipefd[1]); 
    }

    return 0;
}