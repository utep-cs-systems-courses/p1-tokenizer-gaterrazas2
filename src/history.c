#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"

//initialize linked list
List* init_history() {
    // Allocate memory for the list
    List* list = malloc(sizeof(List));
    // Set the root node to NULL (empty list)
    list->root = NULL;
    // Return the initialized list
    return list;
}

// add to the LL
void add_history(List* list, char* str) {
    // Allocate memory for a new history item
    Item *temp = (Item*)malloc(sizeof(Item*) * 100);
    // Assign the given string to the `str` field of the new item
    temp->str = str;
    // Initialize a counter variable
    int c = 1;
    
    // Check if the list is empty
    if (list->root == NULL) {
        // Set the ID of the new item to the counter value
        temp->id = c;
        // Set the root of the list to the new item
        list->root = temp;
    }
    else {
        // Create a pointer to iterate through the history items
        Item *history = list->root;
        // Set the ID of the new item to the counter value
        temp->id = c;
        
        // Traverse the history items until the last item is reached
        while (history->next != NULL) {
          // Increment the ID of the new item by the counter value
          temp->id += c;
          // Move to the next history item
          history = history->next;
        }
        // Assign the new item as the next item of the current last item
        history->next = temp;
        // Increment the ID of the new item by the counter value
        temp->id += c;
    }
}

// returns node given ID
char* get_history(List* list, int id) {
    Item* curr = list->root;
    while (curr != NULL) {
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

// prints LL
void print_history(List *list){
    Item *point = list->root;
    point = point->next;
    while(point->next != NULL){
        printf("History: %d: %s", point->id, point->str);
        point = point->next;
    }
    printf("%d: %s", point->id, point->str);
}

// Free the LL
void free_history(List* list) {
    Item* current = list->root;
    while (current != NULL) {
        // Store the next node
        Item* next = current->next;
        // Free the string memory
        free(current->str);
        // Free the item memory
        free(current);
        // Move to the next node
        current = next;
    }
    // Free the list memory
    free(list);
}
