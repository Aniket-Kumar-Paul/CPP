#include<bits/stdc++.h>
using namespace std;

int main(){
    int j=0;
    for(int i=0;i<6;i++){
        cout<<i<<endl;
        if(i==4){
            while(j<11){
                cout<<j<<endl;
                if(j==6)
                    break;
                j++;
            }
            cout<<"while loop breaked";
        }
    }
    return 0;
}