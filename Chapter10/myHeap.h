
#ifndef C_PROJECT_MYHEAP_H
#define C_PROJECT_MYHEAP_H
#include "vector"

class myHeap{
private:
    std::vector<int> array;
    int top;
public:
    bool stackEmpty();
    void push(int x);
    int pop();
};

#endif //C_PROJECT_MYHEAP_H
