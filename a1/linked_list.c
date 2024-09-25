#include "linked_list.h"


Node* get_new_node(int data, Node* next){
    Node*new_node = (Node*)malloc(sizeof(Node));
    *new_node = (Node){data,next};
    return new_node;
}

// This function sets up the list and prepares it for operations.
void list_init(Node** head){
    // mem_init(2048);
    // Node* new_node = get_new_node(0, NULL);
    // *head = new_node;
    *head = NULL;
}

// Adds a new node with the specified data to the linked list. 
void list_insert(Node** head, int data){
    if (*head == NULL){
        *head = get_new_node(data, NULL);
    }
    else{
        Node*node = *head;
        while(node->next != NULL) node = node->next;
        node->next = get_new_node(data, NULL);
    }
}

// Inserts a new node with the specified data immediately after a given node.
void list_insert_after(Node* prev_node, int data){
    Node* new_node = get_new_node(data, prev_node->next);
    prev_node->next = new_node;
}

// Inserts a new node with the specified data immediately before a given node in the list. 
void list_insert_before(Node** head, Node* next_node, int data){
    if (head == NULL) return;
    Node*node = *head;
    while(node->next != next_node && node->next != NULL) node = node->next;
    if (node->next == NULL) return;
    Node* new_node = get_new_node(data, node->next);
    node->next = new_node;
}

// Removes a node with the specified data from the linked list.
void list_delete(Node** head, int data){
    if (head == NULL) return;
    Node*node = *head;
    while(node->next != NULL && node->next->data != data) node = node->next;
    if (node->next == NULL) return;
    Node* next = node->next->next;
    free(node->next);
    node->next = next;
}

// Searches for a node with the specified data and returns a pointer to it.
Node* list_search(Node** head, int data){
    if (head == NULL) return NULL;
    Node*node = *head;
    while(node != NULL && node->data != data) node = node->next;
    if (node == NULL) return NULL;
    return node;
}

// Prints all the elements in the linked list as a list separated by commas, enclosed in square brackets.
void list_display(Node** head){
    printf("[");
    Node* node = *head;
    while (node != NULL){
        printf("%d",node->data);
        node = node->next;
        if (node != NULL){
            printf(",");
        }

    }
    printf("]\n");
}

// void list_display(Node** head, Node* start_node, Node* end_node);

// Returns the count of nodes
int list_count_nodes(Node** head){
    Node* node = *head;
    int counter = 0;
    while (node != NULL){
        node = node->next;
        counter++;
    }
    return counter;
}

// Frees all the nodes in the linked list. Important to prevent memory leaks.
void list_cleanup(Node** head){
    Node* node = *head;
    while (node != NULL){
        Node* old_node = node;
        node = node->next;
        free(old_node);
    }
    *head = NULL;
}

void list(Node* root){
    Node* node = root;
    printf("\nLinked list: \n");
    while (node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n---\n");
}

int main (){
    Node* head = NULL;
    list_init(&head);
    list_insert(&head, 2);
    list_insert(&head, 4);
    list_insert(&head, 8);
    list_insert(&head, 16);
    list_insert(&head, 32);
    Node* four = list_search(&head, 4);
    list_insert_before(&head, four, 13);
    list_insert_after(four, 17);
    list_delete(&head, 4);
    list_delete(&head, 9);
    int counter = list_count_nodes(&head);
    printf("len = %d\n", counter);
    list_display(&head);

    // list_search(&head, 10);
    // printf("? %p\n", head);
    list(head);
    return 0;
}
