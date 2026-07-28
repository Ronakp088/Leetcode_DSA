class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n <= 0 || n%4 != 0) return false;
        bool test1 = (n & (n-1)) == 0; // if it is power of 2 or not  
        bool test2 = (n-1)%3 == 0; // divisibilty of n-1 by 3  

        return test1&test2;
    }
};