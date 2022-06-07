#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;
    void enQueue(int x){
        s1.push(x);
    }
    int deQueue(){
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty";
            exit(0);
        }
        // if s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    void display(){
        stack<int> temp=s2;
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
    q.deQueue();    
    q.deQueue();    
    q.deQueue();
    cout<<"\nQueue after dequeuing 3 elements: ";
    q.display();
    return 0;
}