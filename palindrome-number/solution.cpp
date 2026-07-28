class Solution {
public:
    bool isPalindrome(int x) {
        long long rn = 0;
        long long y = x;
        while (y > 0) {
            rn = rn * 10 + y % 10;
            y = y / 10;
        }
        if (rn == x) {
            return true;
        } else {
            return false;
        }
    }
};