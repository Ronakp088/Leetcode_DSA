class Solution {
public:
    int candy(vector<int>& nums) {
        int n =nums.size();
        if(n == 1) return 1;
        int ans = 1;
        int peak =0;
        int down =0;
        int i =1;
        while(i<n){
            if(nums[i] == nums[i-1]){
                ans+=1;
                i++;
                continue;
            }
            peak =1;
            while(i<n && nums[i] > nums[i-1]){
                peak += 1;
                ans += peak;
                i++;
            }
            down =1;
            while( i<n && nums[i] < nums[i-1]){
                ans += down;
                down += 1;
                i++;
            }
            if(down > peak) ans += down-peak;
        }
        return ans;
    }
};