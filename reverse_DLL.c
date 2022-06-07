#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;   
};

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

void reverseIter(struct Node **head){
    if (!(*head)){
        printf("List Empty");
        return;
    }
    struct Node *temp = NULL; 
    struct Node *current = *head;

    while (current !=  NULL){
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;             
       current = current->prev;
    }     

    if(temp != NULL )
        *head = temp->prev;
} 

struct Node* reverseRec(struct Node* node){
    if (!node)
        return NULL;
    struct Node* temp = node->next;
    node->next = node->prev;
    node->prev = temp;
    if (!node->prev)
        return node;
    return reverseRec(node->prev);
}

// Display List
void printList(struct Node* node){
    if(node == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("\nList : ");
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int choice, item;
    printf("1.Insert\n"); 
    printf("2.Reverse (Iteration)\n");
    printf("3.Reverse (Recursion)\n");
    printf("4.Display List\n");
    printf("5.Exit\n");
    while(1){
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter item: ");
                scanf("%d",&item);
                insertEnd(&head, item);
                break;
            case 2:
                reverseIter(&head);
                printList(head);
                break;
            case 3:
                head = reverseRec(head);
                printList(head);
                break;
            case 4:
                printList(head);
                printf("\n");
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}