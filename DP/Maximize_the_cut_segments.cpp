
//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        dp[0] = 0;
        int inf = -1e5;
        for(int i = 1; i<=n; i++)
        {
            // there might be some ways which may not lead to a valid cut
            // for example, length of 3 cut by segments of 2. It is not possible
            // but in our logic if we set dp[i] = 0, then it will add 1 to the dp and give wrong ans
            // therefore the dp is initialised with -infinity
            
            dp[i] = inf;
            if(i>=x)
                dp[i] = max(dp[i],1+dp[i-x]);
            if(i>=y)
                dp[i] = max(dp[i],1+dp[i-y]);
            if(i>=z)
                dp[i] = max(dp[i],1+dp[i-z]);
        }
        if(dp[n]<0)
            return 0;
        return dp[n];
    }
};
