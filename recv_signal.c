/**
 * File: recv_signal.c
 * Modified by: Larissa Welti
 * 
 * Brief summary of program:
 */
  #include <stdio.h>
 #include <stddef.h>
 #include <signal.h>


void handle_signal(int sig, siginfo_t *info, void *context){
    printf("Recieved signal %d with value %d\n", sig, info->si_value.sival_int);
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