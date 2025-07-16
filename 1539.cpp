//My approach Brute Force o(n2)
class Solution {
public:
    bool notExist(vector<int>& arr, int num) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (num == arr[i]) {
                return false;
            }
        }
            return true;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        long long high = 100000000000, index = 1;
        for (int i = 1; i <= high; i++) {
            if (notExist(arr, i)) {
                if (index == k)
                    return i;
                else {
                    index++;
                }
            }
        }
        return -1;
    }
};

//Better Optimal Approach O(n)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] > k)
                 break;
            else
                k++;
        }
        return k;
    }
};

// Best optimal Approach o(log n) using BS

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        int mid, missing;
        while (low <= high) {
            mid = (high + low) / 2;
            missing= arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return (high + 1 + k); //  OR return (low+k);
    }
};
