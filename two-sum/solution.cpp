class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
            mpp[nums[0]] = 0;
        for (int i=1; i<nums.size(); i++){
            int temp = target - nums[i];
            if(mpp.find(temp) != mpp.end() ){
                return {mpp[temp],i};
            }
           else mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};