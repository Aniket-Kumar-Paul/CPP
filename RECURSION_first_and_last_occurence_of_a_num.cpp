#include<iostream>
using namespace std;

int firstocc(int arr[], int size, int pos, int key){
    if(pos==size){
        return -1; //key not found
    }
    if(arr[pos]==key){
        return pos;
    }
    return firstocc(arr,size,pos+1,key);
}
int lastocc(int arr[], int size, int pos, int key){
    if(pos==size){
        return -1; //key not found
    }
    int restArr = lastocc(arr,size,pos+1,key);
    if(restArr!=-1){
        return restArr;
    }
    if(arr[pos]==key){
        return pos;
    }
    return -1;
}
int main(){
    int arr[]={4,2,1,2,5,2,7};
    cout<<firstocc(arr,7,0,2)<<endl;
    cout<<lastocc(arr,7,0,2)<<endl;
    return 0;
}