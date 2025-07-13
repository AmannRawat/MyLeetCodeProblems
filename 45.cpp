//JUMP GAME 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, left= 0, right = 0;
        int n = nums.size();
        while(right<n-1){
            int farthest=0;
            for(int i=left;i<=right;i++){
                farthest=max(farthest,nums[i]+i);
            }
            jump++;
            left=right+1;
            right=farthest;
        }
        return jump;
    }
};

//Second approach
int jumps = 0, farthest = 0, end = -1;
for (int i = 0; i < nums.size(); i++) {
    farthest = max(farthest, i + nums[i]);
    if (i == end) {
        jumps++;
        end = farthest;
    }
}
