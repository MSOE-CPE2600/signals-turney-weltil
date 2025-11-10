/**
 * File: server.c
 * Modified by: Larissa Welti
 * Course: CPE 2600 121
 * Brief summary of program: Serves a signal to the reciever program
  and recieves signals from the reciever program
 */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>


void handle_signal(int sig, siginfo_t *info, void *context){
    pid_t pid3 = info->si_value.sival_int /100;
    int volley = info->si_value.sival_int %100;
    union sigval value;
    
    if(volley == 10){
        exit(0);
    } else{
        value.sival_int = getpid()*100 + volley+1;
        printf("\007");
        printf("Server hitting the ball\n");
        int wait_time = rand() % 100;
        sleep(1+0.01*wait_time);
        sigqueue(pid3, SIGUSR1, value);
    }
}

int main(int argc, char* argv[]){
    struct sigaction sa;
    sa.sa_sigaction = &handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);

    pid_t pid = atoi(argv[1]);
    int pid2 = getpid();
    union sigval value;
    value.sival_int = pid2*100;
    sigqueue(pid, SIGUSR1, value);
    while(1){
        
    }
    return 0;
}