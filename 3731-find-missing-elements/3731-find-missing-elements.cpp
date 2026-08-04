class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n  = nums.size();
        int Min = *min_element(nums.begin(),nums.end());
        int Max = *max_element(nums.begin(),nums.end());
        vector<int> ans;  
        int m = Max-Min+1;
        vector<int> v(m,0);
        for(int i =0;i<n;i++){
            v[nums[i]-Min] = 1;
        }
        for(int i =0;i<m;i++){
            if(v[i] == 0) ans.push_back(i+Min);
        }
        return ans;
    }
};