//Brute force TC: O(n2)
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int J = i; J < nums.size(); J++) {
                sum += nums[J];
                if (sum == goal) {
                    count++;
                }
            }
        }
        return count;
    }
//Better Approach  TC: O(N) SC:O(N)
 int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), count = 0, sum = 0;
        int rem; // remaining Sum
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int r = 0;
        while (r < n) {
            sum += nums[r];
            rem = sum - goal;
            count += mpp[rem]; //Unordered Map returns 0 automatically if there is no key rem
            mpp[sum]++;
            r++;
        }
        return count;
    }

//Optimal Appraoch Sliding Window TC: O(2N)
  int atMostGoal(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size(), count = 0, sum = 0;
        int l = 0, r = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostGoal(nums, goal) - atMostGoal(nums, goal - 1);
    }