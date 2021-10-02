/**
Time = O(m*n)
Space = O(2*n)
**/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(2, vector<int>(n, INT_MIN));
        
        dp[(m-1)%2][n-1] = dungeon[m-1][n-1]>0?0:dungeon[m-1][n-1];
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                
                if(j==n-1 && i==m-1)continue;
                
                if(i+1<m && j+1>=n){
                    dp[i%2][j] = dp[(i+1)%2][j];
                }
                else if(i+1>=m && j+1<n){
                    dp[i%2][j] = dp[i%2][j+1];
                }
                else{
                    dp[i%2][j] = max(dp[(i+1)%2][j],dp[i%2][j+1]);
                }
                
                dp[i%2][j] = min(dp[i%2][j]+dungeon[i][j], 0);
                
            }
        }
        return abs(dp[0][0])+1;
    }
};
