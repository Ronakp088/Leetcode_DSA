class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> bank;
        bank[5] = 0;
        bank[10] = 0;
        bank[20] = 0;
        for (int i = 0; i < bills.size(); i++) {
            bank[bills[i]]++;
            if (bills[i] == 10) {
                if (bank[5] == 0)
                    return false;
                else
                    bank[5]--;
            } else if (bills[i] == 20) {
                if (bank[5] > 0 && bank[10] > 0) {
                    bank[5]--;
                    bank[10]--;
                } else if (bank[10] == 0 && bank[5] >= 3) {
                    bank[5] -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};