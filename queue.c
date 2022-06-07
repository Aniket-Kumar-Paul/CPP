#include<stdio.h>
#include<stdlib.h>
struct Queue {
    int front, rear, capacity;
    int* arr;
};
struct Queue* createQueue(int capacity){
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=queue->rear=-1;
    queue->arr=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
};

void enqueue(struct Queue* q, int item){
    if((q->rear)+1==q->capacity){
        printf("Overflow");
        return; 
    }
    if(q->front==-1 & q->rear==-1){
        q->front=q->rear=0;
    }else{
        q->rear=q->rear+1;
    }
    q->arr[q->rear]=item;
    return;
}

int dequeue(struct Queue* q){
    if(q->front==-1 || q->front>q->rear){
        printf("Underflow");
        return -1;
    }
    int ele=q->arr[q->front];
    q->front=q->front+1;
    return ele;
}

void displayQueue(struct Queue* q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
}

int main(){
    int n,ele;
    printf("Enter size of Queue: ");
    scanf("%d",&n);
    struct Queue* q=createQueue(n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        enqueue(q,ele);
    }
    dequeue(q);
    dequeue(q);
    printf("Queue after dequeing 2 elements: ");
    displayQueue(q);
    return 0;
}