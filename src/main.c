#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100

int main(){
    // Declare a character array named input with a size of MAX
    char input[MAX];
    // Declare a pointer to a List structure and initialize it using the init_history() function
    List *list = init_history();
    // Initialize tokens to NULL
    char **tokens = NULL;
    
    // infinite loop for main menu
    while(1){
        puts("-----Menu-----\n1)Tokenize\n2)History\nq)Quit");
        putchar('>');
        fgets(input, MAX, stdin);
        // Declare a double pointer named tokens and assign the result of the tokenize() function to it
        char **tokens = tokenize(input);
        // Tokenize Option
        if(*tokens[0] == '1'){
            puts("-----Tokenizer-----");
            // Free the memory allocated for tokens
            free_tokens(tokens);
            puts("Enter a string");
            //infinite loop
            while(1){
                putchar('>');
                fgets(input, MAX, stdin);
                // Assign the result of the tokenize() function to tokens
                tokens = tokenize(input);
                // if string is empty
                if(*(tokens[0]+1) == '\0'){
                    puts("Empty String");
                    break;
                }
                else{
                                                                        //CODE BREAKS HERE!!!!!!!!!
                    // Print the tokens
                    print_tokens(tokens);
                    // Add the input to the history
                    add_history(list, input);
                    // Free the memory allocated for tokens
                    free_tokens(tokens);
                }
            }
        } // end of Tokenize option
        // History option
        else if(*tokens[0] == '2'){
            puts("-----History Menu-----\n1)View History\n#)for history at that id #\n3)q to quit");
            // Free the memory allocated for tokens
            free_tokens(tokens);
            // infinite loop
            while(1){
                puts("\nEnter a menu option:");
                putchar('>');
                fgets(input, MAX, stdin);
                // Assign the result of the tokenize() function to tokens
                tokens = tokenize(input);
                
                // if user selected to view history
                if(*tokens[0] == '1'){
                    // Print the history of inputs
                    puts("Printing History...");
                    print_history(list);
                    puts("\n");
                    break;
                }
                // if the user selected to quit
                else if(*tokens[0] == 'q'){
                    puts("Quitting to main menu...");
                    // Break out of the inner loop
                    break;
                }
                // if the user selected to view history by ID
                else if((*tokens[0] - '0') > 0){
                    // Print the input history corresponding to the ID provided
                    printf("%s", get_history(list, *tokens[0] - '0'));
                }
            }
        } // end of history option
        
        // Check if the first character of the first token is 'q'
        else if(*tokens[0] == 'q'){
            // Free the memory allocated for the history list
            free_history(list);
            // end program
            return 0;
        }
        else{
            puts("Invalid input");
        }
    }
}
