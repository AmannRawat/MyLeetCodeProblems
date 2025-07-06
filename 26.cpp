
class Solution {
public:
    bool alreadyExist(vector<int> n, int val) {
        for (int i = 0; i < n.size(); i++) {
            if (val == n[i]) {
                return false;
            }
        }
        return true;
    }
    int removeDuplicates(vector<int>& nums) {
        vector<int> newnum;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (alreadyExist(newnum, nums[i])) {
                newnum.push_back(nums[i]);
                k++;
            }
            for (int i = 0; i < k; i++) {
                nums[i] = newnum[i];
            }
        }
        return k;
    }
};