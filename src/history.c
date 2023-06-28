#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"

//initialize linked list by initializing a root and adding it to be the start of a new empty list
List *init_history(){
    // initialize new Item struct
    Item root;
    // Set the id of 'root' to 0
    root.id = 0;
    // Set the root string equal to 'root'
    root.str = "root\n";
    // Allocate memory for an initialized pointer Item
    Item *nodePointer = malloc(sizeof(struct s_Item));
    // assign the pointer value to the root Item
    *nodePointer = root;
    // initialize new List struct
    List list;
    // Set the root of 'list' to the address stored in 'nodePointer' (storing the root)
    list.root = nodePointer;
    // Allocate memory for a new List struct pointer
    List *llPointer = malloc(sizeof(struct s_List));
    // Assign the value of the pointer to list
    *llPointer = list;
    // Return the pointer
    return llPointer;
}

void add_history(List *list, char *str){
    int count = 0;
    // Point to the current root of the list
    Item *curr = list->root;
    // Create an item struct named tempNode
    Item tempNode;
    // Traverse the linked list
    while(curr->next != 0){
      // move to the next node
      curr = curr->next;
    }
    // Set the id of 'tempNode' to the id of the current node + 1 (making tempNode the final node in the list)
    tempNode.id = curr->id + 1;
    // Iterate through the characters of the provided string until the null terminator is encountered
    while(*str != '\0'){
      count++;
      // Move the pointer 'str' to the next character
      str++;
    }
    // Move the pointer 'str' back to the start of the string
    str -= count;
    // Assign a copy of the substring of 'str' to 'node.str' using the 'copy_str' function
    tempNode.str = copy_str(str, count);
    // Allocate memory for the next node in the linked list
    curr->next = malloc(sizeof(struct s_Item));
    // Copy the values of 'tempNode' to the newly created node in the linked list
    *(curr->next) = tempNode;
    }

// returns node given ID
char* get_history(List* list, int id) {
    Item* curr = list->root;
    while (curr != 0) {
        if (curr->id == id) {
            // Return the string if ID matches
            return curr->str;
        }
        // Move to the next node
        curr = curr->next;
    }
    // Return NULL if ID is not found
    return NULL;
}

//Print the LL
void print_history(List *list){
    Item *curr = list->root;
    // Skip the first node created at initialization
    curr = curr->next;
    // for empty history
    if(curr == 0){
        puts("History is Empty");
    }
    else{
        // while not at the end of the list
        while(curr->next != 0){
            // print the current nodes ID and value
            printf("Node #%d: %s", curr->id, curr->str);
            curr = curr->next;
        }
        // print the final node
        printf("Node #%d: %s", curr->id, curr->str);
    }
}

// Free the LL
void free_history(List* list) {
    Item* current = list->root;
    while (current != NULL) {
        // Store the next node
        Item* next = current->next;
        // Free the item memory
        free(current);
        // Move to the next node
        current = next;
    }
    // Free the list memory
    free(list);
}
