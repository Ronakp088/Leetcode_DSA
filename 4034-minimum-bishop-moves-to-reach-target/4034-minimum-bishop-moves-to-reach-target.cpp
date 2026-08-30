class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        int check = s[0]-s[1];
        int check2 = t[0]-t[1];
        if(abs(check%2) == 0 && abs(check2%2) == 1) return -1;
        if(abs(check%2) == 1 && abs(check2%2) == 0) return -1;
        int c1 = s[0]+s[1];
        int c2 = t[0]+t[1];
        int d1 = abs(check-check2)/2;
        int d2 = abs(c1-c2)/2;
        return min(min(d1,d2)+1,2);
    }
};