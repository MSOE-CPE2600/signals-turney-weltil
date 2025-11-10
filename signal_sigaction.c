/**
 * File: signal_sigaction.c
 * Modified by: Larissa Welti
 * 
 * Brief summary of program:
    This program waits for a USR1 signal
    and prints the PID of the signal when it is recieved
    To send a signal you should pause the program with CTRL+Z
    then send the signal with kill -USR1 PID where you put the 
    PID gotten from calling ps
 */

 #include <stdio.h>
 #include <stddef.h>
 #include <signal.h>


void handle_signal(int sig, siginfo_t *info, void *context){
    printf("Signal process ID:%ld\n", (long)info->si_pid);
}

int main(){
    

    struct sigaction sa;
    sa.sa_sigaction = &handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);

    while(1){

    }

    return 0;
}
