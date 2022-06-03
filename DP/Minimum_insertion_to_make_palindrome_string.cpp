
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    
    int minInsertions(string s) {
        
        int dp[501][501];
        string t = string(s.rbegin(),s.rend());
        
        // code for longest common palindromic sub-sequence
        for(int i = 0; i<s.length(); i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i = 1; i<=s.length(); i++)
        {
            for(int j = 1; j<=s.length(); j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return s.length()-dp[s.length()][s.length()];
    }
};
