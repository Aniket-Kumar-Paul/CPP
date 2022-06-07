#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;
    int curr_size=0;
    public:
        void enQueue(int x){
            // Move all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            //Push element into s1
            s1.push(x);
            // Push everything back to s1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            curr_size++;
        }
        int deQueue(){
            // if first stack is empty
            if (s1.empty()) {
                cout << "Queue is Empty";
                exit(0);
            }
            int popped_ele = s1.top();
            s1.pop();
            curr_size--;
            return popped_ele;
        }
        void display(){
            stack<int> temp=s1; 
            while (!temp.empty()){
                int t = temp.top();
                cout << t << " ";
                temp.pop();
            }
        }
};

int main(){
    Queue q;
    int n,x;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>x;
        q.enQueue(x);
    }
    cout<<"Current Queue: ";
    q.display();
    q.deQueue();    
    q.deQueue();    
    q.deQueue();
    cout<<"\nQueue after dequeuing 3 elements: ";
    q.display();
    return 0;
}