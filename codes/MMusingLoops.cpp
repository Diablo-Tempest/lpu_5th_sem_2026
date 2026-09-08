#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>
multiply(vector<vector<int>>
    &mat1,
    vector<vector<int>> &mat2){
        int n = mat1.size(), m = mat1[0].size(), q = mat2[0].size();
        // initialize the result matrix with dimension n x q filled with 0s.
        vector<vector<int>> res(n, vector<int>(q, 0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j< q; j++){
                for(int k = 0; k< m; k++){
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return res;
    }
int main(){
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    vector<vector<int>> mat2 = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    vector<vector<int>> res = multiply(mat1, mat2);
    for(int i = 0; i< res.size(); i++){
        for(int j = 0; j< res.size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }
    return 0;
}