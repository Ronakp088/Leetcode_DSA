class Solution {
public:
    void backTrack(int idx, int sum, int k, int n, vector<int>& nums,
                   vector<int>& temp, vector<vector<int>>& ans) {
        if (sum == n && temp.size() == k && idx <= nums.size()) {
            ans.push_back(temp);
            return;
        }
        if (temp.size() > k || sum > n || idx >= nums.size())
            return;

        temp.push_back(nums[idx]);
        sum += nums[idx];
        backTrack(idx + 1, sum, k, n, nums, temp, ans); // include
        temp.pop_back();
        sum -= nums[idx];
        backTrack(idx + 1, sum, k, n, nums, temp, ans); // exclude
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i < 10; i++) {
            nums.push_back(i);
        } // nums = [1,2,3,4,5,6,7,8,9]
        vector<vector<int>> ans;
        vector<int> temp;
        backTrack(0, 0, k, n, nums, temp, ans);

        return ans;
    }
};