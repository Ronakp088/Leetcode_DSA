class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int n = left; n <= right; n++) {
            int num = n;
            bool valid = true;
            while (num > 0) {
                int digit = num % 10;
                if (digit == 0 || n % digit != 0) {
                    valid = false;
                    break;
                }
                num /= 10;
            }
            if (valid) {
                result.push_back(n);
            }
        }
        return result;
    }
};