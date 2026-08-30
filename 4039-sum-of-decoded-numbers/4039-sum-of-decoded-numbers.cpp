class Solution {
public:
    long long Pow(long long x,long long y){
        int ans =1;
        long long Mod = 1000000007; 
        long long f =y;
        while(f >0){
            if(f%2 == 1){
                ans = (ans*x)%(Mod);
            }
            x = (x*x)%(Mod);
            f/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long Mod = 1000000007;
        int n = nums.size();
        long long  ans =0;
        for(int i =0;i<n;i++){
            int w = nums[i]%10;
            if( w == 0) continue;
            long long d = nums[i]/10;
            string s = to_string(d);
            int digi = s.size();
            long long x = stoll(s.substr(0,w));
            long long y =stoll(s.substr(w,digi-w));

            ans  = (ans + Pow(x,y))%Mod;
        }

        return ans;
    }
};