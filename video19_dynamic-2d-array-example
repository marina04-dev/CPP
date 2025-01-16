// dynamic array: example
#include <iostream>
using namespace std;

int main() {
    int i,j;
    int **arr;
    int n=4;
    int m=4;
    
    // Memory allocation
    arr = new int *[n];
    if (!arr) cout<<"Error allocating memory!";
    for (i=0; i<n; i++) {
        arr[i] = new int [m];
        if (!arr[i]) cout<<"Error allocating memory!";
    }
    
    // Progress on the array 
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            arr[i][j]=i*j;
        }
    }
    
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    
    // Memory delete
    for (i=0; i<n; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}
