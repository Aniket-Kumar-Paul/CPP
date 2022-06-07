#include<iostream>
using namespace std;

class DEqueue {
    int n,f,r;
    int *a;
    public:
        DEqueue(int m){
            n=m;
            a=new int[n];
            f=r=-1;
        }
        void insert_at_front(int);
        void insert_at_rear(int);
        void delete_fr_front();
        void delete_fr_rear();
        void show();
};
void DEqueue::insert_at_rear(int i) {
   if(r>=n-1) {
      cout<<"\nOverflow!!!!";
   }else{
      if(f==-1) {
         f++;
         r++;
      }else{
         r++;
      }
      a[r]=i;
   }
}
void DEqueue::insert_at_front(int i) {
   if(f==-1) {
      f=0;
      a[++r]=i;
   }else if(f!=0) {
      a[--f]=i;
   } else {
      cout<<"\nOverflow!!!";
   }
}
void DEqueue::delete_fr_front() {
   if(f==-1) {
      cout<<"Underflow";
      return;
   }else {
       if(f==r) {
         f=r=-1;
         return;
      } else{
         f=f+1;
      }
   }
}
void DEqueue::delete_fr_rear(){
    if (f == -1){
        cout << "Underflow";
        return;
    }else{
        if (f == r){
            f = r = -1;
        }else{
            r = r - 1;
        }
    }
}
void DEqueue::show(){
    if (f == -1){
        cout << "Empty DEqueue";
    }else{
        for (int i = f; i <= r; i++){
            cout << a[i] << " ";
        }
    }
}
int main(){
    int n, c, i;
    cout<<"Enter max size of queue: ";
    cin>>n;
    DEqueue d(n);
    cout << "\n 1.insert at front";
    cout << "\n 2.insert at rear";
    cout << "\n 3.show";
    cout << "\n 4.deletion from front";
    cout << "\n 5.deletion from rear";
    cout << "\n 6.exit";
    do {
    cout << "\n Enter your choice: ";
    cin >> c;
    switch (c){
    case 1:
        cout << "enter the element to be inserted: ";
        cin >> i;
        d.insert_at_front(i);
        break;
    case 2:
        cout << "enter the element to be inserted: ";
        cin >> i;
        d.insert_at_rear(i);
        break;
    case 3:
        d.show();
        break;
    case 4:
        d.delete_fr_front();
        break;
    case 5:
        d.delete_fr_rear();
        break;
    case 6:
        exit(1);
        break;
    default:
        cout << "Invalid choice";
        break;
    }
    }while (1);
    return 0;
}