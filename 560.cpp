//Brute Force O(n2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                    // break; NO BREAK---Break can miss 0
                }
            }
        }
        return count;
    }
};

//Optimal Solution (Using Prefix Sum and Hash Map) On average TC: O(N)
  int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        int rem; // remaining Sum
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int r = 0;
        while (r < n) {
            sum += nums[r];
            rem = sum - k;
            count += mpp[rem];
            mpp[sum]++;
            r++;
        }
        return count;
    }