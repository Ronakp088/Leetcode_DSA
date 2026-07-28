class Solution {
public:
    long long nCr(int n, int r){
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i) / (i + 1);
    }
    return res;
}
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex == 0) return {1};
        else{
            for(int i=0;i<=rowIndex;i++){
                ans.push_back(nCr(rowIndex,i));
            }
        }
        return ans;
    }
};