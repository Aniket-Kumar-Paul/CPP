#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,i,j;
    cin>>n>>m;
    int arr[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cin>>arr[i][j];
    }

    int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;
    while(rowStart<=rowEnd && colStart<=colEnd){

        for(i=colStart;i<=colEnd;i++)
            cout<<arr[rowStart][i]<<" ";
        rowStart++;
        if(rowStart>rowEnd) break;

        for(i=rowStart;i<=rowEnd;i++)
            cout<<arr[i][colEnd]<<" ";
        colEnd--;
        if(colStart>colEnd) break;

        for(i=colEnd;i>=colStart;i--)
            cout<<arr[rowEnd][i]<<" ";
        rowEnd--;

        for(i=rowEnd;i>=rowStart;i--)
            cout<<arr[i][colStart]<<" ";
        colStart++;
    }
    return 0;
}