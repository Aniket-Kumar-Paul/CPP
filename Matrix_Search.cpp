#include<bits/stdc++.h>
using namespace std;

int main(){
    // NOTE :- Matrix is sorted in each row and column in ascending order
    int n,m,target,i,j;
    cin>>n>>m>>target;
    int mat[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cin>>mat[i][j];
    }

    //Starting from the top right element [can also do the same from bottom left element]
    int r=0,c=m-1;
    while(r<n && c>=0){
        if(mat[r][c]==target){
            cout<<"Target found in matrix.";
            return 1;
        }
        else if(mat[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }
    cout<<"Target not found in matrix.";
    return 0;
}