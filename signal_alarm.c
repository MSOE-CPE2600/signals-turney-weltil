/**
 * File: signal_alarm.c
 * Modified by: Larissa Welti
 * 
 * Brief summary of program:
    sends an alarm signal after 5 seconds
    meanwhile "Sleeping" is printed to the display every second
    when the alarm signal is received the program says so and exits
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGALRM - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    exit(1);
}

int main(){
    // Register for the signal
    signal(SIGALRM, handle_signal);

    alarm(5);
    while(1){
        printf("Sleeping\n");
        sleep(1);
    }
    return 0;
}