// Better appraoch O(n log m)
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

//Optimal appproach O(n+m)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), row=0, column=m-1;
        while (row < n && column >=0) {
            if (target == matrix[row][column])
                return true;
            else if (target > matrix[row][column])
                row++;
            else
                column--;
        }
        return false;
    }
};