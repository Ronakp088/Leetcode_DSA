class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n =nums.size();
        long long sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        sum -= x;
        if( sum == 0) return n;
        int ans = 0;
        int l =0;
        int r= 0; 
        long long temp =0;
        while(r<n){
            temp += nums[r];
            while(l<n && temp > sum){
                temp-=nums[l];
                l++;
            }
            if(sum == temp){
                ans = max(ans,r-l+1);
            }
            r++;
        }

        if(ans == 0) return -1;
        return n-ans;
    }
};