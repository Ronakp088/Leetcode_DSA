class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        if( temp == nums) return 0;
        int k = -1;
        for(int i = 0;i<n;i++){
            if( nums[i] != i){
                k &= nums[i];
                if( k == 0) return 0;
            }
        }

        return max(k,0);
    }
};