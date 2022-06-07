#include<iostream>
using namespace std;
#define N 3 // Assuming dimension of matrix as 3x3

// Using inplace approach
void clock90(int mat[N][N]){
    int temp;
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = temp;
        }
    }
}
void anticlock90(int mat[N][N]){
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = temp;
        }
    }
}
void printmatrix(int mat[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    int matrix[N][N];
    cout<<"Enter elements for the 3x3 matrix: \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin>>matrix[i][j];
    }

    clock90(matrix);
    cout<<"Original matrix after rotating 90 degrees clockwise:\n";
    printmatrix(matrix);

    //rotating original matrix 90 deg twice = 180 deg rotation
    clock90(matrix); 
    cout<<"Original matrix after rotating 180 degrees clockwise:\n";
    printmatrix(matrix);

    anticlock90(matrix); anticlock90(matrix); //to get the original matrix

    anticlock90(matrix);
    cout<<"Original matrix after rotating 90 degrees anti-clockwise:\n";
    printmatrix(matrix);

    //rotating original matrix 90 deg twice = 180 deg rotation
    anticlock90(matrix);
    cout<<"Original matrix after rotating 180 degrees anti-clockwise:\n";
    printmatrix(matrix);
    return 0;
}