class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int a = 0, b = 0;
        int rooms = 0, ans = 0;
        int n = start.size();

        while (a < n) {
            if (start[a] < end[b]) {
                rooms++;
                a++;
            } else {
                rooms--;
                b++;
            }
            ans = max(ans, rooms);
        }
        return ans;
    }
};
