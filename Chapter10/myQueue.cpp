
#include "myQueue.h"

int  myQueue::deQueue() {
    if(empty())
        return -1;
    int ans = array[head];
    head = (head + 1) % size;
    return ans;
}

bool myQueue::empty() {
    if(tail == head)
        return true;
    return false;
}

void myQueue::enQueue(int x) {
    if((tail + 1) % size == head)
        return;
    else {
        array[tail] = x;
        tail = (tail + 1) % size;
    }
}
