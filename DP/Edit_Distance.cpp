// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

class Solution {
  public:
  
  
    int editDistance(string s, string t) {
        
        int m = s.length();
        int n = t.length();
        
        // dp(i,k) to store min number of moves required to make s equal to t when s has length i and 
        // t has length k
        int dp[m+1][n+1];
        
        for(int i = 0; i<=m; i++)
        {
            for(int j = 0; j<=n; j++)
            {
                // if s is empty , we have to add all elements of t into it
                if(i==0)
                {
                    dp[i][j] = j;
                }
                else if(j==0) 
                {
                    // if t is empty remove all elements of s
                    dp[i][j] = i;
                }
                else if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i][j-1],min( dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
        
    }
};
