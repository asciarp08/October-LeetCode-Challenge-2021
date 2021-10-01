/**
Time = O(m*n)
Space = O(2*m), m = min(text1.size(), text2.size())
**/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if(m>n)swap(text1, text2);
        if(m>n)swap(m,n);
        
        vector<vector<int>> dp(2,vector<int>(m+1,0));
        
        for(int  i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i%2][j] = 1+dp[(i-1)%2][j-1];
                }
                else{
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                }
            }
        }
        return dp[n%2][m];
    }
};
