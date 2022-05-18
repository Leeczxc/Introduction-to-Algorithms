#include "vector"
#include "iostream"

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

int randomizedSelect(vector<int>& array, int start, int end, int pos){
    if(start == end)
        return array[start];
    int position = partition(array, start, end);
    if(pos == position)
        return array[pos];
    else if(pos < position)
        return randomizedSelect(array, start, position - 1, pos);
    else
        return randomizedSelect(array,position + 1, end, pos);
}

int main(){
    vector<int> array{ 1, 23,324,5435,654,7,876,98};
    cout << randomizedSelect(array,0, array.size() - 1, 2);
}