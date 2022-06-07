#include<iostream>
using namespace std;

void floodFill(int arr[][8], int r, int c, int toFill, int prevFill){
    int rows = 3; //sizeof(arr)/sizeof(arr[0]);
    int col = 8; //sizeof(arr[0])/sizeof(arr[0][0]);
    if(r<0||r>=rows||c<0||c>=col||arr[r][c]!=prevFill)
        return;
    arr[r][c] = toFill;
    floodFill(arr, r-1, c, toFill, prevFill);
    floodFill(arr, r+1, c, toFill, prevFill);
    floodFill(arr, r, c-1, toFill, prevFill);
    floodFill(arr, r, c+1, toFill, prevFill);
}

int main(){
    int arr[][8] = {{1,1,1,2,1,1,2,2},
    {1,1,1,2,2,0,0,0},
    {2,2,2,0,0,0,1,0}};
    floodFill(arr, 1, 4, 3, 2);
    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}