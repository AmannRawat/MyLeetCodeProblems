//Better Approach TC: O(N + N)
int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, len, countZero = 0, maxLen = 0;
        while (r < nums.size()) {
            if (nums[r] == 0)
                countZero++;
            if (countZero <= k) {
                len = (r - l) + 1;
                maxLen = max(maxLen, len);
            } else {
                while (countZero > k) {
                    if (nums[l] == 0)
                        countZero--;
                    l++;
                }
            }
            r++;
        }
        return maxLen;
    }
//Best Appraoch TC: O(N)    
int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, len, countZero = 0, maxLen = 0;
        while (r < nums.size()) {
            if (nums[r] == 0)
                countZero++;
            if (countZero > k) {
                if (nums[l] == 0)
                    countZero--;
                l++;
            }
            if (countZero <= k) {
                len = (r - l) + 1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }