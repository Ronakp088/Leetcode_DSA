class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<=n-2;i+=2){
            int j = i+1;
            string s = to_string(nums[j]);
            int temp = nums[i];
            for(int k = 0;k<s.size();k++){
                temp = temp*10 + (s[k]-'0');
            }
            ans = min(ans,temp);
        }
        return ans;
    }
};