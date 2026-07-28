class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp.find(nums[i]) != mp.end() && mp[nums[i]] ==  3) mp.erase(nums[i]);
             
        }
        return mp.begin()->first;
    }
};