#include "iostream"
#include "vector"

using namespace std;

void merge(vector<int>& array, int start, int mid, int end) {
    auto startIt = array.begin() + start;
    vector<int> left(startIt, startIt + (mid - start) + 1);
    vector<int> right(startIt + (mid - start) + 1, startIt + (end - start) + 1);
    auto leftIt = left.begin();
    auto rightIt = right.begin();
    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            *startIt = *leftIt;
            startIt++;
            leftIt++;
        } else {
            *startIt = *rightIt;
            startIt++;
            rightIt++;
        }
    }
    if (leftIt == left.end()) {
        while (rightIt != right.end()) {
            *startIt = *rightIt;
            rightIt++;
            startIt++;
        }
    } else {
        while (leftIt != left.end()) {
            *startIt = *leftIt;
            leftIt++;
            startIt++;
        }
    }
}


void merge_sort(vector<int>& array, int start, int end){
    if(start >= end)
        return ;
    int mid =  (end + start) / 2;
    merge_sort(array, start,mid);
    merge_sort(array, mid + 1, end);
    merge(array, start, mid, end);
}

int main(){
    vector<int> array = {1, 3, 5, 7, 9, 2, 4, 6, 8,10};
    merge_sort(array,0,9);
    for(auto c : array)
        cout << c << " ";
}
