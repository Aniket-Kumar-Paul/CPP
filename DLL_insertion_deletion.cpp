#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insertion
void insertBeg(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void insertAfter(struct Node* prev_node, int new_data){
    if (prev_node == NULL) {
        printf("Invalid Previous Node");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void insertEnd(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}
 
// Deletion
void deleteBeg(struct Node* head){
    struct Node * toDelete;
    if(head == NULL){
        printf("\nList is empty.\n");
    }
    else{
        toDelete = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(toDelete);
        printf("Deletion Succesfully.\n");
    }
}
void deleteEnd(struct Node* head){
    struct Node * toDelete;
    struct Node * last;
    last = head;
    if(last == NULL){
        printf("\nList is empty.\n");
        return;
    }
    // printf("");
    while (last->next != NULL)
        last = last->next;
    toDelete = last;
    last = last->prev;
    if (last != NULL)
        last->next = NULL; 
    free(toDelete); 
    printf("Deletion Succesfully.\n");
}
void deleteFromN(struct Node* head, int position){
    struct Node *current;
    current = head;
    for(int i=1; i<position && current!=NULL; i++){
        current = current->next;
    }
    // printf("");
    if(current != NULL){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        printf("Deletion Succesfully.\n");
    }else{
        printf("Invalid position!\n");
    }
}

// Display List
void printList(struct Node* node){
    if(node == NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
 

int main(){
    struct Node* head = NULL;
    int choice,pos,item;
    printf("1.Insert at Begining\n");
    printf("2.Insert after a given Position\n");
    printf("3.Insert at End\n");
    printf("4.Delete from Begining\n");
    printf("5.Delete from a given Position\n");
    printf("6.Delete from End\n");
    printf("7.Display List\n");
    printf("8.Exit\n");
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
                printf("\nEnter Position & item: ");
                scanf("%d%d",&pos,&item);
                struct Node* curr;
                curr = head;
                for(int i=1; i<pos && curr!=NULL; i++){
                    curr = curr->next;
                }
                insertAfter(curr, item);
                break;
            case 3:
                printf("\nEnter item: ");
                scanf("%d",&item);
                insertEnd(&head, item);
                break;
            case 4:
                deleteBeg(head);
                break;
            case 5:
                printf("\nEnter Position: ");
                scanf("%d",&pos);
                deleteFromN(head, pos);
                break;
            case 6:
                deleteEnd(head);
                break;
            case 7:
                printList(head);
                printf("\n");
                break;
            case 8:
                exit(0);
        }
    }
    return 0;
}