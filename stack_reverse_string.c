#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct Stack{
    int top;
    unsigned capacity;
    char* array;
};
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(struct Stack* stack, char item){
    if (stack->top==stack->capacity - 1)
        return;
    stack->array[++stack->top] = item;
}
char pop(struct Stack* stack){
    if (stack->top==-1)
        return '\0';
    return stack->array[stack->top--];
}

void reverse(char str[]){
    int n = strlen(str);
    struct Stack* stack = createStack(n);
    //Pushing characters of the string into stack one by one
    for(int i = 0; i < n; i++)
        push(stack, str[i]);
    //Pop characters from the stack and replace in the string
    for(int i = 0; i < n; i++)
        str[i] = pop(stack);
}
 

int main(){
    char str[20];
    printf("Enter string: ");
    scanf("%s",str);
    reverse(str);
    printf("Reversed string using stack is: %s",str);
}