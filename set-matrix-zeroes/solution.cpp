class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();      // rows
    int n = matrix[0].size();   // columns
   vector<int> row(m, 0);      // m rows, all 0
vector<int> column(n, 0);   // n columns, all 0
        for( int i = 0;i<m;i++){
            for(int j =0 ; j<n ;j++){
                if(matrix[i][j] == 0){
                    column[j] = 1;
                    row[i] = 1;
                }
            }
        }
        for( int i = 0;i<m;i++){
            for(int j =0 ; j<n ;j++){
                if(row[i] || column[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};