class Solution {
public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalBalance = 0;
        int currentBalance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            int gain = gas[i] - cost[i];
            totalBalance += gain;
            currentBalance += gain;

            // If we fail here, start cannot be valid
            if (currentBalance < 0) {
                start = i + 1;
                currentBalance = 0;
            }
        }

        return (totalBalance >= 0) ? start : -1;
    }
};
