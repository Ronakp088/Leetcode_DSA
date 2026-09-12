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
            if(it.second.size() >= 3){
                int check = it.second[1]-it.second[0];
                int flag = 0;
                for(int i=2;i< it.second.size();i++){
                    if(check != it.second[i]-it.second[i-1]) flag = 1;
                }
                if(flag == 0) ans++;
            } 
        }

        return ans;
    }
};