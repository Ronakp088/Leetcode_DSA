class Solution {
public:
    int max_element_index(vector<vector<int>>& mat,int mid){
        int index =0;
        int max = INT_MIN;
        for(int i=0;i<mat.size();i++){
            if(mat[i][mid] > max) {
                max = mat[i][mid];
                index =i;
            }
        }
        return index;
    }
      
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(); // row
        int m = mat[0].size(); // column
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = (low + high) >> 1;
            int p1 = max_element_index(mat,mid);
              if(mid == 0 && mat[p1][mid] > mat [p1][mid+1]) return {p1,mid};
              else if(mid == m-1 && mat[p1][mid] > mat[p1][mid-1]) return {p1,mid};
              else{
                if(mat[p1][mid] > mat[p1][mid-1] && mat[p1][mid] > mat[p1][mid+1]) return {p1,mid};
                else if(mat[p1][mid] < mat[p1][mid+1]) low = mid +1;
                else high = mid-1;
              }
    
        }
        return {-1,-1};
    }
};