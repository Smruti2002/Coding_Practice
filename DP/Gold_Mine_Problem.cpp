// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1/

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n][m];
        int res = 0; 
        for(int j = 0; j<m; j++)
        {
            for(int i = 0; i<n; i++)
            {
                if(j==0)
                    dp[i][j] = M[i][j];
                else if(n==1)
                    dp[i][j] = M[i][j] + dp[i][j-1];
                else if(i==0)
                {
                    dp[i][j] = M[i][j] + max(dp[i][j-1],dp[i+1][j-1]);
                }
                else if(i==n-1)
                {
                    dp[i][j] = M[i][j] + max(dp[i][j-1],dp[i-1][j-1]);
                }
                else
                {
                    dp[i][j] = M[i][j] + max(dp[i+1][j-1],max(dp[i][j-1],dp[i-1][j-1]));
                }
                res = max(dp[i][j],res);
            }
        }
        return res;
    }
};
