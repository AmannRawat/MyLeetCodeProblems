//Hard question
//Brute Force O(3n) O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);

        // Left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }

        // Right pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        }

        // Sum up
        int candies = 0;
        for (int i = 0; i < n; i++)
            candies += max(left[i], right[i]);

        return candies;
    }
};

//Optimal Approach O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1,i=1,n=ratings.size(),peak,down;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
    }
};
