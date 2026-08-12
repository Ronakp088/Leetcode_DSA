class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans =0;
        int j =0;
        int i =0;
        while(i<n){
            if(mp[nums[i]] < k){
                mp[nums[i]]++;
                ans = max(ans,i-j+1);
                i++;
            }
            else{
                mp[nums[j]]--;
                j++;
            }
        }
        return ans;
    }
};