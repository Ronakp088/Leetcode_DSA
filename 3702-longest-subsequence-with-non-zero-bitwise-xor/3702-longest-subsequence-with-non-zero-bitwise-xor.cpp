class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        int Xor = 0;
        for(int i =0;i<n;i++){
            if(nums[i] > 0) flag  =1;
            Xor ^= nums[i];
        }
        if(Xor == 0){
            if(flag == 1){
                return n-1;
            }
            else return 0;
        }

        return n;
    }
};