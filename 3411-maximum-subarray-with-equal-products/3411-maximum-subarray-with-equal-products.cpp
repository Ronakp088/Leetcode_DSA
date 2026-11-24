class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            unsigned int  product = 1;
            long long  g = 0;
            long long  l = 1;
            for(int j =i;j<n;j++){
                product *= 1LL*nums[j];
                g = gcd(g,nums[j]);
                l = lcm(l,nums[j]);
                if(product == 1LL*l*g) ans = max(ans,j-i+1);
            }
        }

        return ans;
    }
};