class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int alternatingSum =0;
        for(int i=0;i<nums.size();i++){
            alternatingSum += (pow(-1,i)*nums[i]);
        }
        return alternatingSum;
    }
};