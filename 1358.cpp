// Appraoch 
 int numberOfSubstrings(string s) {
        unordered_map<char, int> freqmap;
        long long n = s.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        while (r < n) {
            freqmap[s[r]]++;
            while (freqmap.size() == 3) {
                freqmap[s[l]]--;
                if (freqmap[s[l]] == 0) {
                    freqmap.erase(s[l]);
                }
                l++;
            }
            cnt += (r - l + 1); // substrings that DON'T have all 3 chars
            r++;
        }
        return ((n * (n + 1)) / 2) - cnt;
    }

//Another Approach
 int mini(int a, int b, int c) {
        if (a < b && a < c)
            return a;
        if (b < a && b < c)
            return b;
        return c;
    }
    int numberOfSubstrings(string s) {
        unordered_map<char, int> lastSeen;
        lastSeen['a'] = -1;
        lastSeen['b'] = -1;
        lastSeen['c'] = -1;
        long long n = s.size();
        int r = 0;
        int count = 0;
        while (r < n) {
            lastSeen[s[r]] = r;
            if (lastSeen['a'] != -1 && lastSeen['b'] != -1 && lastSeen['c'] != -1) {
                    count += (1+ mini(lastSeen['a'],lastSeen['b'],lastSeen['c']));
            }
            r++;
        }
        return count;
    }