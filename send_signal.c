/**
 * File: send_signal.c
 * Modified by: Larissa Welti
 * 
 * Brief summary of program:
 */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
    pid_t pid = atoi(argv[1]);
    srand(time(NULL));
    int send = rand();
    union sigval value;
    printf("Random value: %d\n", send);
    value.sival_int = send;
    sigqueue(pid, SIGUSR1, value);
    return 0;
}