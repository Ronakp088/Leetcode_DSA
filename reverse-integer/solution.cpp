class Solution {
public:
    int reverse(int x) {
        int sign;
        if (x > 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        x = llabs(x);
        long long rn = 0;
        while (x > 0) {
            rn = rn * 10 + x % 10;
            x = x / 10;
        }
        if(rn > INT_MAX || rn< INT_MIN) return 0;
        return sign * rn;
    }
    };