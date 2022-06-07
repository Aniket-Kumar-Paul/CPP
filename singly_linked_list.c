#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

int lengthLL(struct node* head){
    int count=0;
    struct node* curr = head;
    while (curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

void insBegin(struct node** head, int ele){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = ele;
    new_node->next = *head;
    (*head) = new_node;
}

void insAfter(struct node** head, int pos, int ele){
    if(pos>lengthLL(*head)){
        printf("Invalid Pos\n");
        return;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* pos_node = *head;
    new_node->data = ele;
    int i = 1;
    while(i<pos){
        pos_node = pos_node->next;
        i++;
    }
    new_node->next = pos_node->next;
    pos_node->next = new_node;
}

void insBefore(struct node** head, int pos, int ele){
    if(pos>lengthLL(*head)){
        printf("Invalid Pos\n");
        return;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* pos_node = *head;
    new_node->data = ele;
    int i = 1;
    while(i<pos-1){
        pos_node = pos_node->next;
        i++;
    }
    new_node->next = pos_node->next;
    pos_node->next = new_node;
}

void insAfterdel(struct node** head, int item, int ele){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* item_node = *head;
    new_node->data = ele;
    int i = 1;
    while(item_node->data!=item && item_node->next!=NULL){
        item_node = item_node->next;
    }
    new_node->next = item_node->next->next;
    item_node->next->next = NULL; //Deleting the node after given item
    free(item_node->next);
    item_node->next = new_node;
}

void insEnd(struct node** head, int ele){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last_node = *head;
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

void delBeg(struct node **head){
    if(*head == NULL) return;
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delEnd(struct node **head){
    if(*head == NULL) return;
    struct node* ptr1 = *head;
    struct node* ptr2 = *head;
    while(ptr1->next!=NULL){
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
    free(ptr1);
}

void delPos(struct node **head, int pos){
   if (*head == NULL) return;
   struct node* ptr1 = *head;
   struct node* ptr2 = *head;
   int i = 1;
   while(i<pos){
       ptr2 = ptr1;
       ptr1 = ptr1->next;
       i++;
   }
   ptr2->next = ptr1->next;
   ptr1->next = NULL;
   free(ptr1);
}

void printList(struct node *head){
  while (head != NULL){
     printf(" %d ", head->data);
     head = head->next;
  }
  printf("\n");
}

int main(){
    struct node* head = NULL;
    while (1){
        printf("\nChoose any one for the linked list:-\n");
        printf("1.Insert at Begining\n");
        printf("2.Insert after a Pos\n");
        printf("3.Insert after an item and delete item next to it\n");
        printf("4.Insert before a Pos\n");
        printf("5.Insert at End\n");
        printf("6.Delete at Begining\n");
        printf("7.Delete at a Position\n");
        printf("8.Delete at End\n");
        printf("9.Display Length\n");
        printf("10.Display the Linked List\n");
        int choice,ele,pos,item;
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                insBegin(&head, ele);
                break;
            case 2:
                printf("Enter pos & element: ");
                scanf("%d%d",&pos,&ele);
                insAfter(&head, pos, ele);
                break;
            case 3:
                printf("Enter item after which you want your element to be placed: \n");
                printf("Enter item and element: ");
                scanf("%d%d",&item,&ele);
                insAfterdel(&head, item, ele);
                break;
            case 4:
                printf("Enter pos & element: ");
                scanf("%d%d",&pos,&ele);
                insBefore(&head, pos, ele);
                break;
            case 5:
                printf("Enter element: ");
                scanf("%d",&ele);
                insEnd(&head, ele);
                break;
            case 6:
                delBeg(&head);
                printf("Deleted\n");
                break;
            case 7:
                printf("Enter Position: ");
                scanf("%d",&pos);
                delPos(&head, pos);
                break;
            case 8:
                delEnd(&head);
                printf("Deleted\n");
                break;
            case 9:
                printf("Length of Linked List: %d\n",lengthLL(head));
                break;
            case 10:
                printList(head);
                break;
        }
    }
    return 0;
}