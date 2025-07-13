//Brute Force Approach O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,n=nums.size();
        if(n==1) return 0;
        for(i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return i;
        }
        return i;
    }
};

//Best Approach O(logn)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) // Edgecase
            return 0;
        if (nums[0] > nums[1]) // Edgecase
            return 0;
        if (nums[n - 1] > nums[n - 2]) // Edgecase
            return n - 1;
        int low = 1, high = n - 2, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) {
                high = mid - 1;
            } else
                low = mid + 1; // Edge case when i is at reverse peak
        }
        return -1;
    }
};