#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    int n = s.size();

    stack<char> st;
    bool ans = true;

    for(int i=0; i<n; i++) {
        if(s[i]=='{' or s[i]=='(' or s[i]=='[') {
            st.push(s[i]);
        } else if (s[i]==')'){
            if(!st.empty() && st.top()=='(')
                st.pop();
            else{
                ans = false;
                break;
            }
        } else if (s[i]=='}'){
            if(!st.empty() && st.top()=='{')
                st.pop();
            else{
                ans = false;
                break;
            }
        } else if (s[i]==']'){
            if(!st.empty() && st.top()=='[')
                st.pop();
            else{
                ans = false;
                break;
            }
        }
    }

    if(!st.empty())
        return false;
    return ans;
}

int main() {
    string s = "{([])}";

    if(isValid(s)) {
        cout<<"Balanced Parenthesis"<<endl;
    } else {
        cout<<"Unbalanced Parenthesis"<<endl;
    }
    return 0;
}