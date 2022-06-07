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
    if (stack->top==stack->capacity - 1) //stack overflow
        return;
    stack->array[++stack->top] = item;
}
void pop(struct Stack* stack){
    if (stack->top==-1) //stack underflow
        return;
    stack->array[stack->top--];
}
int matchingPair(char c1, char c2){
    if (c1 == '(' && c2 == ')')
        return 1;
    else if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;
}
void BalancedParenthesis(char exp[]){
    int n = strlen(exp);
    struct Stack* stack = createStack(n);
    for(int i=0;i<n;i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(stack,exp[i]);
        }else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(stack->top==-1){ //stack empty
                printf("Not balanced");
                return;
            }else{
                if(matchingPair(stack->array[stack->top],exp[i])){
                    pop(stack);
                }else{
                    printf("Not balanced");
                    return;
                }
            }
        }
    }
    printf("Balanced");
    return;
}
int main(){
    char str[20];
    printf("Enter expression: ");
    scanf("%s",str);
    BalancedParenthesis(str);
}