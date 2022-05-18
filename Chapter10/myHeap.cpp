#include "myHeap.h"

bool myHeap::stackEmpty() {
    if(top == 0)
        return true;
    return false;
}

void myHeap::push(int x) {
    array.emplace_back(x);
    top++;
}

int myHeap::pop() {
    if(top == 0)
        return -1;
    top--;
    return array[top];
}
