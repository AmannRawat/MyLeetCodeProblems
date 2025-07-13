//Best Approach 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), mid = 0, low = 0, high = n - 1, mini = INT_MAX;
        while (low <= high) {
            mid = (high + low) / 2;
            if (nums[low] <= nums[mid]) {
                mini=min(mini,nums[low]);
                low=mid+1;
            }else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};
//My approach Not passing all test case
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), mid = 0, low = 0, high = n - 1, mini = INT_MAX;
        while (low <= high) {
            mid = (high + low) / 2;
            // mini=min(mini,nums[mid]);
            if (low == high)
                return nums[mid];
            if (nums[low] <= nums[high]) {
                if (mid == high)
                    high = mid - 1;
                else
                    high = mid;
            } else {
                if (mid == low)
                    low = mid + 1;
                else
                    low = mid;
            }
        }
        return nums[mid];
    }
};