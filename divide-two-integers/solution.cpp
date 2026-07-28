class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        int sign = 1;
        if(dividend <= 0 && divisor >0) sign = -1;
        if(dividend >= 0 && divisor <0) sign = -1;
        long long m = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long  ans =0;
        while( m >= d){
            int cnt = 0; // this is power of 2
            while(m >= (d << (cnt+1))) cnt++; // d << snt+1  == d*(2 ki power cnt+1)
            ans += 1<<cnt; // same 2 ki power cnt
            m -= (d<<cnt);
        }
        if(ans == (1<<31) && sign == 1) return INT_MAX;
        if(ans == (1<<31) && sign == -1) return INT_MIN;

        return sign*ans;
    }
};  