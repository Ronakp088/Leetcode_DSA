class Solution {
public:
    int bsidx(int val, vector<int>& arr) {
        int l = 0;
        int h = arr.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] == val) return mid;
            else if (arr[mid] > val) h = mid;
            else l = mid + 1;
        }

        return l;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();

        sort(arr2.begin(), arr2.end());

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int val = arr1[i];

            int j = bsidx(val, arr2);

            bool valid = true;

            if (abs(val - arr2[j]) <= d)
                valid = false;

            if (j > 0 && abs(val - arr2[j - 1]) <= d)
                valid = false;

            if (j < m - 1 && abs(val - arr2[j + 1]) <= d)
                valid = false;

            if (valid) cnt++;
        }

        return cnt;
    }
};