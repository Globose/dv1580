#include "linked_list.h"

// This function sets up the list and prepares it for operations.
void list_init(Node** head){
    // mem_init(2048);
    *head = (Node*)malloc(sizeof(Node));
    **head = (Node){0,NULL};
}

// Adds a new node with the specified data to the linked list. 
void list_insert(Node** head, int data){
    return;
}

/**
 * Inserts a new node with the specified data immediately after a given node.
 */
void list_insert_after(Node* prev_node, int data){
    return;
}

/**
 * Inserts a new node with the specified data immediately before a given node in the list. 
 */
void list_insert_before(Node** head, Node* next_node, int data){
    return;
}

/**
 * Removes a node with the specified data from the linked list.
 */
void list_delete(Node** head, int data){
    return;
}

/**
 * Searches for a node with the specified data and returns a pointer to it.
 */
Node* list_search(Node** head, int data){
    Node* ptr = NULL;
    return ptr;
}

/**
 * Prints all the elements in the linked list as a list separated by commas, enclosed in square brackets.
 */
void list_display(Node** head){
    return;
}
// void list_display(Node** head, Node* start_node, Node* end_node);

/**
 * Returns the count of nodes
 */
int list_count_nodes(Node** head){
    return 0;
}

/**
 * Frees all the nodes in the linked list. Important to prevent memory leaks.
 */
void list_cleanup(Node** head){
    return;
}

void list(Node* root){
    Node* node = root;
    while (node != NULL){
        printf("%p: %d, -> %p\n",node, node->data, node->next);
        node = node->next;
    }
}

int main (){
    Node* head = NULL;
    list_init(&head);
    printf("Head %p\n", head);
    printf("headvalue %d", head->data);
    return 0;
}
