#include "iostream"
#include "vector"

using namespace std;

int partition(vector<int>& array, int start, int end){
    int pos = end;
    int changedPos = start -1;
    for(int i = start; i < end; i++){
       if(array[i] <= array[pos]){
           changedPos++;
           swap(array[i], array[changedPos]);
       }
    }
    swap(array[changedPos + 1], array[end]);
    return changedPos + 1;
}

void quickSort(vector<int>& array, int start, int end){
    if(start < end){
        int pos = partition(array,start, end);
        quickSort(array, start, pos -  1);
        quickSort(array, pos + 1, end);
    }
}

int main(){
    vector<int> array{7, 8, 9, 2, 1, 3, 6};
    quickSort(array,0,array.size()-1);
    for(auto c: array){
        cout << c << " ";
    }
}