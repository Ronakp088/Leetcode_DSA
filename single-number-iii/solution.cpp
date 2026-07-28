class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long Xor = 0;
        for(int i=0;i<nums.size();i++) Xor ^= nums[i];
        int rightmost =(Xor&(Xor-1))^Xor;
        int b1=0;
        int b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rightmost) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        return {b1,b2};
    }
};