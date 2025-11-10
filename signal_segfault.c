/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:Larissa Welti
 * 
 * Brief summary of modifications:
    Added a handler that prints when a segmentation fault occurs
    Nothing else is done so will repeatedly send the segmentation fault
    until you force exit the program (CTRL+C)

 */


#include <stdio.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and exits
 */
void handle_signal() {
    printf("Segmentation Fault Detected\n");
}

int main (int argc, char* argv[]) {

    // Register for the signal
    signal(SIGSEGV, handle_signal);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}