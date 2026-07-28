class Solution {
public:
   void checkAllCombo(int index,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans){
        if (target == 0){
            ans.push_back(temp);
            return; 
            }
        if (index == candidates.size()) return;
        
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            checkAllCombo(index,target-candidates[index],candidates,temp,ans);
            temp.pop_back(); // kyu ki jab not pick wala case lenge to uss mei pick wala nahi aana chahiye
        }
        checkAllCombo(index+1,target,candidates,temp,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        checkAllCombo(0,target,candidates,temp,ans);
        return ans;
    }
};