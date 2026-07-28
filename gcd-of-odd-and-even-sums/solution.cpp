class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int OddSum = n*n;
        int EvenSum = n*(n+1);
        return gcd(OddSum,EvenSum);
    }
};