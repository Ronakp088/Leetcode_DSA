class Solution {
public:
    int maxPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int ans = 1;
        map<int,int> mpp2;
        int max2 =0;
        for(int i =0;i<n;i++){
            mpp2[nums[i][0]]++;
            max2 = max(max2,mpp2[nums[i][0]]);
        }
        ans = max(ans,max2);
        for(int i =0;i<n;i++){
            map<double,int> mpp;
            int maxi =0;
            for(int j =i+1;j<n;j++){
                if(nums[j][0] - nums[i][0] != 0){
                    mpp[(double)(nums[j][1]-nums[i][1])/(nums[j][0]-nums[i][0])]++;
                    maxi = max(maxi,mpp[(double)(nums[j][1]-nums[i][1])/(nums[j][0]-nums[i][0])]);
                }
            }
            ans = max(ans,maxi+1);
            if(ans > n/2) return ans;
        }
        return ans;
    }
};