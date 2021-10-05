/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int climbStairs(int n) {
        
        int ways1Prev = 1;
        int ways2Prev = 1;
        
        //dp[0] = dp[1] = 1
        
        for(int i = 2; i<=n; i++){
            int waysCur = ways1Prev + ways2Prev; //dp[2]
            ways2Prev = ways1Prev;
            ways1Prev = waysCur;
        }
        return ways1Prev;
    }
};
