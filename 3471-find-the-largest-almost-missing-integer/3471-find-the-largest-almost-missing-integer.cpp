class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        if(n == 1) return nums[0];
        int flag =0;
        if(n == k){
            int g =0;
            int maxi =0;
            unordered_map<int,int> mpp2;
            for(int i =0;i<n;i++){
               if( nums[i] != nums[0]){
                 flag =1;
               }
                mpp2[i]++;
                if(mpp2[i] >= maxi){
                    maxi = mpp2[i];
                    g = max(g,nums[i]);
                }
            }
        if(flag == 0) return nums[0];
        else return g;
        }
        int i =0;
        int j = k-1;
        while(j<n){
            for(int l = i;l <= j ;l++){
                mpp[nums[l]]++;
            }
            i++;
            j++;
        }
        int ans =-1;
        for(auto it: mpp){
            if(it.second == 1){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};