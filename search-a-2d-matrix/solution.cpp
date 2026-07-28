class Solution {
public:
    int search(vector<vector<int>>& matrix, int i, int m, int target) {
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = (high + low) >> 1;
            if (matrix[i][mid] == target)
                return 1;
            else if (matrix[i][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (target > matrix[i][m - 1])
                continue;
            else {
                if (search(matrix, i, m, target) == 1)
                    return true;
            }
        }
        return false;
    }
};