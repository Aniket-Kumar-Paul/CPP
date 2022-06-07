#include<iostream>
#include<math.h>
#include<string>
#include<stack>
using namespace std;

int Operations(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }
}
int precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    else if(op == '*'||op == '/')
        return 2;
    else if(op == '^')
        return 3;
    return 0;
}
int evaluate(string expression){
    int i;
    stack <int> values; //integer stack
    stack <char> ops;   //operators stack
    for(i = 0; i < expression.length(); i++){
        if(expression[i] == ' ')
            continue;
        else if(expression[i] == '('){
            ops.push(expression[i]);
        }
        else if(isdigit(expression[i])){
            int val = 0;
            //If the no. is of more than single single digit
            while(i < expression.length() && isdigit(expression[i])){
                val = (val*10) + (expression[i]-'0');
                i++;
            }
            values.push(val);
            i--; //for correction of i value
        }
        else if(expression[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                 
                values.push(Operations(val1, val2, op));
            }
            if(!ops.empty())
               ops.pop();
        }
        else{ //the character is an operator
            while(!ops.empty() && precedence(ops.top())>= precedence(expression[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop(); 
                char op = ops.top();
                ops.pop();
                 
                values.push(Operations(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }
    while(!ops.empty()){ //applying remaining ops to reamining nos.
        int val2 = values.top();
        values.pop();         
        int val1 = values.top();
        values.pop();       
        char op = ops.top();
        ops.pop();
                 
        values.push(Operations(val1, val2, op));
    }
    return values.top(); //result of the expression
}
int main() {
    string exp;
    cout<<"Enter expression: ";
    cin>>exp;
    cout<<exp<<" = "<<evaluate(exp);
    return 0;
}