#include "iostream"
#include "vector"
#include "list"
#include "algorithm"

using namespace std;
//把每个都均匀的放在一个桶中
vector<int> bucketSort(vector<int>& array){
    size_t size = array.size();
    vector<vector<int>> temp(size);
    for(auto c: array){
        temp[c/10].emplace_back(c);
    }
    for(auto &c: temp)
        std::sort(c.begin(), c.end(),std::less<int>());
    vector<int> ans;
    for(auto c: temp){
        if(!c.empty()){
            for(auto b:c)
                ans.emplace_back(b);
        }
    }
    return ans;
}

int main(){
    vector<int> array{78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    for(auto c: bucketSort(array))
        cout << c <<" ";
}