/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Larissa Welti
 * 
 * Brief summary of modifications:
    Removed the exiting of the program when handling the signal 
    In order to exit the program you now must stop the program with CTRL+Z
    and enter the command "kill -SIGKILL PID" or "kill -9 PID" 
    where you get the PID from entering "ps" into the command line
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    sleep(1);
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}