class Solution {
    int sum(int t){
        int ans =0;
        while(t > 0){
            ans += t%10;
            t/=10;
        }

        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(sum(nums[i]) == i) return i;
        }

        return -1;
    }
};