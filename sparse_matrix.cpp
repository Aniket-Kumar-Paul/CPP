#include<iostream>
using namespace std;

void addition(int* mat1, int* mat2, int m, int n){
    int sum,i,j;
    for(i = 0; i < m; i++){
        sum=0;
        for(j = 0; j < n; j++){
            sum=(*((mat1+i*n)+j)+*((mat2+i*n)+j));
            if(sum!=0)
                cout<<i<<"\t"<<j<<"\t"<<sum<<endl;
        }
    }
}

int main(){
    int m,n;
    cout<<"Enter m,n for mxn matrix: ";
    cin>>m>>n;
    // Matrix 1
    cout<<"Enter the sparse matrix1:\n";
    int matrix1[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>matrix1[i][j];
    }

    // Counting no. of non-zero elements
    int size=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            if(matrix1[i][j]!=0) size++;
    }
    int sparse1[3][size];

    // Converting to sparse matrix triplet representation
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix1[i][j]!=0){
                sparse1[0][k]=i; //row
                sparse1[1][k]=j; //column
                sparse1[2][k]=matrix1[i][j]; //value
                k++;
            }
        }
    }

    // Displaying the sparse matrix triplet representation
    cout<<"Sparse matrix 1 triplet representation as:\nrow\ncolumn\nvalue\n\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<size;j++)
            cout<<sparse1[i][j]<<" ";
        cout<<endl;
    }

    // Matrix 2
    cout<<"Enter the sparse matrix2:\n";
    int matrix2[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>matrix2[i][j];
    }

    // Counting no. of non-zero elements
    size=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            if(matrix2[i][j]!=0) size++;
    }
    int sparse2[3][size];

    // Converting to sparse matrix triplet representation
    int l=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix2[i][j]!=0){
                sparse2[0][l]=i; //row
                sparse2[1][l]=j; //column
                sparse2[2][l]=matrix2[i][j]; //value
                l++;
            }
        }
    }

    // Displaying the sparse matrix triplet representation
    cout<<"Sparse matrix 2 triplet representation as:\nrow\ncolumn\nvalue\n\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<size;j++)
            cout<<sparse2[i][j]<<" ";
        cout<<endl;
    }
    
    // Addition of the two sparse matrix
    cout<<"Addition of the two sparse matrix in the form of :-\n";
    cout<<"Row\tColumn\tValue"<<endl;
    addition((int *)matrix1,(int *)matrix2,m,n);

    return 0;
}