class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int cnt =0;
        int k = nums.size();
        if(n == 0) return true;
        if(k == 1 && nums[0] == 0 && n == 1) return true;
        if(k == 1 && nums[0] == 1 && n != 0) return false;
        if(k == 1 && nums[0] == 0 && n >= 1) return false;
        int i =0;
        while(i<k){
            if(cnt >= n) return true;
            if(i == 0 && nums[i] == 0 && nums[i+1] == 0){
                cnt++;
                nums[i] = 1;
                i += 2;
            }
            else if(i == k-1 && nums[k-2] == 0 && nums[k-1] == 0){
                cnt++;
                i++;
            }
            else if(nums[i] == 0 && i > 0 && i < k-1 && nums[i-1] == 0 && nums[i+1] == 0){
                cnt++;
                nums[i] =1;
                i+2;
            }
            else i++;
        }
        if(cnt >= n) return true;
        return false;
    }
};