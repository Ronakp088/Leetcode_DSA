class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j = n-1;
        int ans =0;
        while(i<j){
            int temp = (j-i)*min(nums[i],nums[j]);
            if(nums[i]<=nums[j]) i++;
            else j--;
            ans = max(ans,temp);
        }
        return ans;

    }
};