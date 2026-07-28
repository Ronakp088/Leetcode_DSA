class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> v(n, 0);
        if(nums == v && goal == 0) return (n*(n+1))/2;
        else if(nums == v && goal > 0) return 0;

        int r = 0;
        int l = 0, l2 = 0;
        int ans = 0;
        int sum = 0, sum2 = 0;

        while(r < n){
            sum += nums[r];
            sum2 += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            while(sum2 > goal - 1 && l2 <= r){
                sum2 -= nums[l2];
                l2++;
            }

            ans += (l2 - l);
            r++;
        }
        return ans;
    }
};