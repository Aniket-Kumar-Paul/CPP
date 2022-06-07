#include<stdio.h>
#include<stdlib.h>
struct circularQueue {
    int front, rear, capacity;
    int* arr;
};
struct circularQueue* createcircularQueue(int capacity){
    struct circularQueue* circularqueue=(struct circularQueue*)malloc(sizeof(struct circularQueue));
    circularqueue->capacity=capacity;
    circularqueue->front=circularqueue->rear=-1;
    circularqueue->arr=(int*)malloc(circularqueue->capacity*sizeof(int));
    return circularqueue;
};

void enqueue(struct circularQueue* q, int item){
    if((q->front==0 && q->rear==q->capacity-1) || (q->front==q->rear+1)){
        printf("Overflow");
        return; 
    }
    if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
    }else if(q->rear==q->capacity-1 && q->front!=0){
        q->rear=0;
    }else{
        q->rear++;
    }
    q->arr[q->rear]=item;
    return;
}

int dequeue(struct circularQueue* q){
    if(q->front==-1){
        printf("Underflow");
        return -1;
    }
    int ele=q->arr[q->front];
    if(q->front==q->rear){ //only one element left
        q->front=q->rear=-1;
    }else if(q->front==q->capacity-1){
        q->front=0;
    }else{
        q->front++;
    }
    return ele;
}

void displayQueue(struct circularQueue* q){
    if(q->front==-1){
        printf("Empty Queue");
        return;
    }
    if(q->rear>=q->front){
        for(int i=q->front;i<=q->rear;i++){
            printf("%d ",q->arr[i]);
        }
    }else{
        for(int i=q->front;i<q->capacity;i++){
            printf("%d ",q->arr[i]);
        }
        for(int i=0;i<=q->rear;i++){
            printf("%d ",q->arr[i]);
        }
    }
}

int main(){
    int n,ele;
    printf("Enter size of circularQueue: ");
    scanf("%d",&n);
    struct circularQueue* q=createcircularQueue(n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        enqueue(q,ele);
    }
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printf("circularQueue after dequeing 3 elements: ");
    displayQueue(q);
    printf("\nEnter two elements: ");
    scanf("%d",&ele);
    enqueue(q,ele);
    scanf("%d",&ele);
    enqueue(q,ele);
    printf("circularQueue from front to rear position after enqueing the two elements: ");
    displayQueue(q);
    return 0;
}