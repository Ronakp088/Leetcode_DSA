class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans =0;
        for(auto& it : mp){
            if(it.second.size() == 3){
                if(it.second[1]- it.second[0] == it.second[2]-it.second[1]) ans++;
            } 
        }

        return ans;
    }
};