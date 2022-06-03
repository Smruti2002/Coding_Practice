// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    
    int dp[1001][1001][2];
    int inf = INT_MIN,n;
    vector<int> p;
    
    
    /* 
        dp(i,k,bit)-> max profit after buying or selling or leaving ith day. 
        bit=0, selling the stock or leaving it, bit=1-> buying the stock or 
        leaving it.
    */
    
    int recur(int i, int k, int bit)
    {
        if(i>=n || k<=0)
        {
            return 0;
        }
        if(dp[i][k][bit]==-1)
        {
            if(bit)
            {
                dp[i][k][bit] = max(-p[i]+recur(i+1,k,0),recur(i+1,k,1));
            }
            else
            {
                dp[i][k][bit] = max(p[i]+recur(i+1,k-1,1),recur(i+1,k,0));
            }
        }
        return dp[i][k][bit];
    }
    
    int maxProfit(int k, vector<int>& prices) {
     
        p = prices;
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        
        return recur(0,k,1);
    }
};
