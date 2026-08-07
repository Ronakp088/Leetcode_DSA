class Solution {
public:
    static bool comp(vector<int> val1,vector<int> val2){
        return val1[1]<val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comp);
        int cnt = 1;
        int last = nums[0][1];
        for(int i =1;i<n;i++){
            if(nums[i][0] >= last){
                cnt++;
                last = nums[i][1];
            }
        }
        return n - cnt;
    }
};