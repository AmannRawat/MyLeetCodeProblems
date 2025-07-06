// Brute Force O(n2) or O(nlog n) if we use merge or quick sort
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        bool swapped;

        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
};

// Optimal approach O(n) DUTCH NATIONAL FLAG ALGORITHM
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0, mid = 0,high = arr.size() - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else if (arr[mid] == 2) {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};