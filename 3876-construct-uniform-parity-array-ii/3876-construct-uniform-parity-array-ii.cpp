class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even =0;
        int odd =0;
        int n = nums1.size();
        int check = INT_MAX; 
        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 0) {
                even++;
                }
            else {
                odd++;
                check = min(check,nums1[i]);
                }
        }
        if(even == n || odd == n) return true;
        // for odd
        for(int i =0;i<n;i++){
            if(nums1[i]%2 == 0){
                if(nums1[i]-check < 1) return false;
            }
        }

        return true;

    }
};