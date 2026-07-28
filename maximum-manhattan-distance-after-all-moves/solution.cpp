class Solution {
public:
    int maxDistance(string moves) {
        int x =0;
        int y =0;
        int cnt =0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'U') y++;
            else if(moves[i] == 'D') y--;
            else if(moves[i] == 'R') x++;
            else if(moves[i] == 'L') x--;
            else cnt++;
        }
        if(abs(x) >= abs(y)){
            if(x<0) x -= cnt;
            else x += cnt;
        }
        else{
            if(y<0) y -= cnt;
            else y += cnt;
        }
        return abs(x) + abs(y);;
    }
};