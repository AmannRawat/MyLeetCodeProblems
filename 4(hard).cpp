//Brute Force Approach O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;
        vector<int> num;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                num.push_back(nums1[i++]);
            } else
                num.push_back(nums2[j++]);
        }
        while (i < n) {
            num.push_back(nums1[i++]);
        }
        while (j < m) {
            num.push_back(nums2[j++]);
        }
        int newsize = num.size();
        double median = 0;
        if (newsize % 2 == 0) {
            int mid = newsize / 2;
            median = (num[mid - 1] + num[mid]) / 2.0;
        } else
            median = num[newsize / 2];
        return median;
    }
};

//Optimal Approach BS O(log n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n;
        int left = (n + m + 1) / 2;
        int N = n + m;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n)
                r1 = nums1[mid1];
            if (mid2 < m)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if (N % 2 == 1)
                    return max(l1, l2);
                else
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};