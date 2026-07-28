class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       // int n = nums.size();
        // int st = -1;
        // int ed = -1;
        if(nums.size() == 0) return {-1,-1};
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if( lb == nums.size() || nums[lb] != target) return {-1,-1};
        int ub =upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        return {lb,ub-1};
    }
};