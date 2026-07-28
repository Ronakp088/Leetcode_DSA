class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c = 0;
        int ans = 0;
        int n = nums.size();
        int l = 0;

        for(int r = 0 ; r < n ; r++){

            if(nums[r] == 0) c++;

            while(c > k){
                if(nums[l] == 0) c--;
                l++;
            }

            ans = max(ans , r - l + 1);
        }

        return ans;

    }
};
