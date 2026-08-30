class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int ans =0;
        mpp[nums[0]]++;
        ans++;
        for(int i=1;i<n;i++){
            if(mpp[nums[i]] == 0){mpp[nums[i]] = 1;ans++;}
            else if(i>0 && mpp[nums[i]] == 1 && nums[i-1] != nums[i]) {ans--;mpp[nums[i]]=2;}
        }

        return ans;
    }
};