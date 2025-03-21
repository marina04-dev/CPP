// dynamic array: example
#include <iostream>
using namespace std;

int main() {
    int *arr;
    int n=4;
    
    // Memory allocation
    arr = new int [n];
    if (!arr) cout<<"Error allocating memory!";
    
    // Progress on the array 
    for (int i=0; i<n; i++) {
        arr[i]=i*i;
    }
    
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    
    // Memory delete
    delete [] arr;
    return 0;
}
