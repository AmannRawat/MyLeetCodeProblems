//Optimal Approach
class Solution {
public:
    bool possible(vector<int>& nums, int k, int currMaxSum, int n) {
        int subArray = 1, subSum = 0;
        for (int i = 0; i < n; i++) {
            if (subSum + nums[i] <= currMaxSum) {
                subSum = subSum + nums[i];
            } else{
                subSum = nums[i];
                subArray++;
            }     
        }
        return (subArray <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            sum = sum + nums[i];
        }
        long long low = maxi, high = sum, mid;
        while (low <= high) {
            mid = (high + low) / 2;
            if (possible(nums, k, mid, n))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};