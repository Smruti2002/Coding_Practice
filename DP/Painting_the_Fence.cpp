// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

class Solution{
    public:
    long long countWays(int n, int k){
        long long mod = 1e9+7;
        long long dp[n+1];
        dp[1] = k;
        dp[2] = k*k;
        long long eq[n+1],uneq[n+1];
        eq[2] = k;
        uneq[2] = k*(k-1);
        for(int i = 3; i<=n; i++)
        {
            eq[i] = uneq[i-1]%mod;
            uneq[i] = (eq[i-1]*(k-1))%mod + (uneq[i-1]*(k-1))%mod;
            uneq[i] = uneq[i]%mod;
            dp[i] = (eq[i]+uneq[i])%mod;
        }
        return dp[n];
    }
};
