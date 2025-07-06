// Brute force approach O(n2)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 1;
        int consec=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count=1;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == 1)
                        count++;
                    else
                        break;
                }
                if(count>consec)
                     consec=count;
            }
        }
        return consec;
    }
};

//Best approach
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int consec=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                consec=max(consec,count);
            }else{
                count=0;
            }
        }
        return consec;
    }
};