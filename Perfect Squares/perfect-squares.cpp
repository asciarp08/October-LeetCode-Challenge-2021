/**
Time - O(n^(3/2))
Space - O(n)
**/

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> cnt(n+1, INT_MAX);
        cnt[0] = 0;
        
        for(int sum = 1; sum<=n; sum++){
            int minCount = INT_MAX;
            for(int num = 1; num*num<=sum; num++){
                minCount = min(minCount, cnt[sum-num*num]+1);
            }
            cnt[sum] = minCount;
        }
        return cnt[n];
    }
};
