#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <string.h>


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
char *token_start(char *str); 

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token);

/* Counts the number of tokens in the string argument. */
int count_tokens(char *s) {
    int count = 0;
    int len = strlen(s);
    int is_token = 0;

    // Iterate through each character in s
    for (int i = 0; i < len; i++) {
        // Check if the current character is a whitespace
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
            // reset the token counter because current position is not part of token
            is_token = 0;
        }
        // Check if the current character (s[i]), is a letter
        else if ((s[i] >= 'a' && s[i] <= 'z') ||
                 (s[i] >= 'A' && s[i] <= 'Z') {
            if (is_token == 0) {
                // Start of a new token
                count++;
                // Sets current position to  be a token
                is_token = 1;
            }
        }
    }

    return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    // Allocate memory for the copy (+1 for the '\0' at the end of the string)
    char *outStr = malloc((len + 1) * sizeof(char));
    
    // run through original string and copy into outStr
    for (short i = 0; i < len; i++) {
        outStr[i] = inStr[i];
    }
    
    // At a string terminator to the extra spot allocated by the malloc line
    outStr[len] = '\0';

    return outStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
