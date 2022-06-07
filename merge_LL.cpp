#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int ele){
    struct Node* new_node = new Node;
    struct Node *last_node = *head;
    new_node->data = ele;
    new_node->next = NULL;
    if (*head == NULL){
       *head = new_node;
       return;
    }
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = new_node;
}

struct Node* merge(struct Node* head1, struct Node* head2){
    struct Node* start = head1;
    struct Node* last = start;
    while(last->next != NULL)
        last = last->next;
    last->next = head2;
    return start;
}

void printList(struct Node *head){
    printf("\nThe Linked List is :\n");
    while (head != NULL){
        printf(" %d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node* h1 = NULL;
    struct Node* h2 = NULL;
    printf("1.Insert into List 1\n");
    printf("2.Insert into List 2\n");
    printf("3.Merge\n");
    printf("4.Display List 1\n");
    printf("5.Display List 2\n");
    printf("6.Exit\n");
    int choice, x;
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter item: ");
                scanf("%d",&x);
                insertEnd(&h1, x);
                break;
            case 2:
                printf("\nEnter item: ");
                scanf("%d",&x);
                insertEnd(&h2, x);
                break;
            case 3:
                printList(merge(h1, h2));
                break;
            case 4:
                printList(h1);
                break;
            case 5:
                printList(h2);
                break;
            case 6:
                exit(0);
        }
    }
}