#include <iostream>
using namespace std;

int lsearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);

int main() {
    return 0;
}

int lsearch(int arr[], int size, int target) {
    for (int i=0; i<size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size -1;
    while(left <= right) {
        int mid = left + (right - left) / 2; // Prevents potential overflow
        // Check if target is present at mid
        if(arr[mid] == target)
            return mid;
        // If target greater, ignore left half
        if(arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    return -1; // Target not found
}
