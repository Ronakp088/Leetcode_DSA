class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if( n == 1){
             return 0;
        }
        vector<pair<int,int>> v(n);
        v[0].first = nums[0];
        v[n-1].second = nums[n-1];
        for(int i=1;i<=n-2;i++){
        v[i].first = max(nums[i],v[i-1].first);
        v[n-1-i].second = min(nums[n-1-i],v[n-i].second);
        }
        v[n-1].first = max(nums[n-1],v[n-2].first);
        v[0].second = min(nums[0],v[1].second);

        for(int i =0;i<n;i++){
            if((v[i].first-v[i].second) <= k) return i;
        }

        return -1;
    }
};