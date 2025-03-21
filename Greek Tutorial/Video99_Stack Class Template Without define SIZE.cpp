#include <iostream>
#include <string>
using namespace std;


template <typename T, int STACK_SIZE>
class Stack {
    public:
        Stack();
        bool empty();
        bool full();
        bool push(T elem);
        bool pop(T *elem);
    private:
        T array[STACK_SIZE];
        int top;
};

int main() {
    /* Integer Stack */
    Stack<int, 100> st;
    int temp;
    
    st.push(2);
    st.push(5);
    
    st.pop(&temp);
    cout<<temp<<" ";
    st.pop(&temp);
    cout<<temp<<" ";
    
    
    /* String Stack */
    Stack<string, 100> st2;
    string temp2;
    
    st2.push("Hello");
    st2.push("World");
    
    st2.pop(&temp2);
    cout<<temp2<<" ";
    st2.pop(&temp2);
    cout<<temp2<<" ";
    return 0;
}

template <typename T, int STACK_SIZE>
Stack<T,STACK_SIZE>::Stack() {
    top = 1;
}

template <typename T, int STACK_SIZE>
bool Stack<T,STACK_SIZE>::empty() {
    return top == -1;
}

template <typename T, int STACK_SIZE>
bool Stack<T,STACK_SIZE>::full() {
    return top == STACK_SIZE-1;
}

template <typename T, int STACK_SIZE>
bool Stack<T,STACK_SIZE>::push(T elem) {
    if (full()) {
        return false;
    }
    top++;
    array[top]=elem;
    return true;
}

template <typename T, int STACK_SIZE>
bool Stack<T,STACK_SIZE>::pop(T *elem) {
    if (empty()) {
        return false;
    }
    *elem = array[top];
    top--;
    return true;
}
