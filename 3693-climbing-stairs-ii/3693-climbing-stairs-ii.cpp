class Solution {
public:
    int f(int i,vector<int>& nums,vector<int> &dp){
        if(i == 0) return 0;
        int arr[] = {-1,-2,-3};
        int temp = INT_MAX;
        for(int j = 0;j<3;j++){
            int ni = i + arr[j];
            if(ni >= 0 ){
                int y = 0;
                if(dp[ni] != -1) y = dp[ni]; 
                else y = f(ni,nums,dp);
                int x = y + nums[i-1] + (i-ni)*(i-ni);
                temp = min(temp,x);
            }
        }
        return dp[i] = temp;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return f(n,costs,dp);
    }
};