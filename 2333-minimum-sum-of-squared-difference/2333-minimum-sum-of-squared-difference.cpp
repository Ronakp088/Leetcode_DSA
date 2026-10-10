class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int M = 0;
        long long k = 1LL*k1+k2;
        for(int i =0;i<n;i++){
            M = max(M,abs(nums1[i]-nums2[i]));
        }
        vector<int> v(M+1,0);
        for(int i = 0;i<n;i++){
            v[abs(nums1[i]-nums2[i])]++;
        }
        for(int i = M;i>0 && k>0;i--){
            long long take = min((long long)v[i],k);
            v[i] -= take;
            v[i-1] += take;
            k -= take;
        }
        long long ans =0;
        for(int i = 1;i <= M;i++){
            ans += 1LL*v[i]*i*i;
        }
        return ans;
        
    }
};