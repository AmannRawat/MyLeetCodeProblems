//My approach Greedy Approach works with Some testcases but failed for some testcases
 int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0, right = n - 1, score = 0;
        int i = 0;
        while (i < k) {
            if (cardPoints[left] > cardPoints[right]) {
                score += cardPoints[left];
                left++;
            } else if (cardPoints[left] == cardPoints[right]) {
                if (cardPoints[left + 1] >= cardPoints[right - 1]) {
                    score += cardPoints[left];
                    left++;
                } else {
                    score += cardPoints[right];
                    right--;
                }
            } else {
                score += cardPoints[right];
                right--;
            }
            i++;
        }
        return score;
    }
    
//Optimal Approach TC:O(N)
 int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = k - 1, right = n - 1, score = 0, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        score = max(score, sum);
        while (left >= 0) {
            sum -= cardPoints[left];
            left--;
            sum += cardPoints[right];
            right--;
            score = max(score, sum);
        }
        return score;
    }