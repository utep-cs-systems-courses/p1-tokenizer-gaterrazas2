#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    // Define a character array to store user input
    char input[MAX_LENGTH];
    
    // Display a prompt for the user
    printf("Enter a word, or 'exit' to exit\n");
    printf(">> ");
    
    // Continue looping indefinitely until the program is manually terminated
    while (1) {
        /*
         input: The character array where the input will be stored.
         sizeof(input): The size of the input buffer, which is the maximum number of characters that can be read.
        stdin: The standard input stream from which the input will be read */
        
        //Read user input and store it in the 'input' array
        fgets(input, sizeof(input), stdin);
        
        // function returns the index of the first character found
        // Remove the trailing newline character from the input to check against "exit" later
        input[strcspn(input, "\n")] = '\0';
        
        // Display the user input
        printf("You entered: %s\n", input);
        
        // Check if the input is "exit" and break out of the loop if true
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        // Display the prompt for the next input
        printf("Enter a word, or 'exit' to exit\n");
        printf(">> ");
    }
    
    return 0;
}
