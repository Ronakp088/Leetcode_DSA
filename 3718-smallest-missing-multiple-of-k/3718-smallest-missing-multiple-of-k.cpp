class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> exist(101);
        for(int& num: nums){
            exist[num] = true;
        }
        int ans = k;
        while(ans < 101){
            if( !exist[ans]) return ans;

            ans += k;
        }
        return ans;
    }
};