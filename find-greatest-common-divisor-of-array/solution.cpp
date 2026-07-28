class Solution {
public:
    int findGCD(vector<int>& nums) {
        int MaxNo = INT_MIN;
        int MinNo = INT_MAX;
        for(int i=0;i<nums.size();i++){
            MaxNo = max(MaxNo,nums[i]);
            MinNo = min(MinNo,nums[i]);
        }
        return gcd(MaxNo,MinNo);
    }
};