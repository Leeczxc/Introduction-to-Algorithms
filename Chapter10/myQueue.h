#ifndef C_PROJECT_MYQUEUE_H
#define C_PROJECT_MYQUEUE_H


#include <cstddef>
#include "vector"

class myQueue {
private:
    int head = 0;
    int tail = 0;
    int size = 3;
    std::vector<int> array;
public:
    myQueue(){
        array.resize(size);
    }
    bool empty();
    void enQueue(int x);
    int deQueue();
};


#endif //C_PROJECT_MYQUEUE_H
