class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        n -= 10;
        int t = 9;
        int turn = 1; // bob;
        while(n >= t){
            n -= t;
            t--;
            turn++;
        }
        if(turn%2 == 1) return true;

        return false;
    }
};
/*
turn 1;
n = 24
t = 9
turn = 2;
n = 15
t = 8;
turn 3
n = 7
t =7;



*/