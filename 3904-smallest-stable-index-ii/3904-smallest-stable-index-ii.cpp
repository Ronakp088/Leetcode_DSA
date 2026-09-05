class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if( n == 1){
             return 0;
        }
        vector<int> v(n);
        v[0] = nums[0];
        for(int i =1;i<n;i++){
            v[i] = max(nums[i],v[i-1]);
        }
        int mini = nums[n-1];
        v[n-1] = v[n-1]-mini;
        int ans = -1;
        if(v[n-1] <= k) ans = n-1;
        for(int i =n-2;i>=0;i--){
            mini = min(nums[i],mini);
            v[i] = v[i] - mini;
            if(v[i] <= k) ans =i;
        }
        
        return ans;
    }
};