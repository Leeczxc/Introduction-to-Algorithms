#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> squareMatrixMultiply(vector<vector<int>> a,vector<vector<int>> b){
    int n = a.size();
    vector<vector<int>> ans(row,vector<int>(column));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[i][j] = 0;
            for(int k = 0; k < n ;k++)
                ans[i][j] += a[i][k]*b[k][j];
        }
    }
    return ans;
}

vector<vector<int>> squareMatrixMultiplyRecursive(vector<vector<int>> a,vector<vector<int>> b){
    int n = a.size();
    vector<vector<int>> ans;
    if(n == 1)
        ans[0][0] = a[0][0] * b[0][0];
    else{ partition A,B and C as in equations
        ans11 = squareMatrixMulptiplyRecursive(A11,B11)+ ...
    }
}
int main(){
    vector<vector<int>> a = {{1, 1}, {1, 1}};
    vector<vector<int>> b = {{2, 2}, {2, 2}};

}