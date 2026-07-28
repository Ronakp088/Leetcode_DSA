class Solution {
public:
    void backTrack(int idx,int k,vector<int>& temp,int n,vector<vector<int>>& ans){
        if(temp.size() == k ){
            ans.push_back(temp);
            return;
        }
        if(idx == n) return;
        temp.push_back(idx+1);
        backTrack(idx+1,k,temp,n,ans); // include
        temp.pop_back();
        backTrack(idx+1,k,temp,n,ans); // exclude
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        backTrack(0,k,temp,n,ans);

        return ans;
    }
};