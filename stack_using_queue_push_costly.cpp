#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
    int curr_size=0; //no. of elements
    public:
        void push(int x){
            curr_size++;
            q2.push(x); // Push x in empty q2
            // Push the remaining elements from q1 to q2
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            //swapping names of the two queues
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }
        int ppop(){
            if (q1.empty())
                return INT_MIN;
            curr_size--;
            int popped_ele=q1.front();
            q1.pop();
            return popped_ele;
        }
        int top(){
            if (q1.empty())
                return -1;
            return q1.front();
        }
        int size(){
            return curr_size;
        }
};
  
int main(){
    Stack s;
    int n,x;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>x;
        s.push(x);
    }
    cout << "Current size of stack: " << s.size()<<endl;
    cout << "Popping 3 elements one by one\n";
    cout << "Top of stack : " << s.top() <<endl;
    cout << "Popped element : " << s.ppop() <<endl;   
    cout << "Top of stack : " << s.top() <<endl;
    cout << "Popped element : " << s.ppop() <<endl;   
    cout << "Top of stack : " << s.top() <<endl;
    cout << "Popped element : " << s.ppop() <<endl;
    cout << "Top of stack : " << s.top() <<endl;
    cout << "current size of stack: " << s.size()<<endl;
    return 0;
}
