#include<iostream>
#include<cstring>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<n; i++){
        int bestIdx = -1;
        for (int j=0; j<m; j++){
            if (blockSize[j] >= processSize[i]){
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1){
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++){
        cout<<" "<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if (allocation[i] != -1)
            cout <<allocation[i]+1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
    cout<< "\n\nCurrent left out block sizes:\n";
    for (int i = 0; i < m; i++){
        cout<<blockSize[i]<<" ";
    }
}

int main(){
    int blockSize[] = {300, 600, 350, 200, 750, 125};
    int processSize[] = {115, 500, 358, 200, 375};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
  
    bestFit(blockSize, m, processSize, n);
    
    return 0 ;
}