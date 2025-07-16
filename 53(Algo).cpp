//Brute force approach o(n2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

//Better Approach Kadane's Algorithm O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (sum < 0)                 //Kadane's Algorithm
                sum = 0;
            sum += nums[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};