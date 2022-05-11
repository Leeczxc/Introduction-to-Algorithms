#include "iostream"
#include "vector"

using namespace std;

void maxHeapify(vector<int>& array, int pos){
    int leftPos = 2 * pos + 1;
    int rightPos = 2 * (pos + 1);
    int size = array.size();
    int largestPos = pos;
    if(leftPos <= size && array[leftPos] > array[pos])
        largestPos = leftPos;
    if(rightPos <= size && array[rightPos] > array[largestPos])
        largestPos = rightPos;
    if(largestPos == pos)
        return;
    swap(array[pos],array[largestPos]);
    maxHeapify(array,largestPos);
};

void buildMaxHeap(vector<int>& array){
    int pos = array.size() / 2;
    while(pos >= 0){
        maxHeapify(array, pos);
        pos--;
    }
}

vector<int> heapSort(vector<int> array){
    int size = array.size();
    buildMaxHeap(array);
    vector<int> ans;
    ans.emplace_back(array[0]);
    array.erase(array.begin());
    while(!array.empty()){
        maxHeapify(array,0) ;
        ans.emplace_back(array[0]);
        array.erase(array.begin());
    }
    return ans;
}

int heapMaximum(vector<int>& array){
    return array[0];
}

int headExtractMax(vector<int> array){
    if(array.size() == 0){
       cout << "heap underflow";
       return -1;
    }
    int ans = array[0];
    swap(array[0],array[array.size()-1]);
    array.erase(array.end()-1);
    maxHeapify(array,0);
    return ans;
}

void heapIncreaseMax(vector<int>& array, int pos, int key){
    if(key < array[pos])
        return;
    array[pos] = key;
    while(pos > 0 && array[(pos - 1)/2] < array[pos]){
        swap(array[(pos - 1)/2], array[pos]);
        pos = (pos - 1) / 2;
    }
}

void maxHeapInsert(vector<int>& array, int key){
    array.emplace_back(-1);
    heapIncreaseMax(array,array.size() - 1, key);
}

int main(){
    vector<int> array{5, 3, 17, 10, 84, 19, 6, 22,9};
    buildMaxHeap(array);
    maxHeapInsert(array,90);
    for(auto c: array){
        cout << c << " ";
    }
}