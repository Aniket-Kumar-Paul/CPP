
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
 
// Insertion
void insertBeg(struct Node** start, int value){
    struct Node *last = (*start)->prev;
    struct Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    new_node->prev = last;
    last->next = (*start)->prev = new_node;
    *start = new_node;
}
void insertAfter(struct Node** start, int value1, int value2){
    struct Node* new_node = new Node;
    new_node->data = value1;
    struct Node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node *next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}
void insertEnd(struct Node** start, int value){
    if (*start == NULL){
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    Node *last = (*start)->prev;
    struct Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
} 

// Deletion
void deleteNode(struct Node** start, int key){
    if (*start == NULL)
        return;
    struct Node *curr = *start, *prev_1 = NULL;
    while (curr->data != key) {
        if (curr->next == *start) {
            printf("\nList doesn't have node with value = %d", key);
            return;
        }
        prev_1 = curr;
        curr = curr->next;
    }
    // Check if node is the only node in list
    if (curr->next == *start && prev_1 == NULL) {
        (*start) = NULL;
        free(curr);
        return;
    }
    // If list has more than one node, check if it is the first node
    if (curr == *start) {
        prev_1 = (*start)->prev;
        *start = (*start)->next;
        prev_1->next = *start;
        (*start)->prev = prev_1;
        free(curr);
    }
    // check if it is the last node
    else if (curr->next == *start) {
        prev_1->next = *start;
        (*start)->prev = prev_1;
        free(curr);
    }
    else {
        struct Node* temp = curr->next;
        prev_1->next = temp;
        temp->prev = prev_1;
        free(curr);
    }
}

// Display List
void printList(struct Node* start){
    struct Node *temp = start;
    printf("\nTraversal in forward direction \n");
    while (temp->next != start){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\nTraversal in reverse direction \n");
    Node *last = start->prev;
    temp = last;
    while (temp->prev != last){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main(){
    struct Node* head = NULL;
    int choice,ele,item;
    printf("1.Insert at Begining\n");
    printf("2.Insert after a given value\n");
    printf("3.Insert at End\n");
    printf("4.Delete entered item\n");
    printf("5.Display List\n");
    printf("6.Exit\n");
    while(1){
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter item: ");
                scanf("%d",&item);
                insertBeg(&head, item);
                break;
            case 2:
                printf("\nEnter element and value to be inserted: ");
                scanf("%d%d",&ele,&item);
                insertAfter(&head, item, ele);
                break;
            case 3:
                printf("\nEnter item: ");
                scanf("%d",&item);
                insertEnd(&head, item);
                break;
            case 4:
                printf("\nEnter item to be deleted: ");
                scanf("%d",&item);
                deleteNode(&head, item);
                break;
            case 5:
                printList(head);
                printf("\n");
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}