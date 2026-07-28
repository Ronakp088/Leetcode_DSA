class Solution {
public:
    void backTrack(vector<bool>& used,vector<int>& temp,vector<int>& nums,vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backTrack(used,temp,nums,ans);
            temp.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(),false); // ye ek nums ke size ka vector banayega jismei sab false hongee 

        backTrack(used,temp,nums,ans);

        return ans;
    }
};