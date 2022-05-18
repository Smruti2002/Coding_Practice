// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
public:

    int equalPartition(int N, int arr[])
    {
        
        int n = N;
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += arr[i];
        if(sum%2==0)
        {
            int dp[sum/2 + 1][n+1];
            memset(dp,-1,sizeof(dp));
            
            for(int i = 0; i<=sum/2; i++)
            {
                for(int j = 0; j<=n; j++)
                {
                    if(i==0)
                        dp[i][j] = 1;
                    else if(j==0)
                        dp[i][j] = 0;
                    else
                    {
                        dp[i][j] = dp[i][j-1];
                        if(arr[j-1]<=i)
                            dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
                    }
                }
            }
            return dp[sum/2][n];
           
        }
        else
        {
            return 0;
        }
    }
};
