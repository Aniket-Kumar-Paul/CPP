#include<iostream>
#include<math.h>
#include<string>
#include<stack>
using namespace std;

int evaluatePostfix(string exp){
    stack<int> s;
    int i;
    for (i = 0; i<exp.length(); ++i){
        if (isdigit(exp[i])) //operand
            s.push(exp[i] - '0');
        else{ //operator
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (exp[i]){
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2/val1); break;
                case '^': s.push(pow(val2,val1)); break;
            }
        }
    }

    return s.top();
}

int main() {
    string exp;
    cout<<"Enter expression: ";
    cin>>exp;
    cout<<exp<<" = "<<evaluatePostfix(exp);
    return 0;
}