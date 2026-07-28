class Solution {
public:
    bool isPerfectSquare(int num) {
        double n = pow(num,0.5);
        if(int(n) == n) return true;
        return false;
    }
};