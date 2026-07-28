class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m=0 ,l =0;
        int ans =0;
        int cnt =0;
        for(int r=0;r<n;r++){
            if(nums[r]%2) cnt++;
            while(cnt >k){
                if(nums[l]%2) cnt--;
                l++;
                m =l;
            }
            if(cnt == k){
                while(!(nums[m]%2)) m++;
                ans += m-l+1; 
            }
        }
        return ans;
    }
};