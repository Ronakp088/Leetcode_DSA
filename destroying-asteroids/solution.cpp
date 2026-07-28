class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long  temp = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i = 0;i<asteroids.size();i++){
            if(asteroids[i] > temp) return false;
            else temp += asteroids[i];
        }
        return true;
    }
};