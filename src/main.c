#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    // Define a character array to store user input
    char input[MAX_LENGTH];
    
    // Display a prompt for the user
    printf(">> ");
    
    // Continue looping indefinitely until the program is manually terminated
    while (1) {
        /*
         input: The character array where the input will be stored.
         sizeof(input): The size of the input buffer, which is the maximum number of characters that can be read.
        stdin: The standard input stream from which the input will be read */
        
        //Read user input and store it in the 'input' array
        fgets(input, sizeof(input), stdin);
        
        // Display the user input
        printf("You entered: %s", input);
        
        // Display the prompt for the next input
        printf(">> ");
    }
    
    return 0;
}
