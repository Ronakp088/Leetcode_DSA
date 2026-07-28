class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans =0;
        for(int i=0;i<nums.size();i++){
            long long sum =0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                long long temp = sum;
                if(temp%10 == x){
                    while(temp>=10) temp/=10;
                    if(temp == x)ans++;
                }
            }
        }
        return ans;
    }
};