class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2){
            if(nums[1] != nums[0]) return 2;
            else return 1;
        }
        int inc = 0;
        int dec = 0;
        int ans = 1;
        if(nums[1] > nums[0]) {inc+=2;ans =2;dec = 1;}
        else if(nums[1] < nums[0]) {dec+=2;ans=2;inc =1;}
        else {
            inc++;
            dec++;
        }
        for(int i =2;i<n;i++){
            if(nums[i] > nums[i-1]){
                dec =1;
                inc++;
                ans = max(ans,inc); 
            }
            else if(nums[i] < nums[i-1]){
                inc = 1;
                dec++;
                ans = max(ans,dec);
            }
            else{
                inc =1;
                dec =1;
            }
        }
        return ans ;
    }
};