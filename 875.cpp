//My approach (time limit Exceeded O(n2))
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int k = 1,maxi=-1;
        long long time = 0;
        for (int i = 0; i < n; i++){
            maxi=max(maxi,piles[i]);
        }
        while (k<=maxi) {
            time=0;
            for (int i = 0; i < n; i++) {
                time += ceil((double)piles[i] / k);
            }
            if (time<=h){
                return k;
            }
            k++;
        }
        return k;
    }
};

//Optimal Approach
class Solution {
public:
    long long totalTime(vector<int>& piles, int k) {
        int n = piles.size();
        long long time = 0;
        for (int i = 0; i < n; i++) {
            time += ceil((double)piles[i] / k);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        long long low = 1, high = maxi, mid, time;
        while (low <= high) {
            mid = (high + low) / 2;
            time = totalTime(piles, mid);
            if (time <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};