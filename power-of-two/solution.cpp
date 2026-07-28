class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1 ) return true;
        if(n%2 != 0 || n == 0 || n < 0) return false;
        if((n & (n-1)) == 0) return true;

        return false;
    }
};