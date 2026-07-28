class Solution {
public:
    void backTrack(int idx, vector<int>& temp, vector<int>& nums,
                   vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue; // duplicates ko hata ne ke liye usse skip hi kardo
                          // simple
            temp.push_back(nums[i]);
            backTrack(i + 1, temp, nums, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        backTrack(0, temp, nums, ans);

        return ans;
    }
};