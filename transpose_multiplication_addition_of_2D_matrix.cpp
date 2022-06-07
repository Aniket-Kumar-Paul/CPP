#include<iostream>
using namespace std;

void transpose(int* mat, int m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout<<*((mat+j*n)+i)<<" ";
        cout<<endl;
    }
}
void addition(int* mat1, int* mat2, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout<<(*((mat1+i*n)+j)+*((mat2+i*n)+j))<<" ";
        cout<<endl;
    }
}
void multiplication(int* mat1, int* mat2, int l, int m, int n){
    int sum;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            sum=0;
            for(int k = 0; k < m; k++)
                sum+=(*((mat1+i*m)+k))*(*((mat2+k*n)+j));
            cout<<sum<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int l,m,n;
    cout<<"Enter m & n: ";
    cin>>m>>n;
    int m1[m][n],m2[m][n];
    cout<<"Enter matrix 1:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>m1[i][j];
    }
    cout<<"Enter matrix 2:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>m2[i][j];
    }

    cout<<"\nTranspose of matrix 1:\n";
    transpose((int *)m1,m,n);
    cout<<"\nTranspose of matrix 2:\n";
    transpose((int *)m2,m,n);
    
    cout<<"\nAddition of matrix 1 and 2:\n";
    addition((int *)m1,(int *)m2,m,n);

    cout<<"\nFor multiplication,\nEnter l,m for lxm matrix 1:\n";
    cin>>l>>m;
    int mat1[l][m];
    cout<<"Enter matrix 1:\n";
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++)
            cin>>mat1[i][j];
    }
    cout<<"\nEnter m,n for mxn matrix 2:\n";
    cin>>m>>n;
    int mat2[m][n];
    cout<<"Enter matrix 2:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>mat2[i][j];
    }
    cout<<"\nMultiplication of matrix 1 and 2:\n";
    multiplication((int *)mat1,(int *)mat2,l,m,n);
    return 0;
}