//My approach Brute Force O(nlog n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int lb=lower_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            int ub=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(lb==(ub-1))return nums[i];
        }
        return -1;
    }
};

//Better Solution O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        for(int i=0;i<n;i=i+2){
            if(nums[i]!=nums[i+1]) return nums[i];
        }
        return -1;
    }
};

//Best Solution using binary search O(logn)
class Solution {
public:
    int evenOdd(int num) {
        if (num % 2 == 0)
            return 1;
        else
            return 0;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        int low = 1, high = n - 2, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if (nums[mid] == nums[mid + 1] && evenOdd(mid) ||
                nums[mid - 1] == nums[mid] && !(evenOdd(mid))) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};