// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[W+1][n];
       for(int i = 0; i<n; i++)
        dp[0][i] = 0;
        
        for(int i = 1; i<=W; i++)
        {
            if(wt[0]<=i)
                dp[i][0] = val[0];
            else
                dp[i][0] = 0;
                
            for(int j = 1; j<n; j++)
            {
                if(wt[j]<=i)
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-wt[j]][j-1]+val[j]);
                }
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[W][n-1];
    }
};
