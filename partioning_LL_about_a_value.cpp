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

struct Node *partition(struct Node *head, int x){
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;

    while (head != NULL){
        if (head->data == x){
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else{
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
        else if (head->data < x){
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next  = head;
                greaterLast = head;
            }
        }
        head = head->next;
    }

    if (greaterLast != NULL)
        greaterLast->next = NULL;
 
    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }
 
    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        return smallerHead;
    }

    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return  smallerHead;
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
    struct Node* head = NULL;
    printf("1.Insert\n");
    printf("2.Partition\n");
    printf("3.Display List\n");
    printf("4.Exit\n");
    int choice, x;
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter item: ");
                scanf("%d",&x);
                insertEnd(&head, x);
                break;
            case 2:
                printf("\nEnter key about which to be partitioned: ");
                scanf("%d",&x);
                printList(partition(head, x));
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
        }
    }
}