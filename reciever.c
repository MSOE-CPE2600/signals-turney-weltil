/**
 * File: reciever.c
 * Modified by: Larissa Welti
 * Course: CPE 2600 121
 * Brief summary of program: Recieves signal from the 
 server and sends signals back to the server
 */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void handle_signal(int sig, siginfo_t *info, void *context){
    pid_t pid = info->si_value.sival_int /100;
    int volley = info->si_value.sival_int %100;
    union sigval value;
    
    if(volley == 10){
        value.sival_int = 10;
        printf("I missed the ball!\n");
        sigqueue(pid, SIGUSR1, value);
        exit(0);
    } else{
        value.sival_int = getpid()*100 + volley+1;
        printf("\007");
        printf("Reciever hitting the ball\n");
        int wait_time = rand() % 100;
        sleep(1+0.01*wait_time);
        sigqueue(pid, SIGUSR1, value);
    }
}

int main(int argc, char* argv[]){
    struct sigaction sa;
    sa.sa_sigaction = &handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);

    while(1){
        
    }
    return 0;
}