class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans(nums.size(),0);
        for(int i =0;i<nums.size();i++){
            if(i%2 == 0) ans[i+1] = nums[i];
            else ans[i-1] = nums[i];
        }
        return ans;
    }
};