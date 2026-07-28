class Solution {
public:
    vector<int> Sum(vector<vector<int>>& mat){
        int n = mat.size();
        int sum = INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++){
           int temp = accumulate(mat[i].begin(),mat[i].end(),0);
            if(temp>sum){
                sum = temp;
                index =i;
            }
        }
        return {index,sum};
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       vector<int> ans = Sum(mat);
        return ans;
    }
};