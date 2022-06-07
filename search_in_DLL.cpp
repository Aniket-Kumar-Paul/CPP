#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertEnd(struct Node** head_ref, int new_data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
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
    return;
}

int search(Node** head_ref, int x){
    Node* temp = *head_ref;
    int pos = 0;
    while (temp->data != x && temp->next != NULL) {
        pos++;
        temp = temp->next;
    }
    if (temp->data != x)
        return -1;
    return (pos + 1);
}

void printList(struct Node* node){
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;
    int n,x;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter the items: \n");
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        insertEnd(&head, x);
    }
    printf("\nEntered Linked List is : \n");
    printList(head);
    int ele;
    printf("\nEnter item to be searched: ");
    scanf("%d",&ele);
    x=search(&head, ele);
    if(x==-1)
        printf("\nElement not found");
    else
        printf("%d found at position %d",ele,x);
}