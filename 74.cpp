//Brute force O(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns;
        for (int i = 0; i < rows; i++) {
            columns = matrix[i].size();
            {
                for (int j = 0; j < columns; j++) {
                    if (target == matrix[i][j])
                        return true;
                }
            }
        }
        return false;
    }
};

// Better Approach Using BS O(nlog m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns, low, high, mid;
        for (int i = 0; i < rows; i++) {
            columns = matrix[i].size();
            {
                low = 0;
                high = columns - 1;
                while (low <= high) {
                    mid = (high + low) / 2;
                    if (target == matrix[i][mid])
                        return true;
                    if (target > matrix[i][mid])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
        return false;
    }
};

//Optmial Approach using Flatten BS O(log n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), low, high, mid, row,
            column;
        low = 0;
        high = (m * n) - 1;
        while (low <= high) {
            mid = (high + low) / 2;
            row = mid / m;
            column = mid % m;
            if (target == matrix[row][column])
                return true;
            if (target > matrix[row][column])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};