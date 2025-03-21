#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

void insertion_sort(string *array, int N);
void swap(string &s1, string &s2);

int main() {
    string ar[SIZE]={"abcd","adas","asdr","aqwe","qwetyy","asdasd","asdasdq","xcvxc","ytreh","werwer"};
    
    insertion_sort(ar,SIZE);
    
    for (int i=0; i<SIZE; i++) {
        cout<<ar[i]<<endl; 
    }
    
    return 0; 
}

/* Insertion Sort Function */

void insertion_sort(string *array, int N) {
    int i,j; 
    
    for (i=1; i<N; i++) {
       for (j=i; j>=1; j--) {
          if (array[j]<array[j-1]) {
             swap(array[j], array[j-1]);
          }
          else {
             break;
          }
       }
    }
}

void swap(string &s1, string &s2) {
    string k = s1; 
    s1=s2;
    s2=k; 
}
