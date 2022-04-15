#include "iostream"
#include "vector"

using namespace std;

void merge(vector<int>& array, int start, int mid, int end){
    auto startIt = array.begin() + start ;
    vector<int> left(startIt,startIt + ( mid - start) + 1);
    vector<int> right(startIt + (mid-start) + 1,startIt + ( end - start ) + 1);
    auto leftIt= left.begin();
    auto rightIt = right.begin();
    while(leftIt != left.end() && rightIt != right.end()){
        if(*leftIt <= *rightIt){
            *startIt = *leftIt;
            startIt++;
            leftIt++;
        }
        else{
            *startIt = *rightIt;
            startIt++;
            rightIt++;
        }
    }
    if(leftIt == left.end()){
        while(rightIt != right.end()){
            *startIt = *rightIt;
            rightIt++;
        }
    }
    else{
        while(leftIt != left.end()){
            *startIt = *leftIt;
            leftIt++;
        }
    }
}
