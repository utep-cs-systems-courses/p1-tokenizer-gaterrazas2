#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    if(c == ' ' || c == '\t'){
        if(c != '\0'){
          // char c is a space or tab and not a zero terminator
          return 1;
        }
    }
    // char c is not a space or tab
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
    return (c != ' ' && c != '\t' && c != '\0');
}

/* Returns a pointer to the first character of the next
   space-separated token in zero-terminated str.  Return a zero pointer if
   str does not contain any tokens. */
char *token_start(char *s){
    // Loop while the current character is a space character
    while(space_char(*s)){
        // Move to the next character
        s++;
    }
    // If the current character is a null terminator
    if(*s == '\0'){
        // Return a zero pointer to indicate no tokens found
        return 0;
    }
    else{
        // Return the pointer to the first character of the next token
        return s;
    }
}

char *token_terminator(char *token){
    // Loop until the end is found
    while(non_space_char(*token)){
        token++;
    }
    // Return the terminator of the token
    return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char* str) {
    // keep track of token count
    int tokenCount = 0;
    
    // Loop until the end of the string ('\0') is reached
    while (*str) {
        // Check if the character is a newline, space, or tab
        if (*str == '\n' || *str == ' ' || *str == '\t') {
            // Increment the token count
            tokenCount++;
        }
        // Move to the next character in the string
        ++str;
    }
    // Return the final token count
    return tokenCount;
}


char *copy_str(char *inStr, short len) {
    // Allocate memory for the word string
    char *word = malloc(sizeof(char) * len);
    // Pointer to the allocated memory
    char *p = word;
    // Counter to track the number of characters copied
    int count = 0;

    // Loop until count reaches the specified length
    while (count != len) {
        // Copy the character from inStr to the current position in word
        *p = *inStr;
        // Move the input string pointer to the next character
        inStr++;
        // Move the word pointer to the next position
        p++;
        count++;
    }
    // Add a null terminator at the end of the word string
    *p = '\0';
    // Move the word pointer back to the beginning of the allocated memory
    p -= len;
    // Return the pointer to the copied word string
    return p;
}

/* Tokenizes the string argument into an array of tokens.
   For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */

char **tokenize(char* str) {
    // Count the number of tokens in the string
    int numTokens = count_tokens(str);
    // Allocate memory for the tokens vector
    char **tokens = malloc(sizeof(char*) * (numTokens + 1));
    // Index to keep track of the current token
    int tokenIndex = 0;
    // Get the pointer to the start of the first token
    char *tokenStart = token_start(str);
    
    // Loop until all tokens are processed
    while (tokenStart != NULL) {
        // Get the pointer to the end of the current token
        char *tokenEnd = token_terminator(tokenStart);
        // Calculate the length of the current token
        int tokenLength = tokenEnd - tokenStart;
        // Copy the current token to a new string
        char *tokenCopy = copy_str(tokenStart, tokenLength);
        
        // Store the copied token in the tokens vector
        tokens[tokenIndex] = tokenCopy;
        // Move to the next token
        tokenIndex++;
        // Get the pointer to the start of the next token
        tokenStart = token_start(tokenEnd);
    }
    // Add a zero terminator at the end of the tokens vector
    tokens[tokenIndex] = 0;
    // Return the tokens vector
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    int i = 0;
    while(*tokens[i] != '\0'){
        printf("%s\n", tokens[i]);
        i++;
    }
  
}

/* Frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens){
    int i = 0;
    while (tokens[i] != NULL){
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

